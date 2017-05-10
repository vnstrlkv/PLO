
//������� 7.
//����p���� ����� ��� p����� � ��������.
//����� ������ �������� ��������������� ���� : ������������ ������ �������, ������ �������� ��������, ��������� �� ������.
//����� ������ ������������ �p�������� ������� ��� p����� � ������� �������� : ���������� ���������, �����, ������, ��������, ����� ������� � ������� ����� � �.�.

#include <conio.h>
#include <iostream>
#include <iomanip>

class Array
{
	int maxSizeArray;
	int currentIndex;
	int *ptrArray;
	int sizeArray;
	int* resize_array();

public:
	Array();
	Array(int size, int value, ...);
	Array(int *ptr, int size);
	Array(const Array & tmp);

	~Array();
	void view() const;
	void add(int value);
	Array* copy();
	void remove(int value);
	void removeByIndex(int index);
	int search(int value);
	void replace(int index, int value);
	int size()const; 
	int maxSize()const;
	int get(int index)const;
	int max()const;
	int min()const;
};
