
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

public:
	Array();
	~Array();
	void view();
	void add_item(int);
	void remove_item(int);
	void search_item(int);
};
