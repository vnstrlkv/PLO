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
template <class T, typename TT>
void menu(T &arr, TT)
{
	TT temp=0;
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
		TT val;
		std::cout << "Input val: ";
		
		std::cin >> val;
		std::cin.clear();
		std::cout << std::endl;
		arr.add(val);
	
		break;
	}
	case '3':
	{
		TT val;
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
	//	std::cout <<arr.get()<< std::endl;
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
		TT value;
		std::cin >> value;
		std::cout << std::endl;
		arr.replace(index, value);
		break;
	}
	}
	menu(arr, temp);
}

void main()
{
	Array<char> arr1;
	Array<char> arr2(3, 'r', 'd', 's');
	char temp=0;
	arr1 = arr2;
	 std::cout<<arr2;
	 std::cin >> arr1;
	 arr1 == arr2;
	 Array<char> arr3 = arr1 + arr2;

	//Array<char> arr = arr2 + arr1;
	//Array arr3;
	//arr[0] = 10;
//	arr++;
//	++arr;
//	arr3=arr-10;
//	std::cout << arr;
//	std::cin >> arr3;
//	std::ofstream ofs("test.txt");
//	ofs << arr3;
//	ofs.close();
//	Array arr4;

//	std::ifstream test("test.txt");
//	test >> arr4;
//	test.close();
//	std::cout <<std:: endl;
//	CyclicArray arr6 ;
//	Queue  arr7(1,1);
	menu(arr3, temp);
}