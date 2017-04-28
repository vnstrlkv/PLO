
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
	int *ptr_array;
	int size;
	int* resize_array();
public:
	Array();
	~Array();
	void view() const;
	void add_item(int);
	void remove_item_val(int);
	void remove_item_index(int);
	int search_item(int);
	int get_size()const;
	int get_max_size()const;
	int get_item(int)const;
	int get_maxVal()const;
	int get_minVal()const;
};
