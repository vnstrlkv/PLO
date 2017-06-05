#include "CyclicArray.h"
CyclicArray::CyclicArray()
{
Array:Array();
	ptr = ptrArray; 
}
CyclicArray::CyclicArray(int size, int value, ...)
{
	int *p = &(value);
	sizeArray = size;
	maxSizeArray = size;
	ptrArray = new int[size];
	currentIndex = ptrArray[0];
	for (int i = 0; i < size; i++)
	{
		ptrArray[i] = *p;
		p++;
	}
	ptr = ptrArray;
}

CyclicArray::CyclicArray(int *ptrtmp, int size) :Array(ptrtmp, size) { ptr = ptrArray; };
CyclicArray::CyclicArray(const Array & tmp) :Array(tmp) { ptr = ptrArray; };


void CyclicArray::add(int value)
{
	if (Array::add(value) == false)
	{
		*ptr = value;
		ptr++;
		if (ptr == (ptrArray + sizeArray))
			ptr = ptrArray;
	}
	else (ptr = ptrArray);
}

