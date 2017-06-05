#pragma once
#include "Array.h"

class Queue : public Array
{
protected:
	int *first;
	int *last;
	int* resize_array();
public:
	Queue();
	Queue(int size, int value, ...);
	Queue(int *ptr, int size) ;
	Queue(const Array & tmp) ;


	bool add(int value);
	int get();
};