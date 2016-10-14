#include "List.h"
void main() {
	List<int> a;
	a.add(5, 0);
	a.add(6, 1);
	a.add(999, 1);
	a.del(2);
	a.print();

	std::cout << std::endl;

	for (ListIterator<int> ptr = a.begin(); ptr != a.end(); ++ptr) {
		std::cout << *ptr << std::endl;
	}
	ListIterator<int> ptr = a.begin();
	std::cout << *ptr++ << std::endl;
	std::cout << *(--ptr) << std::endl;
	
	a.insert(++ptr, 11);
	std::cout << std::endl;
	a.print();

	std::cout << *ptr << std::endl;
	a.erase(ptr);
	std::cout << std::endl;
	a.print();
	system("pause");
}