#pragma once
#include "Array.h"
#include "CyclicArray.h"
#include "Queue.h"


void main()
{
	system("color F0");
	Array<char> arr1(5,'1','s','r','y','w');
	Array<char> arr2(3, 'r', 'd', 's');
	Array<char>arr3;
	arr3 = arr1 + arr2;
	std::cout << "Char Array" << std::endl;
	std::cout << "arr1:" <<arr1<< std::endl;
	std::cout << "arr2:" << arr2 << std::endl;
	std::cout << "arr3=arr1+arr2:" << arr3 << std::endl;
	std::cout << "Double Array" << std::endl;
	Array<double> arr4;
	std::cin >> arr4;
	arr4++;
	std::cout << "arr4++:" << arr4 << std::endl;
}