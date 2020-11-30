#pragma once
#include <cassert>
#include "LinkNode.h"
#include "LinkIterator.h"
template <class T >
class LinkedList
{
public:
	LinkedList() : m_size(0), m_root(0), m_lastNode(0) {}
	~LinkedList() {
		while (m_root) {
			Pop();
		}
	}

	LinkNode<T>* Begin() {
		assert(m_root != NULL);
		return m_root;
	}

	LinkNode<T>* End() {
		return NULL;
	}
	LinkNode<T>* Last() {
		return m_lastNode;
	}

	void Insert_Before(LinkIterator<T>& it, T newData, int pri)
	{
		assert(it.m_node != NULL);

		LinkNode<T>* node = new LinkNode<T>;
		assert(node != NULL);

		node->setData(newData);
		node->setProiority(pri);
		node->setNextNode(it.m_node);
		node->setPreviousNode(it.m_node->getPreviousNode());

		if (node->getPreviousNode() != NULL)
		{
			node->getPreviousNode()->setNextNode(node);
		}

		it.m_node->setPreviousNode(node);
		if (it.m_node == m_root)
		{
			m_root = node;
		}
		
		m_size++;
	}

	void Insert_After(LinkIterator<T>& it, T newData, int pri)
	{
		assert(it.m_node != NULL);

		LinkNode<T>* node = new LinkNode<T>;
		assert(node != NULL);

		node->setData(newData);
		node->setProiority(pri);
		node->setNextNode(it.m_node->getNextNode());
		node->setPreviousNode(it.m_node);

		if (node->getNextNode() != NULL)
		{
			node->getNextNode()->setPreviousNode(node);
		}

		it.m_node->setNextNode(node);
		if (it.m_node == m_lastNode)
		{
			m_lastNode = node;
		}

		m_size++;
	}


	void Push_Front(T newData ) {
		LinkNode<T>* node = new LinkNode<T>;

		assert(node != NULL);
		node->setData(newData);
		node->setNextNode(NULL);
		node->setPreviousNode(NULL);
		

		if (m_root != NULL) {
			node->setNextNode(m_root);
			m_root->setPreviousNode(node);
			m_root = node;	
		}
		else {
			m_root = node;
			m_lastNode = node;
		}
		m_size++;
	}
	void Pop_Front() {
		assert(m_root != NULL);
		
		LinkNode<T>* temp = m_root;

		m_root = m_root->getNextNode();
		
		if (m_root != NULL) {
			m_root->setPreviousNode(NULL);
		}
		else {
			m_lastNode = NULL;
		}

		delete temp;
		temp = NULL;

		m_size = (m_size == 0 ? m_size : m_size - 1);
	}
	void Push(T newData, int priority) {
		
		LinkNode<T>* node = new LinkNode<T>;
		
		assert(node != NULL);
		node->setData(newData);
		node->setNextNode(NULL);
		node->setPreviousNode(NULL);
		node->setProiority(priority);

		if (m_lastNode != NULL){
			m_lastNode->setNextNode(node);
			node->setPreviousNode(m_lastNode);
		}
		else {
			m_root = node;
		}

		m_lastNode = node;
		m_size++;
	}
	void Pop(){
		assert(m_root != NULL);
		
		if (m_root->getNextNode() == NULL) {
			delete m_root;
			m_root = NULL;
			m_lastNode = NULL;
		}
		else {
			LinkNode<T>* prevNode = m_lastNode->getPreviousNode();

			prevNode->setNextNode(NULL);
			delete m_lastNode;
			m_lastNode = prevNode;
			prevNode = NULL;
			
		}
		m_size = (m_size == 0 ? m_size : m_size - 1);
	}
	int getSize() {
		return m_size;
	}
private:
	int m_size;
	LinkNode<T>* m_root;
	LinkNode<T>* m_lastNode;
};