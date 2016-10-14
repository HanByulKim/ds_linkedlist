#pragma once
template<typename T>
class ListItem {
public:
	template<typename T> friend class List;
	template<typename T> friend class ListIterator;

	ListItem():prev('\0'), next('\0'){}
	ListItem(T data):prev('\0'), next('\0'), n(data){}
	T n;
	ListItem<T>* prev;
	ListItem<T>* next;
};

