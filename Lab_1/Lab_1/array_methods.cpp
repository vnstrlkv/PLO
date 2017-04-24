#include "Array.h"

Array::Array()
{
	Array::max_size = 100;
	Array::current_index = 0;
	Array::pointer = new int[100];
	for (int i = 0; i < max_size; i++)
		pointer[i] = NULL;
}

Array::~Array()
{
	delete pointer;
}

void Array::view()
{
	for (int i = 0; pointer[i] != NULL; i++)
		std::cout << pointer[i] << " " <<std:: endl;
}


void Array::add_item(int number)
{
	int i;
	while ()
}
void Array::remove_item(int number)
{

}
void Array::search_item(int item)
{

}