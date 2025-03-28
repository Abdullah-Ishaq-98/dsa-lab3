#ifndef MYLIST_H
#define MYLIST_H

#include "List.h"

template <class Type>
class MyList : public List<Type> {
public:
	MyList(int size = 10);
	MyList(const MyList &other);
	~MyList();

	bool empty();
	bool full();
	int size();
	bool insertAt(int index, Type value);
	Type last();
	bool search(Type value);
	void addElementAtFirstIndex(Type value) override;
	void addElementAtLastIndex(Type value) override;
	Type removeElementFromEnd() override;
	void removeElementFromStart() override;
};

#endif 