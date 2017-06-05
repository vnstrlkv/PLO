#pragma once
#include "Array.h"
#include "CyclicArray.h"
#include "Queue.h"
void show_menu()
{
	std::cout 
		<< "1. View array" << std::endl 
		<< "2. Add item" << std::endl 
		<< "3. Remove item by val" << std::endl 
		<< "4. Remove item by index" << std::endl 
		<< "5. Get value" << std::endl
		<< "6. Get min value" << std::endl
		<< "7. Get size" << std::endl
		<< "8. Replace value" << std::endl
		<< "esc: exit" << std::endl << std::endl;
}
template <typename T>
void menu(T &arr)
{
	show_menu();
	char key;
	key=getch();
	switch (key)
	{
	case '\033':
	{
		exit(0);
		break;
	}
	case '1': //view
	{
		arr.view();
		break;
	}
	case '2':
	{
		int val;
		std::cout << "Input val: ";
		std::cin >> val;
		std::cout << std::endl;
		arr.add(val);
		break;
	}
	case '3':
	{
		int val;
		std::cout << "Input val: ";
		std::cin >> val;
		std::cout << std::endl;
		arr.remove(val);
		break;
	}
	case '4':
	{
		int index;
		std::cout << "Input index: ";
		std::cin >> index;
		std::cout << std::endl;
		arr.removeByIndex(index);
		break;
	}

	case '5':
	{
		std::cout << "Get: ";
//		std::cout <<arr.get()<< std::endl;
		break;
	}
	case '6':
	{
		std::cout << "Min value: ";
		std::cout << arr.min() << std::endl;
		break;
	}
	case '7':
	{
		std::cout << "Size array: ";
		std::cout << arr.size() << std::endl;
		break;
	}
	case '8':
	{
		std::cout << "Input index: " << std::endl;
		int index;
		std:: cin >> index;
		std::cout << std::endl;
		std::cout << "Input value: " << std::endl;
		int value;
		std::cin >> value;
		std::cout << std::endl;
		arr.replace(index, value);
		break;
	}
	}
	menu(arr);
}

void main()
{
	system("color F0");

	CyclicArray arr6(5,1,2,3,4,5) ;
	std::cout << "CyclicArray  " <<arr6<< std::endl;
	int val;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "Input val: ";
		std::cin >> val;
		std::cout << std::endl;
		arr6.add(val);
		std::cout << arr6 << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	Queue arr(5, 1, 2, 3, 4, 5);
	std::cout << "Queue  " << arr << std::endl;
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Add val: ";
		std::cin >> val;
		std::cout << std::endl;
		arr.add(val);
		std::cout << arr << std::endl;
	}
	for (int i = 0; i < 15; i++)
	{
		std::cout << "Get val: "<<arr.get();
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << arr;
		std::cout << std::endl;
	}
		



	menu(arr);
}