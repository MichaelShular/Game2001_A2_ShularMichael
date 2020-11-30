#include <iostream>
#include "DoublyLinkedList.h"
#include "LinkIterator.h"
#include "LinkNode.h"

int main() {

	std::cout << "running" << std::endl;
	std::cout << "Double-Ended Linked List Example" << std::endl << std::endl;
	LinkedList<int> lList;
	lList.Push(101,1);
	lList.Push_Front(102);
	lList.Pop();
	lList.Push(201,1);
	lList.Push_Front(301);
	lList.Push(801,1);
	lList.Push(401,1);
	lList.Push(1,1);
	lList.Pop_Front();
	lList.Push(701,1);
	LinkIterator<int> it;
	for (it = lList.Begin(); it != lList.End(); it++)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl << std::endl;
	return 0;
}