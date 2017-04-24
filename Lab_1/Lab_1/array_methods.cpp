#include "Array.h"

Array::Array()
{
	std::cout << "hello"<<std::endl;
	Array::max_size = 100;
	Array::current_index = 0;
	Array::pointer = new int[100];
	Array::size = 0;

}

Array::~Array()
{
	delete pointer;
}

void Array::view()
{
	for (int i = 0; i < size; i++)
		std::cout << i << ":" << pointer[i] << " ";
	std::cout<< std::endl;
}


void Array::add_item(int val)
{

	pointer[size] = val;
	size++;
}
void Array::remove_item_val(int val)
{
	int number = search_item(val);
	if (number != NULL)
	{
		{
			for (int i = number; i < size - 1; i++)
				pointer[i] = pointer[i + 1];
		}
		size--;
	}
}

void Array::remove_item_index(int index)
{
	if (index <= size)
	{
		{
			for (int i = index; i < size - 1; i++)
				pointer[i] = pointer[i + 1];
		}
		size--;
	}
}

int Array::search_item(int item)
{
	current_index = NULL;
	for (int i=0;i<size;i++)

		if (pointer[i] == item)
		{
			current_index = i;
			break;
		}

	return current_index;
}