
//������� 7.
//����p���� ����� ��� p����� � ��������.
//����� ������ �������� ��������������� ���� : ������������ ������ �������, ������ �������� ��������, ��������� �� ������.
//����� ������ ������������ �p�������� ������� ��� p����� � ������� �������� : ���������� ���������, �����, ������, ��������, ����� ������� � ������� ����� � �.�.

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
	int* resize_array();
public:

	int & operator [] (int index) const { return ptrArray[index]; };
	Array& operator = (Array &rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		maxSizeArray=rhs.maxSizeArray;
		currentIndex=rhs.currentIndex;
		sizeArray=rhs.sizeArray;
		delete[] ptrArray;
		ptrArray = new int [sizeArray];
		for (int i = 0; i < sizeArray; i++)
		{
			ptrArray[i] = rhs.ptrArray[i];
		}
		return *this;
	};
	bool operator == (Array &rhs)const
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
	bool operator != ( Array &rhs) const
	{
		bool flag = !(*this == rhs);
		return flag;
	}

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
	void add(int value);
	Array copy();
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
