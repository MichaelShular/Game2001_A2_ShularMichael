#include <iostream>
#include "DoublyLinkedList.h"

int main() {

	std::cout << "running" << std::endl;
	std::cout << "Double-Ended Linked List Example" << std::endl << std::endl;
	LinkedList<int> lList;
	lList.Push(101);
	lList.Push_Front(102);
	lList.Pop();
	lList.Push(201);
	lList.Push_Front(301);
	lList.Push(801);
	lList.Push(401);
	lList.Push(1);
	lList.Pop_Front();
	lList.Push(701);
	LinkIterator<int> it;
	for (it = lList.Begin(); it != lList.End(); it++)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl << std::endl;
	return 0;
}