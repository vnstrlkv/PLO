#include "Array.h"

Array::Array()
{
	maxSizeArray = 100;
	currentIndex = 0;
	ptrArray = new int[maxSizeArray];
	sizeArray = 0;
}

Array::Array(int size, int value, ...)
{
	int *p = &value;
	sizeArray = size;
	maxSizeArray = size;
	ptrArray = new int[maxSizeArray];
	currentIndex = ptrArray[0];
	for (int i = 0; i < size; i++)
	{
		ptrArray[i] = *p;
		p++;
	}

}
Array::Array(int *ptr, int size)
{
	sizeArray = size;
	maxSizeArray = size;
	ptrArray = new int[maxSizeArray];
	currentIndex = ptrArray[0];
	for (int i = 0; i < size; i++)
	{
		ptrArray[i] = ptr[i];
	}

}
Array::Array(const Array &tmp)
{
	sizeArray = tmp.sizeArray;
	maxSizeArray = tmp.maxSizeArray;
	ptrArray = new int[maxSizeArray];
	for (int i = 0; i < sizeArray; i++)
		ptrArray[i] = tmp.ptrArray[i];
}




Array::~Array()
{
	delete[] ptrArray;
}

void Array::view() const
{
	for (int i = 0; i < sizeArray; i++)
	{
		if (i % 5 == 0)
			std::cout << std::endl<<std::endl;
		std::cout << i << ": " << std::setw(5) << std::left  << ptrArray[i] << "| ";
	}
	std::cout<< std::endl << std::endl;
}


void Array::add(int val)
{
	//	ptrArray=resize_array();	
		ptrArray[sizeArray] = val;
		sizeArray++;		
}

Array* Array::copy()
{
	Array *tmp;
	tmp->sizeArray=sizeArray;
	tmp->maxSizeArray= maxSizeArray;
	tmp->ptrArray = new int[maxSizeArray];
	for (int i = 0; i < sizeArray; i++)
		tmp->ptrArray[i] = ptrArray[i];
	return tmp;
}


void Array::remove(int val)
{
	int number = search(val);
	if (number >= 0)
	{
		{
			for (int i = number; i < sizeArray - 1; i++)
				ptrArray[i] = ptrArray[i + 1];
		}
		sizeArray--;
	}
		//ptrArray = resize_array();
}

void Array::removeByIndex(int index)
{
	if (index>=0 && index < sizeArray)
	{
		{
			for (int i = index; i < (sizeArray); i++)
				ptrArray[i] = ptrArray[i + 1];
		}
		sizeArray--;
	}
//	ptrArray = resize_array();
}

int Array::search(int item)
{
	currentIndex = -1;
	for (int i=0;i<sizeArray;i++)

		if (ptrArray[i] == item)
		{
			currentIndex = i;
			break;
		}

	return currentIndex;
}

int* Array::resize_array()
{
	int *tmp=ptrArray;
	if (sizeArray >= maxSizeArray / 3 * 2)
	{
		maxSizeArray = maxSizeArray * 2;
		tmp=new int [maxSizeArray];
		for (int i = 0; i < sizeArray; i++)
			tmp[i] = ptrArray[i];
		delete[] ptrArray;
	}
	else if (sizeArray <= maxSizeArray / 2 && maxSizeArray>100)
	{
		maxSizeArray = maxSizeArray / 3 * 2;
		tmp = new int[maxSizeArray];
		for (int i = 0; i < sizeArray; i++)
			tmp[i] = ptrArray[i];
		delete[] ptrArray;
	}
	return tmp;
}

void Array::replace(int index, int value)
{
	if (index>=0 && index < sizeArray)
	ptrArray[index] = value;
}

int Array::maxSize() const
{
	return maxSizeArray;
}
int Array::size() const
{
	return sizeArray;
}
int Array::get(int index) const
{
	int tmp = NULL;
	if (index<sizeArray)
	tmp= ptrArray[index];
	return tmp;
}
int Array::max() const
{
	int tmp = ptrArray[0];
	{
		for (int i = 1; i < sizeArray; i++)
			if (tmp < ptrArray[i])
				tmp = ptrArray[i];
	}
	return tmp;
}

int Array::min() const
{
	int tmp = ptrArray[0];
	{
		for (int i = 1; i < sizeArray; i++)
			if (tmp > ptrArray[i])
				tmp = ptrArray[i];
	}
	return tmp;
}