
//Вариант 7.
//Постpоить класс для pаботы с массивом.
//Класс должен включать соответствующие поля : максимальный размер массива, индекс текущего элемента, указатель на массив.
//Класс должен обеспечивать пpостейшие функции для pаботы с данными классами : добавление элементов, поиск, замена, удаление, вывод массива в удобной форме и т.д.

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
	Array();// копирования, с параметрами //метод copy
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
