
//������� 7.
//����p���� ����� ��� p����� � ��������.
//����� ������ �������� ��������������� ���� : ������������ ������ �������, ������ �������� ��������, ��������� �� ������.
//����� ������ ������������ �p�������� ������� ��� p����� � ������� �������� : ���������� ���������, �����, ������, ��������, ����� ������� � ������� ����� � �.�.

#include <conio.h>
#include <iostream>
#include <iomanip>

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
	void add_item(int value);
	void remove_item_val(int value);
	void remove_item_index(int index);
	int search_item(int value);
	void replace_value(int index, int value);
	int get_size()const;
	int get_max_size()const;
	int get_item(int index)const;
	int get_maxVal()const;
	int get_minVal()const;
};
