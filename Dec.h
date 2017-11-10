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

	void printFront(const string &msg = "");
	void printEnd(const string &msg = "");

	~Deque();
};


class WordDeq: public Deque<std::string> {
public:
	void Sort();
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
void Deque<T>::printFront(const string &msg) {
	cout << msg;

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
void Deque<T>::printEnd(const string &msg) {
	cout << msg;
	
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


void WordDeq::Sort() {
	bool isSorted = false;

	while (!isSorted) {
		isSorted = true;

		Node<string> *now = front;

		while (now->next) {
			Node<string> *l1 = now;
			Node<string> *l2 = now->next;

			if (l1->value > l2->value) {

				Node<string> *prev = l1->prev;
				Node<string> *next = l2->next;

				l2->prev = prev;
				l2->next = l1;
				l1->prev = l2;
				l1->next = next;

				if (l1 == front) {
					front = l2;
					next->prev = l1;
				}
				else if (l2 == end) {
					end = l1;
					prev->next = l2;
				}
				else {
					prev->next = l2;
					next->prev = l1;
				}

				isSorted = false;
			}
			else 
				now = now->next;
		}
	}
}

#endif