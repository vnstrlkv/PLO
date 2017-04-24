#include "Array.h"
#include <conio.h>
void menu(Array &arr);
void show_menu()
{
	std::cout << "1.View array" << std::endl << "2. Add item" << std::endl << "3. Remove item by val" << std::endl << "4. Remove item by index" << std::endl << std::endl;
}

void menu(Array &arr)
{
	show_menu();
	char key;
	key=getch();
	switch (key)
	{
	case '0':
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
		arr.add_item(val);
		break;
	}
	case '3':
	{
		int val;
		std::cout << "Input val: ";
		std::cin >> val;
		std::cout << std::endl;
		arr.remove_item_val(val);
		break;
	}
	case '4':
	{
		int index;
		std::cout << "Input index: ";
		std::cin >> index;
		std::cout << std::endl;
		arr.remove_item_index(index);
		break;
	}
	}
	menu(arr);
}

void main()
{
	Array arr;
	menu(arr);
}