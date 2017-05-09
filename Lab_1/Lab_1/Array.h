
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
