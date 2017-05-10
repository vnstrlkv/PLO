
//Вариант 7.
//Постpоить класс для pаботы с массивом.
//Класс должен включать соответствующие поля : максимальный размер массива, индекс текущего элемента, указатель на массив.
//Класс должен обеспечивать пpостейшие функции для pаботы с данными классами : добавление элементов, поиск, замена, удаление, вывод массива в удобной форме и т.д.

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
