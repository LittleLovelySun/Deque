#include <iostream>
#include "Dec.h"
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

template <typename T>
Node<T>::Node(T value) {
	next = NULL;
	prev = NULL;
	this->value = value;
}

template <typename T>
Node<T>::Node(Node *prev, Node *next, T value) {
	this->next = next;
	this->prev = prev;
	this->value = value;
}

template <typename T>
Node<T>::Node(const Node &a) {
	next = a->next;
	prev = a->prev;
	value = a->value;
}

template <typename T>
Node<T>::~Node() {
	delete next;
	delete prev;
}

template <typename T>
Deque<T>::Deque() {
	front = NULL;
	end = NULL;
}

template <typename T>
void Deque<T>::pushFront(const T &value) {
	if (!front) {
		Node<T> tmp(value);
		front = tmp;
		end = tmp;
	}
	else {
		Node<T> tmp(front, NULL, value);
		front->next = tmp;
		front = tmp;
	}
}

template <typename T>
void Deque<T>::pushEnd(const T &value) {
	if (!end) {
		Node<T> tmp(value);
		front = tmp;
		end = tmp;
	}
	else {
		Node<T> tmp(NULL, end, value);
		end->prev = tmp;
		end = tmp;
	}
}

template <typename T>
void Deque<T>::printFront() {
	if (!front) {
		cout << "Deque is empty";
		return;
	}

	Node<T> now(front);

	while (now) {
		cout << now->value << " ";
		now(now->prev);
	}
}

template <typename T>
void Deque<T>::printEnd() {
	if (!end) {
		cout << "Deque is empty";
		return;
	}

	Node<T> now(end);

	while (now) {
		cout << now->value << " ";
		now(now->next);
	}
}

template <typename T>
Deque<T>::~Deque() {

	while(front){
		Node<T> *tmp(front->prev);
		delete front;
		front = tmp;
	}
	front = NULL;
	end = NULL;
}

/*
void swap(Node<string> a, Node<string> b) {

}

void WordDeq::SortDeq() {
	if (!front) 
		return;

	bool key = true;

	while (key) {
		key = false;
		Node<string> tmp(front);

		while (tmp->prev) {
			if (strcmp(tmp->value, (tmp->prev)->value) > 0) {
				swap(tmp, tmp->prev);
				key = true;
			}
			tmp = tmp->prev;
		}
	}
}*/