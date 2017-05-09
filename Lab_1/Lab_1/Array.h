
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
	Array(int size, int value, ...);

	~Array();
	void view() const;
	void add(int value);//add
	void remove(int value);//remove
	void remove_item_index(int index);//removebyindex
	int search(int value);//search
	void replace(int index, int value);//repace
	int size()const; //size || count ||length
	int max_size()const;//max_size
	int get(int index)const;//get
	int max()const;//max
	int min()const;//min ///
};
