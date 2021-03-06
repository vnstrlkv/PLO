
#include "Array.h"

class CyclicArray : public Array<int>
{
	int *ptr;

public:
	CyclicArray();
	CyclicArray(int size, int value, ...);
	CyclicArray(int *ptrtmp, int size);
	CyclicArray(const Array & tmp);
	bool add( int);
};
