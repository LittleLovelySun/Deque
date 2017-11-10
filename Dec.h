#ifndef DEC_H
#define DEC_H

#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
	Node<T> *next;
	Node<T> *prev;
	T value;

	Node(const T &value, Node *next = NULL, Node *prev = NULL);
	Node(const Node &a);
};

template <typename T>
class Deque {
public:
	Node<T> *end;
	Node<T> *front;

	Deque();

	void pushFront(const T &value);
	void pushEnd(const T &value);
	void popFront();
	void popEnd();

	void printFront();
	void printEnd();

	~Deque();
};

template <typename T>
Node<T>::Node(const T &value, Node *next, Node *prev) {
	this->prev = prev;
	this->next = next;
	this->value = value;
}

template <typename T>
Node<T>::Node(const Node &a) {
	prev = a->prev;
	next = a->next;
	value = a->value;
}

template <typename T>
Deque<T>::Deque() {
	end = NULL;
	front = NULL;
}

template <typename T>
void Deque<T>::pushFront(const T &value) {
	if (!front) {
		Node<T> *tmp = new Node<T>(value);
		end = tmp;
		front = tmp;	
	}
	else {
		Node<T> *tmp = new Node<T>(value, front, NULL);
		front->prev = tmp;
		front = tmp;
	}
}

template <typename T>
void Deque<T>::pushEnd(const T &value) {
	if (!end) {
		Node<T> *tmp = new Node<T>(value);
		end = tmp;
		front = tmp;
	}
	else {
		Node<T> *tmp = new Node<T>(value, NULL, end);
		end->next = tmp;
		end = tmp;
	}
}

template <typename T>
void Deque<T>::printFront() {
	if (!front) {
		cout << "Deque is empty";
		return;
	}

	Node<T> *now = front;

	while (now) {
		cout << now->value << " " ;
		now = now->next;
	}
	cout << endl;
}

template <typename T>
void Deque<T>::printEnd() {
	if (!end) {
		cout << "Deque is empty";
		return;
	}

	Node<T> * now = end;

	while (now) {
		cout << now->value << " ";
		now = now->prev;
	}
	cout << endl;
}

template <typename T>
void Deque<T>::popFront() {
	if (!front) {
		cout << "Deque is empty" << endl;
		return;
	}
	Node<T> *tmp = front;
	front = front->next;
	front->prev = NULL;
	delete tmp;
}

template <typename T>
void Deque<T>::popEnd() {
	if (!end) {
		cout << "Deque is empty" << endl;
		return;
	}
	Node<T> *tmp = end;
	end = end->prev;
	end->next = NULL;
	delete tmp;
}

template <typename T>
Deque<T>::~Deque() {
	while(front){
		Node<T> *tmp = front;
		front = front->next;
		delete tmp;
	}

	end = NULL;
}


/*
class WordDeq: public Deque<std::string> {
	//WordDeq();
	void SortDeq();
	//~WordDeq();
};

void swap(Node<std::string> a, Node<std::string> b);
*/
#endif