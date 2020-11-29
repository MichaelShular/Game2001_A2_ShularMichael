#pragma once
#include <cassert>

template <class T> class LinkIterator;
template <class T> class LinkedList;

template <class T>
class LinkNode {
public:
	friend class LinkIterator<T>;
	friend class LinkedList<T>;
private:
	T m_data;
	LinkNode* m_next;
	LinkNode* m_previous;
};

template <class T>
class LinkIterator {
public:
	LinkIterator() {
		m_node = NULL;
	}
	~LinkIterator() {}
	
	void operator=(LinkNode<T>* node){
		m_node = node;
	}
	T& operator*(){
		assert(m_node != NULL);
		return m_node->m_data;
	}
	void operator++() {
		assert(m_node != NULL);
		m_node = m_node->m_next;
	}
	void operator++(int) {
		assert(m_node != NULL);
		m_node = m_node->m_next;
	}
	void operator--() {
		assert(m_node != NULL);
		m_node = m_node->m_previous;
	}
	void operator--(int) {
		assert(m_node != NULL);
		m_node = m_node->m_previous;
	}
	bool operator !=(LinkNode<T>* node) {
		return (m_node != node);
	}
	bool operator ==(LinkNode<T>* node) {
		return (m_node == node);
	}
	 
private:
	LinkNode<T>* m_node;
};

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

	void Push_Front(T newData) {
		LinkNode<T>* node = new LinkNode<T>;

		assert(node != NULL);
		node->m_data = newData;
		node->m_next - NULL;
		node->m_previous = NULL;

		if (m_root != NULL) {
			node->m_next = m_root;
			m_root->m_previous = node;
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

		m_root = m_root->m_next;
		
		if (m_root != NULL) {
			m_root->m_previous = NULL;
		}
		else {
			m_lastNode = NULL;
		}

		delete temp;
		temp = NULL;

		m_size = (m_size == 0 ? m_size : m_size - 1);
	}
	void Push(T newData) {
		
		LinkNode<T>* node = new LinkNode<T>;
		
		assert(node != NULL);
		node->m_data = newData;
		node->m_next = NULL;
		node->m_previous = NULL;
		
		if (m_lastNode != NULL){
			m_lastNode->m_next = node;
			node->m_previous = m_lastNode;
		}
		else {
			m_root = node;
		}

		m_lastNode = node;
		m_size++;
	}
	void Pop(){
		assert(m_root != NULL);
		
		if (m_root->m_next == NULL) {
			delete m_root;
			m_root = NULL;
			m_lastNode = NULL;
		}
		else {
			LinkNode<T>* prevNode = m_lastNode->m_previous;

			prevNode->m_next = NULL;
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