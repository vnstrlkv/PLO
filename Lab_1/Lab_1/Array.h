
//������� 7.
//����p���� ����� ��� p����� � ��������.
//����� ������ �������� ��������������� ���� : ������������ ������ �������, ������ �������� ��������, ��������� �� ������.
//����� ������ ������������ �p�������� ������� ��� p����� � ������� �������� : ���������� ���������, �����, ������, ��������, ����� ������� � ������� ����� � �.�.

#include <conio.h>
#include <iostream>


class Array
{
	int max_size;
	int current_index;
	int *pointer;
	int size;

public:
	Array();
	~Array();
	void view();
	void add_item(int);
	void remove_item_val(int);
	void remove_item_index(int);
	int search_item(int);
};
