#include "Array.h"



/*
int & Array:: operator [] (int index) const { return ptrArray[index]; }

Array& Array:: operator = (Array &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	maxSizeArray = rhs.maxSizeArray;
	currentIndex = rhs.currentIndex;
	sizeArray = rhs.sizeArray;
	delete[] ptrArray;
	ptrArray = new int[sizeArray];
	for (int i = 0; i < sizeArray; i++)
	{
		ptrArray[i] = rhs.ptrArray[i];
	}
	return *this;
};
bool Array:: operator == (Array &rhs)const
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
bool Array:: operator != (Array &rhs) const
{
	bool flag = !(*this == rhs);
	return flag;
}
Array operator +(Array &left, Array &right)
{
	Array tmp;
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
Array operator -(Array &left, Array &right)
{
	Array tmp;
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
Array& Array:: operator ++(int)
{
	for (int i = 0; i < size(); i++)
	{
		this->ptrArray[i]++;
	}
	return *this;
};
Array& Array:: operator ++()
{
	Array tmp(*this);
	for (int i = 0; i < size(); i++)
	{
		ptrArray[i]++;
	}
	return tmp;
}
Array& Array:: operator --(int)
{
	for (int i = 0; i < size(); i++)
	{
		this->ptrArray[i]--;
	}
	return *this;
};
Array& Array:: operator --()
{
	Array tmp(*this);
	for (int i = 0; i < size(); i++)
	{
		ptrArray[i]--;
	}
	return tmp;
};
Array Array::operator +(int number)
{

	Array tmp(*this);
	for (int i = 0; i < size(); i++)
	{
		tmp.ptrArray[i] += number;
	}
	return tmp;
};
Array Array::operator -(int number)
{
	Array tmp(*this);
	for (int i = 0; i < size(); i++)
	{
		tmp.ptrArray[i] -= number;
	}
	return tmp;
};

std::ostream& operator << (std::ostream &out, const Array &obj)
{
	for (int i = 0; i < obj.size(); i++)
	{
		if (i % 5 == 0)
			out << std::endl << std::endl;
		out << i << ": " << std::setw(5) << std::left << obj.ptrArray[i] << "| ";
	}
	return out;
}

std::istream& operator >> (std::istream &in, Array &obj)
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


std::ofstream& operator << (std::ofstream &fout, const Array  &obj)
{
	fout << obj.size() << " ";
	for (int i = 0; i < obj.size(); i++)
	{
		fout << obj.ptrArray[i] << " ";
	}
	return fout;
}

std::ifstream& operator >> (std::ifstream &fin, Array &obj)
{
	fin >> obj.sizeArray;
	for (int i = 0; i < obj.size(); i++)
	{
		fin >> obj[i];
	}
	return fin;
}
*/