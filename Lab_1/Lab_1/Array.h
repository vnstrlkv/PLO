
//Вариант 7.
//Постpоить класс для pаботы с массивом.
//Класс должен включать соответствующие поля : максимальный размер массива, индекс текущего элемента, указатель на массив.
//Класс должен обеспечивать пpостейшие функции для pаботы с данными классами : добавление элементов, поиск, замена, удаление, вывод массива в удобной форме и т.д.

#include <conio.h>
#include <iostream>
#include <iomanip>
#include <fstream>

class Array
{
	int maxSizeArray;
	int currentIndex;
	int *ptrArray;
	int sizeArray;
	bool chekSize();
public:

	int & operator [] (int index) const;
	Array& operator = (Array &rhs);
	bool operator == (Array &rhs)const;
	bool operator != (Array &rhs) const;

	Array& operator ++();
	Array& operator ++(int);
	Array& operator --();
	Array& operator --(int);

	Array operator +(int);
	Array operator -(int);

	friend Array operator +(Array &left, Array &right);
	friend Array operator -(Array &left, Array &right);	
	
	friend std::ostream& operator << (std::ostream &out, const Array &obj);
	friend std::istream& operator >> (std::istream &in, Array &obj);

	friend std::ofstream& operator << (std::ofstream &fout, const Array& obj);
	friend std::ifstream& operator >> (std::ifstream &fin, Array &obj);

	

public:
	Array();
	Array(int size, int value, ...);
	Array(int *ptr, int size);
	Array(const Array & tmp);

	~Array();
	void view() const;
	bool add(int value);
	Array copy();
	bool remove(int value);
	bool removeByIndex(int index);
	int search(int value);
	bool replace(int index, int value);
	int size()const; 
	int maxSize()const;
	int get(int index)const;
	int max()const;
	int min()const;
};
