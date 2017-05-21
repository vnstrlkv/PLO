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
		std::cout <<arr.get()<< std::endl;
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
	Array arr1(5, 2, 3, 4,5, 6);
	Array arr2(3, 0, 0, 1);
	
	Array arr = arr2 + arr1;
	Array arr3;
	//arr[0] = 10;
	arr++;
//	++arr;
	arr3=arr-10;
	std::cout << arr;
//	std::cin >> arr3;
//	std::ofstream ofs("test.txt");
//	ofs << arr3;
//	ofs.close();
	Array arr4;

//	std::ifstream test("test.txt");
//	test >> arr4;
//	test.close();
//	std::cout <<std:: endl;
	CyclicArray arr6 ;
	Queue  arr7(1,1);
	menu(arr7);
}