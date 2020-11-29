#pragma once
#include <cassert>


template <class T>
class LinkNode {
public:

	void setNextNode(LinkNode* a)
	{
		m_next = a;
	}
	void setPreviousNode(LinkNode* a)
	{
		m_previous = a;
	}
	void setData(T a)
	{
		m_data = a;
	}

	LinkNode* getNextNode(){ return m_next; }
	LinkNode* getPreviousNode() { return m_previous; }
	T getData() { return m_data; }

private:
	T m_data;
	int m_priority; 
	LinkNode* m_next;
	LinkNode* m_previous;
};