#include<iostream>
#include "CustomList.h"

template <class Type>
CustomList<Type>::CustomList(int size) : MyList<Type>(size) {}

template <class Type>
Type CustomList<Type>::sum_ofPrime() 
{

	Type sum = 0;
	for (int i = 0; i < currentSize; i++) {
		bool isPrime = true;
		if (arr[i] < 2) isPrime = false;
		else {
			for (Type j = 2; j * j <= arr[i]; j++) {
				if (arr[i] % j == 0) {
					isPrime = false;
					break;
				}
			}
		}
		if (isPrime) sum += arr[i];
	}
	return sum;
	
}

template <class Type>
Type CustomList<Type>::secondMaxEven() 
{
	Type max1 = -1, max2 = -1;
	for (int i = 0; i < currentSize; i++) {
		if (arr[i] % 2 == 0) {
			if (arr[i] > max1) {
				max2 = max1;
				max1 = arr[i];
			}
			else if (arr[i] > max2 && arr[i] < max1) {
				max2 = arr[i];
			}
		}
	}
	return max2;
}

template <class Type>
Type CustomList<Type>::secondMinOdd() 
{
	Type min1 = INT_MAX, min2 = INT_MAX;
	for (int i = 0; i < currentSize; i++) {
		if (arr[i] % 2 != 0) {
			if (arr[i] < min1) {
				min2 = min1;
				min1 = arr[i];
			}
			else if (arr[i] < min2 && arr[i] > min1) {
				min2 = arr[i];
			}
		}
	}
	return min2;
}

template <class Type>
void CustomList<Type>::printDuplicates()
{
	for (int i = 0; i < currentSize; i++) {
		bool isDuplicate = false;
		for (int j = i + 1; j < currentSize; j++) {
			if (arr[i] == arr[j]) {
				isDuplicate = true;
				break;
			}
		}
		if (isDuplicate) {
			cout << arr[i] << " is duplicated." << endl;
		}
	}
}

template <class Type>
void CustomList<Type>::rotateClockwise(int r) 
{
	if (currentSize == 0) return;
	r = r % currentSize;
	for (int i = 0; i < r; i++) {
		Type temp = arr[currentSize - 1];
		for (int j = currentSize - 1; j > 0; j--) {
			this->arr[j] = arr[j - 1];
		}
		arr[0] = temp;
	}
}

template <class Type>
void CustomList<Type>::rotateAntiClockwise(int rt) 
{
	if (currentSize == 0)
		return;
	rt = rt % currentSize;
	for (int i = 0; i < rt; i++) 
	{
		Type temp = arr[0];
		for (int j = 0; j < currentSize - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		  arr[currentSize - 1] = temp;
	}
}