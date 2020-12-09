#pragma once
#include <cassert>
#include "DoublyLinkedList.h"
#include "LinkNode.h"
#include "LinkIterator.h"
//Got rid of CMP since the Assignment is only comparing priority values for position and data doesnt effect its position in the doubly link list
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
			m_elements.Push(val, pri); 
		}
		else{
			LinkIterator<T> it;
			it = m_elements.Begin();

			while (it != m_elements.End())
			{
				if (it == m_elements.Last() && pri > it.getNode()->getProiority())
				{
					m_elements.Insert_After(it, val, pri);
					break;
				}
				if (pri > it.getNode()->getProiority()){
					it++;
				}
				if (pri < it.getNode()->getProiority()){
					m_elements.Insert_Before(it, val, pri);
					break;
				}
				if (pri == it.getNode()->getProiority())
				{
					while ( it != m_elements.Last() && pri == it.getNode()->getNextNode()->getProiority())
					{
						it++;
					}
					m_elements.Insert_After(it, val, pri);
					break;
				}
				
			}
		}
	}
	void pop()
	{
		m_elements.Pop_Front();
	}
	LinkNode<T>  front(){
	/*	LinkIterator<T> it;
		it = ;*/
		return *m_elements.Begin();
	}
	T& back() {
		LinkIterator<T> it;
		it = m_elements.Last();

		return *it;
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
		m_size = size;
	}
private:
	LinkedList<T> m_elements; 
	int m_size;
};

