
//Вариант 7.
//Постpоить класс для pаботы с массивом.
//Класс должен включать соответствующие поля : максимальный размер массива, индекс текущего элемента, указатель на массив.
//Класс должен обеспечивать пpостейшие функции для pаботы с данными классами : добавление элементов, поиск, замена, удаление, вывод массива в удобной форме и т.д.

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
