
//Вариант 7.
//Постpоить класс для pаботы с массивом.
//Класс должен включать соответствующие поля : максимальный размер массива, индекс текущего элемента, указатель на массив.
//Класс должен обеспечивать пpостейшие функции для pаботы с данными классами : добавление элементов, поиск, замена, удаление, вывод массива в удобной форме и т.д.
#pragma once
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <fstream>

template<typename T>
class Array;

template<typename T>
std::ostream& operator << (std::ostream &out, const Array<T> &obj);
template<typename T>
std::istream& operator >> (std::istream &in, Array<T> &obj);
template<typename T>
std::ofstream& operator << (std::ofstream &fout, const Array<T>& obj);
template<typename T>
std::ifstream& operator >> (std::ifstream &fin, Array<T> &obj);

template <typename TT>
Array<TT> operator + (const Array<TT> &left, const Array<TT> &right);

template <typename T>
Array<T> operator - (const Array<T> &left, const Array<T> &right);



template <typename T>
class Array
{
protected:
	int maxSizeArray;
	int currentIndex;
	T *ptrArray;
	int sizeArray;
	bool chekSize();
public:
	
	T & operator [] (int index) const;
	Array<T>& operator = (const Array<T> &rhs);
	bool operator == (Array<T> &rhs)const;
	bool operator != (Array<T> &rhs) const;

	Array<T>& operator ++();
	Array<T>& operator ++(int);
	Array<T>& operator --();
	Array<T>& operator --(int);

	Array<T> operator +(int);
	Array<T> operator -(int);

	template <typename TT>
	friend Array<TT> operator + (const Array<TT> &left, const Array<TT> &right);


	template <typename TT>
	friend Array<TT> operator - (const Array<TT> &left, const Array<TT> &right);
	
	friend std::ostream& operator << <T>(std::ostream &out, const Array<T> &obj);
	friend std::istream& operator >> <T>(std::istream &in, Array<T> &obj);

	friend std::ofstream& operator << <T>(std::ofstream &fout, const Array<T>& obj);
	friend std::ifstream& operator >> <T>(std::ifstream &fin, Array<T> &obj);
	
	

	Array();
	Array(int size, T value, ...);
	Array(T *ptr, int size);
	Array(const Array & tmp);

	~Array();
	void view() const;
virtual	bool add(T value);
	Array<T> copy();
	bool remove(T value);
	bool removeByIndex(int index);
	int search(T value);
	bool replace(int index, T value);
	int size()const; 
	int maxSize()const;
	int get(int index)const;
	int max()const;
	int min()const;
};
template <typename T>
Array<T>::Array()
{
	maxSizeArray = 16;
	currentIndex = 0;
	ptrArray = new T[maxSizeArray];
	sizeArray = 0;
}
template <typename T>
Array<T>::Array(int size, T value, ...)
{
	T *p = &value;
	sizeArray = size;
	maxSizeArray = size;
	ptrArray = new T[maxSizeArray];
	currentIndex = ptrArray[0];
	for (int i = 0; i < size; i++)
	{
		ptrArray[i] = *p;
		p=p+sizeof(p);
	}

}
template <typename T>
Array<T>::Array(T *ptr, int size)
{
	sizeArray = size;
	maxSizeArray = size;
	ptrArray = new T[maxSizeArray];
	currentIndex = ptrArray[0];
	for (int i = 0; i < size; i++)
	{
		ptrArray[i] = ptr[i];
	}

}
template <typename T>
Array<T>::Array(const Array &tmp)
{
	sizeArray = tmp.sizeArray;
	maxSizeArray = tmp.maxSizeArray;
	ptrArray = new T[maxSizeArray];
	for (int i = 0; i < sizeArray; i++)
		ptrArray[i] = tmp.ptrArray[i];
}



template <typename T>
Array<T>::~Array()
{
	delete[] ptrArray;
}
template <typename T>
void Array<T>::view() const
{
	for (int i = 0; i < sizeArray; i++)
	{
		if (i % 5 == 0)
			std::cout << std::endl << std::endl;
		std::cout << i << ": " << std::setw(5) << std::left <<ptrArray[i] << "| ";
	}
	std::cout << std::endl << std::endl;
}

template <typename T>
bool Array<T>::add(T val)
{
	bool flag = chekSize();
	if (flag)
	{
		ptrArray[sizeArray] = val;
		sizeArray++;
	}
	return flag;
}


template <typename T>
Array<T> Array<T>::copy()
{
	return Array(*this);
}

template <typename T>
bool Array<T>::remove(T val)
{
	bool flag = false;
	int number = search(val);
	if (number >= 0)
	{
		{
			for (int i = number; i < sizeArray - 1; i++)
				ptrArray[i] = ptrArray[i + 1];
		}
		sizeArray--;
		flag = true;
	}
	return flag;

}
template <typename T>
bool Array<T>::removeByIndex(int index)
{
	bool flag = false;
	if (index >= 0 && index < sizeArray)
	{
		{
			for (int i = index; i < (sizeArray); i++)
				ptrArray[i] = ptrArray[i + 1];
		}
		sizeArray--;
		flag = true;
	}
	return flag;
}
template <typename T>
int Array<T>::search(T item)
{
	currentIndex = -1;
	for (int i = 0; i<sizeArray; i++)

		if (ptrArray[i] == item)
		{
			currentIndex = i;
			break;
		}

	return currentIndex;
}
template <typename T>
bool Array<T>::chekSize()
{
	bool flag = false;
	if (size() < maxSize())
		flag = true;
	return flag;

}
template <typename T>
bool Array<T>::replace(int index, T value)
{
	bool flag = false;
	if (index >= 0 && index < sizeArray)
	{
		ptrArray[index] = value;
		flag = true;
	}
	return flag;
}

template <typename T>
int Array<T>::maxSize() const
{
	return maxSizeArray;
}

template <typename T>
int Array<T>::size() const
{
	return sizeArray;
}

template <typename T>
int Array<T>::get(int index) const
{
	int tmp = NULL;
	if (index<sizeArray)
		tmp = ptrArray[index];
	return tmp;
}

template <typename T>
int Array<T>::max() const
{
	int tmp = ptrArray[0];
	{
		for (int i = 1; i < sizeArray; i++)
			if (tmp < ptrArray[i])
				tmp = ptrArray[i];
	}
	return tmp;
}
template <typename T>
int Array<T>::min() const
{
	int tmp = ptrArray[0];
	{
		for (int i = 1; i < sizeArray; i++)
			if (tmp > ptrArray[i])
				tmp = ptrArray[i];
	}
	return tmp;
}


template <typename T>
T & Array<T>:: operator [] (int index) const { return ptrArray[index]; }

template <typename T>
Array<T>& Array<T>:: operator = (const Array<T> &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	maxSizeArray = rhs.maxSizeArray;
	currentIndex = rhs.currentIndex;
	sizeArray = rhs.sizeArray;
	delete[] ptrArray;
	ptrArray = new T[sizeArray];
	for (int i = 0; i < sizeArray; i++)
	{
		ptrArray[i] = rhs.ptrArray[i];
	}
	return *this;
};
template <typename T>
bool Array<T>:: operator == (Array &rhs)const
{
	bool flag = true;
	if (rhs.size() != size())
	{
		flag = false;
		return flag;
	}
	for (int i = 0; i < size(); i++)
	{
		if (rhs.ptrArray[i] != this->ptrArray[i])
		{
			flag = false;
			break;
		}
	}
	return flag;
}

template <typename T>
bool Array<T>:: operator != (Array &rhs) const
{
	bool flag = !(*this == rhs);
	return flag;
}



template <typename T>
Array<T>& Array<T>:: operator ++(int)
{
	for (int i = 0; i < size(); i++)
	{
		this->ptrArray[i]++;
	}
	return *this;
};

template <typename T>
Array<T>& Array<T>:: operator ++()
{
	Array<T> tmp(*this);
	for (int i = 0; i < size(); i++)
	{
		ptrArray[i]++;
	}
	return tmp;
}

template <typename T>
Array<T>& Array<T>:: operator --(int)
{
	for (int i = 0; i < size(); i++)
	{
		this->ptrArray[i]--;
	}
	return *this;
};

template <typename T>
Array<T>& Array<T>:: operator --()
{
	Array<T> tmp(*this);
	for (int i = 0; i < size(); i++)
	{
		ptrArray[i]--;
	}
	return tmp;
};

template <typename T>
Array<T> Array<T>::operator +(int number)
{

	Array<T> tmp(*this);
	for (int i = 0; i < size(); i++)
	{
		tmp.ptrArray[i] += number;
	}
	return tmp;
};

template <typename T>
Array<T> Array<T>::operator -(int number)
{
	Array<T> tmp(*this);
	for (int i = 0; i < size(); i++)
	{
		tmp.ptrArray[i] -= number;
	}
	return tmp;
};

template <typename T>
std::ostream& operator << (std::ostream &out, const Array<T> &obj)
{
	for (int i = 0; i < obj.size(); i++)
	{
		if (i % 5 == 0)
			out << std::endl << std::endl;
		out << i << ": " << std::setw(5) << std::left << obj.ptrArray[i] << "| ";
	}
	return out;
}

template <typename T>
std::istream& operator >> (std::istream &in, Array<T> &obj)
{
	std::cout << "Input size: ";
	in >> obj.sizeArray;
	std::cout << std::endl << "Input value:";
	for (int i = 0; i < obj.size(); i++)
	{
		in >> obj[i];
	}
	return in;
}

template <typename T>
std::ofstream& operator << (std::ofstream &fout, const Array<T>  &obj)
{
	fout << obj.size() << " ";
	for (int i = 0; i < obj.size(); i++)
	{
		fout << obj.ptrArray[i] << " ";
	}
	return fout;
}

template <typename T>
std::ifstream& operator >> (std::ifstream &fin, Array<T> &obj)
{
	fin >> obj.sizeArray;
	for (int i = 0; i < obj.size(); i++)
	{
		fin >> obj[i];
	}
	return fin;
}



template <typename T>
Array<T> operator + (const Array<T> &left, const Array<T> &right)
{
	Array<T> tmp;
	if (left.sizeArray >= right.sizeArray)
	{
		tmp = left;
		for (int i = 0; i < right.sizeArray; i++)
			tmp.ptrArray[i] += right.ptrArray[i];
	}
	if (left.sizeArray < right.sizeArray)
	{
		tmp = right;
		for (int i = 0; i < left.sizeArray; i++)
			tmp.ptrArray[i] += left.ptrArray[i];
	}
	return tmp;
};

template <typename T>
Array<T> operator - (const Array<T> &left, const Array<T> &right)
{

	Array<T> tmp;
	if (left.sizeArray >= right.sizeArray)
	{
		tmp = left;
		for (int i = 0; i < right.sizeArray; i++)
			tmp.ptrArray[i] -= right.ptrArray[i];
	}
	if (left.sizeArray < right.sizeArray)
	{
		tmp = right;
		for (int i = 0; i < left.sizeArray; i++)
			tmp.ptrArray[i] -= left.ptrArray[i];
	}
	return tmp;

};