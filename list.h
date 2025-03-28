#ifndef LIST_H
#define LIST_H

template <class Type>
class List {
protected:
	Type *arr;
	int maxSize;
	int currentSize;

public:
	List(int size = 10);
	List(const List &other);
	virtual ~List();

	virtual void addElementAtFirstIndex(Type value) = 0;
	virtual void addElementAtLastIndex(Type value) = 0;
	virtual Type removeElementFromEnd() = 0;
	virtual void removeElementFromStart() = 0;
};

#endif 