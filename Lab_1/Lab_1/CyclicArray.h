
#include "Array.h"

class CyclicArray : public Array
{
	int *ptr;

public:
	CyclicArray();
	CyclicArray(int size, int value, ...);
	CyclicArray(int *ptrtmp, int size) :Array(ptrtmp, size) { ptr = ptrArray; };
	CyclicArray(const Array & tmp) :Array(tmp) { ptr = ptrArray; };
	void add( int);
};