#include<iostream>
using namespace std;
#include "MyList.h"

template <typename Type>
MyList<Type>::MyList(int size) : List<Type>(size) {}

template <typename Type>
MyList<Type>::MyList(const MyList &other) : List<Type>(other) {}

template <typename Type>
MyList<Type>::~MyList() {}

template <typename Type>
bool MyList<Type>::empty() {
	return this->currentSize == 0;
}

template <typename Type>
bool MyList<Type>::full() {
	return this->currentSize == this->maxSize;
}

template <typename Type>
int MyList<Type>::size() {
	return this->currentSize;
}

template <typename Type>
bool MyList<Type>::insertAt(int index, Type value) {
	if (index < 0 || index >= this->maxSize || this->currentSize >= this->maxSize) {
		return false;
	}
	for (int i = this->currentSize; i > index; i--) {
		this->arr[i] = this->arr[i - 1];
	}
	this->arr[index] = value;
	this->currentSize++;
	return true;
}

template <typename Type>
Type MyList<Type>::last() {
	return this->arr[this->currentSize - 1];
}

template <typename Type>
bool MyList<Type>::search(Type value) {
	for (int i = 0; i < this->currentSize; i++) {
		if (this->arr[i] == value) {
			return true;
		}
	}
	return false;
}

template <typename Type>
void MyList<Type>::addElementAtFirstIndex(Type value) {
	insertAt(0, value);
}

template <typename Type>
void MyList<Type>::addElementAtLastIndex(Type value) {
	if (!full()) {
		this->arr[this->currentSize++] = value;
	}
}

template <typename Type>
Type MyList<Type>::removeElementFromEnd() {
	if (!empty()) {
		return this->arr[--this->currentSize];
	}
	throw out_of_range("List is empty");
}

template <typename Type>
void MyList<Type>::removeElementFromStart() {
	if (!empty()) {
		for (int i = 0; i < this->currentSize - 1; i++) {
			this->arr[i] = this->arr[i + 1];
		}
		this->currentSize--;
	}
}
