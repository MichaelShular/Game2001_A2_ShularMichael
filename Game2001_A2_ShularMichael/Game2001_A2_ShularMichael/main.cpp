#include <iostream>
#include "DoublyLinkedList.h"
#include "LinkIterator.h"
#include "LinkNode.h"
#include "PriorityQueue.h"

int main() {

	std::cout << "running" << std::endl;
	std::cout << "Int test" << std::endl << std::endl;
	//test 1 start 
	PriorityQueue<int> test1(8);

	test1.push(153, 3); 
	test1.push(451, 6);
	test1.push(4, 1);
	test1.push(12, 2);
	test1.push(5, 4);
	test1.push(4, 2);
	test1.push(245, 1);
	test1.push(74, 6);

	std::cout << "Max Size of test 1: " << test1.getMaxSize() << std::endl;
	int count = 1;
	while (!test1.isEmpty()) {
		std::cout << "Data " << count << ": " << test1.front().getData() << std::endl;
		test1.pop();
		count++;
	}
	std::cout << std::endl << std::endl;
	
	//Test two start
	
	std::cout << "Object test" << std::endl << std::endl;
	class Test {
	public:
		Test() : m_data("NO DATA") {}
		Test(std::string d): m_data(d) {}
		std::string getTestData() {
			return m_data;
		}
		~Test() {}

	private:
		std::string m_data;
	};
	PriorityQueue<Test> test2(5);

	test2.push(Test("HI"), 4);
	test2.push(Test("John"), 2);
	test2.push(Test("Bye"), 3);
	test2.push(Test("Wow"), 3);
	test2.push(Test("Day"), 3);
	
	std::cout << "Max Size of test 2: " << test2.getMaxSize() << std::endl;
	int count2 = 1;
	while (!test2.isEmpty()) {
		std::cout <<  "Data " << count2 << ": " << test2.front().getData().getTestData() << std::endl;
		test2.pop();
		count2++;
	}
	std::cout << std::endl << std::endl;
	
	//test 3 start

	std::cout << "test 3" << std::endl << std::endl;
	PriorityQueue<int> test3(10);

	test3.push(34, 2);
	test3.push(41, 6);
	test3.push(1, 5);
	test3.push(2, 5);
	test3.push(3, 5);
	test3.push(4, 5);
	test3.push(5, 5);
	test3.push(6, 5);

	std::cout << "Max Size of test 3: " << test3.getMaxSize() << std::endl;
	int count3 = 1;
	while (!test3.isEmpty()) {
		std::cout << "Data " << count3 << ": " << test3.front().getData() << std::endl;
		test3.pop();
		count3++;
	}

	return 0;
}