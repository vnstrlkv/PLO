#include "Queue.h"

Queue::Queue()
{
Array:Array();
	first = ptrArray;
	last = ptrArray + sizeArray-1;
};
Queue::Queue(int size, int value, ...)
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
	first = ptrArray;
	last = ptrArray + sizeArray;
};
Queue::Queue(int *ptr, int size)
{
Array:Array(ptr, size);
	first = ptrArray;
	last = ptrArray + sizeArray;
};
Queue::Queue(const Array & tmp)
{
  //  Array:Array(tmp);
	first = ptrArray;
	last = ptrArray + sizeArray;
};



int* Queue::resize_array()
{
	int *tmp = ptrArray;
	if (sizeArray >= maxSizeArray / 3 * 2)
	{
		maxSizeArray = maxSizeArray * 2;
		tmp = new int[maxSizeArray];
		for (int i = 0; i < sizeArray; i++)
			tmp[i] = ptrArray[i];
		delete[] ptrArray;
	}
	else if (sizeArray < maxSizeArray / 2 && maxSizeArray>100)
	{
		maxSizeArray = maxSizeArray / 3 * 2;
		tmp = new int[maxSizeArray];
		for (int i = 0; i < sizeArray; i++)
			tmp[i] = ptrArray[i];
		delete[] ptrArray;
	}
	first = tmp;
	return tmp;
}

bool Queue::add(int value)
{
	bool flag=false;
	ptrArray=resize_array();
	flag=Array::add(value);
	return flag;
}


int Queue::get()
{
	int tmp;
	tmp = *first;
	for (int i = 0; i < sizeArray-1; i++)
	{
		ptrArray[i] = ptrArray[i + 1];
	}
	try
	{
		if (first == &ptrArray[sizeArray]) throw ("Queue Free");

	}
	catch (const char *a)
	{
		std::cerr << a << std::endl;
		return NULL;
	}
	if (first != &ptrArray[sizeArray])
	{
		sizeArray--;
		return tmp;
	}
}
