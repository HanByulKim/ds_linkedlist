#pragma once
#include "ListItem.h"
#include "ListIterator.h"
#include <iostream>
template<typename T>
class List {
public:
	List() {
		head = new ListItem<T>();
		last = new ListItem<T>();
		head->next = last;
		last->prev = head;
	}
	ListIterator<T> begin() const{ return ListIterator<T>(head->next); }
	ListIterator<T> end() const{ return ListIterator<T>(last); }

	ListItem<T>* head;
	ListItem<T>* last;
	int size = 0;

	void add(T n, int i) {
		ListItem<T>* itr=head;
		for (int j = 0; j < i; j++) {
			itr = itr->next;
		}
		ListItem<T>* tail = itr->next;
		ListItem<T>* nNode = new ListItem<T>(n);
		nNode->prev = itr;
		nNode->next = tail;
		if(nNode->prev)
			nNode->prev->next = nNode;
		if(nNode->next)
			nNode->next->prev = nNode;
		size++;
	}
	ListIterator<T> insert(const ListIterator<T>& iter, const T& item) {
		ListItem<T>* newItem = new ListItem<T>(item);
		newItem->prev = iter.current->prev;
		newItem->next = iter.current;
		newItem->next->prev = newItem;
		if (newItem->prev != '\0')
			newItem->prev->next = newItem;
		size++;
		return ListIterator<T>(newItem);
	}
	ListIterator<T> erase(const ListIterator<T>& iter) {
		ListItem<T>* item = new ListItem<T>(iter.current->n);
		if (iter.current->prev != '\0')
			iter.current->prev->next = iter.current->next;
		if (iter.current->next != '\0')
			iter.current->next->prev = iter.current->prev;
		delete iter.current;
		size--;
		return ListIterator<T>(item);
	}
	void del(int i) {
		ListItem<T>* itr = head;
		for (int j = 0; j < i; j++) {
			itr = itr->next;
		}
		ListItem<T>* tail = itr->next;
		itr->next = tail->next;
		if(tail->next)
			tail->next->prev = itr;
		delete tail;
		size--;
	}
	void print() {
		for (ListItem<T>* itr = head->next; itr->next; itr=itr->next) {
			std::cout << itr->n << " " << std::endl;
		}
	}
};