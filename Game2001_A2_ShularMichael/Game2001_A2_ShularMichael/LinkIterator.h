#pragma once
#include <cassert>
#include "LinkNode.h"


template <class T>
class LinkIterator {
public:
	LinkIterator() {
		m_node = NULL;
	}
	~LinkIterator() {}

	void operator=(LinkNode<T>* node) {
		m_node = node;
	}
	T operator*() {
		assert(m_node != NULL);
		return m_node->getData();
	}
	void operator++() {
		assert(m_node != NULL);
		m_node = m_node->getNextNode();
	}
	void operator++(int) {
		assert(m_node != NULL);
		m_node = m_node->getNextNode();
	}
	void operator--() {
		assert(m_node != NULL);
		m_node = m_node->getPreviousNode();
	}
	void operator--(int) {
		assert(m_node != NULL);
		m_node = m_node->getPreviousNode();
	}
	bool operator !=(LinkNode<T>* node) {
		return (m_node != node);
	}
	bool operator ==(LinkNode<T>* node) {
		return (m_node == node);
	}
	bool isValid() {
		return (m_node != NULL);
	}

private:
	LinkNode<T>* m_node;
};