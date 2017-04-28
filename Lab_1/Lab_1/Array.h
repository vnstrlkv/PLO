
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
	Array();// �����������, � ����������� //����� copy
	~Array();
	void view() const;
	void add_item(int value);//add
	void remove_item_val(int value);//remove
	void remove_item_index(int index);//removebyindex
	int search_item(int value);//search
	void replace_value(int index, int value);//repace
	int get_size()const; //size || count ||length
	int get_max_size()const;//max_size
	int get_item(int index)const;//get
	int get_maxVal()const;//max
	int get_minVal()const;//min
};
