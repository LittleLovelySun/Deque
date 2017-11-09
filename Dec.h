#ifndef DEC_H
#define DEC_H

#include <iostream>

template <typename T>
class Node {
public:
	Node<T> *prev;
	Node<T> *next;
	T value;

	Node(T value);
	Node(Node *prev, Node *next, T value);
	Node(const Node &a);
	~Node();
};

template <typename T>
class Deque {
public:
	Node<T> *front;
	Node<T> *end;

	Deque();

	void pushFront(const T &value);
	void pushEnd(const T &value);
	void popFront();
	void popEnd();

	void printFront();
	void printEnd();

	~Deque();
};
/*
class WordDeq: public Deque<std::string> {
	//WordDeq();
	void SortDeq();
	//~WordDeq();
};

void swap(Node<std::string> a, Node<std::string> b);
*/
#endif