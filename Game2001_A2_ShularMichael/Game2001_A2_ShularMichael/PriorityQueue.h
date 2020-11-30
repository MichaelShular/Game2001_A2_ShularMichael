#pragma once
#include "DoublyLinkedList.h"
#include "LinkNode.h"
#include "LinkIterator.h"

template<class T>

class PriorityQueue
{
public:
	PriorityQueue(int size) {
		assert(size > 0);
		m_size = size;
	}
	~PriorityQueue() {}

	void push(T val, int pri)
	{
		assert(m_elements.getSize() < m_size);

		if(m_elements.getSize() == 0){
			m_elements.Push(val, pri )
		}
		else{
			LinkIterator<T> it;
			it = m_elements.Begin();

			while (it != m_elements.End())
			{
				if (pri < it.m_node->getProiority()){
					it++
				}
				if (pri > it.m_node->getProiority()){
					m_elements.Insert_Before(it, val, pri);
				}
				if (pri == it.m_node->getProiority())
				{
					while (pri == it.m_node->getNextNode()->getProiority())
					{
						i++;
					}
					m_elements.Insert_After(it, val, pri);
				}
			}
		}
	}
	void pop()
	{
		m_elements.Pop_Front();
	}
	T& front(){
		LinkIterator<T> it;
		it = m_elements.Begin();

		return *it
	}
	T& back() {
		LinkIterator<T> it;
		it = m_elements.Last();

		return *it
	}
	int getSize() {
		return m_elements.getSize();
	}
	int getMaxSize() {
		return m_size;
	}
	bool isEmpty() {
		return (m_elements.getSize() == 0);
	}
	void Resize(int size){
		assert(size > 0);
		m_size = size
	}
private:
	LinkedList<T> m_elements; 
	int m_size;
};

