#pragma once
#include "ListItem.h"
template<typename T>
class ListIterator {
public:
	template<typename T>friend class List;

	T& operator*() { // prefix unary
		if (current->next == '\0')
			throw std::out_of_range("");
		return current->n;
	}
	ListIterator<T>& operator++() { // prefix unary
		if (current->next == '\0')
			throw std::out_of_range("");
		current = current->next;
		return (*this);
	}
	ListIterator<T> operator++(int) { // postfix unary
		if (current->next == '\0')
			throw std::out_of_range("");
		ListIterator ret(*this);
		current = current->next;
		return ret;
	}

	ListIterator<T>& operator--() {
		if(current->prev == '\0')
			throw std::out_of_range("");
		current = current->prev;
		return (*this);
	}
	ListIterator<T> operator--(int) {
		if (current->prev == '\0')
			throw std::out_of_range("");
		ListIterator<T> ret(*this);
		current = current->prev;
		return ret;
	}
	bool operator!=(const ListIterator<T>& rhs) { return rhs.current != current; } // binary

private:
	ListIterator(ListItem<T>* ptr):current(ptr){}
	ListItem<T>* current;
};