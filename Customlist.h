
#ifndef CUSTOMLIST_H
#define CUSTOMLIST_H

#include "MyList.h"

template <typename Type>
class CustomList : public MyList<Type> {
public:
	CustomList(int size = 10);
	CustomList(const CustomList& other);
	~CustomList();

	Type sum_ofPrime();
	Type secondMaxEven();
	Type secondMinOdd();
	void printDuplicates();
	void rotateClockwise(int r);
	void rotateAntiClockwise(int rt);
};

#endif 