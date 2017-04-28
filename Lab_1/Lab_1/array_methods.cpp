#include "Array.h"

Array::Array()
{
	max_size = 100;
	current_index = 0;
	ptr_array = new int[max_size];
	size = 0;

}

Array::~Array()
{
	delete ptr_array;
}

void Array::view() const
{
	for (int i = 0; i < size; i++)
		std::cout << i << ":" << ptr_array[i] << " ";
	std::cout<< std::endl;
}


void Array::add_item(int val)
{
		ptr_array=resize_array();	
		ptr_array[size] = val;
		size++;		
}
void Array::remove_item_val(int val)
{
	int number = search_item(val);
	if (number != NULL)
	{
		{
			for (int i = number; i < size - 1; i++)
				ptr_array[i] = ptr_array[i + 1];
		}
		size--;
	}
		ptr_array = resize_array();
}

void Array::remove_item_index(int index)
{
	if (index < size)
	{
		{
			for (int i = index; i < size; i++)
				ptr_array[i] = ptr_array[i + 1];
		}
		size--;
	}
	ptr_array = resize_array();
}

int Array::search_item(int item)
{
	current_index = NULL;
	for (int i=0;i<size;i++)

		if (ptr_array[i] == item)
		{
			current_index = i;
			break;
		}

	return current_index;
}

int* Array::resize_array()
{
	int *tmp=ptr_array;
	if (size >= max_size / 3 * 2)
	{
		max_size = max_size * 2;
		tmp=new int [max_size];
		for (int i = 0; i < size; i++)
			tmp[i] = ptr_array[i];
		delete[] ptr_array;
	}
	else if (size <= max_size / 2 && max_size>100)
	{
		max_size = max_size / 3 * 2;
		tmp = new int[max_size];
		for (int i = 0; i < size; i++)
			tmp[i] = ptr_array[i];
		delete[] ptr_array;
	}

	return tmp;
}

int Array::get_max_size() const
{
	return max_size;
}
int Array::get_size() const
{
	return size;
}
int Array::get_item(int index) const
{
	int tmp = NULL;
	if (index<size)
	tmp= ptr_array[index];
	return tmp;
}
int Array::get_maxVal() const
{
	int tmp = ptr_array[0];
	{
		for (int i = 1; i < size; i++)
			if (tmp < ptr_array[i])
				tmp = ptr_array[i];
	}
	return tmp;
}

int Array::get_minVal() const
{
	int tmp = ptr_array[0];
	{
		for (int i = 1; i < size; i++)
			if (tmp > ptr_array[i])
				tmp = ptr_array[i];
	}
	return tmp;
}