#include "Array.h"

Array::Array()
{
	maxSizeArray = 16;
	currentIndex = 0;
	ptrArray = new int[maxSizeArray];
	sizeArray = 0;
}

Array::Array(int size, int value, ...)
{
	int *p = &value;
	sizeArray = size;
	maxSizeArray = size;
	ptrArray = new int[maxSizeArray];
	currentIndex = ptrArray[0];
	for (int i = 0; i < size; i++)
	{
		ptrArray[i] = *p;
		p++;
	}

}
Array::Array(int *ptr, int size)
{
	sizeArray = size;
	maxSizeArray = size;
	ptrArray = new int[maxSizeArray];
	currentIndex = ptrArray[0];
	for (int i = 0; i < size; i++)
	{
		ptrArray[i] = ptr[i];
	}

}
Array::Array(const Array &tmp)
{
	sizeArray = tmp.sizeArray;
	maxSizeArray = tmp.maxSizeArray;
	ptrArray = new int[maxSizeArray];
	for (int i = 0; i < sizeArray; i++)
		ptrArray[i] = tmp.ptrArray[i];
}




Array::~Array()
{
	delete[] ptrArray;
}

void Array::view() const
{
	for (int i = 0; i < sizeArray; i++)
	{
		if (i % 5 == 0)
			std::cout << std::endl << std::endl;
		std::cout << i << ": " << std::setw(5) << std::left << ptrArray[i] << "| ";
	}
	std::cout << std::endl << std::endl;
}


bool Array::add(int val)
{
	bool flag = chekSize();
	if (flag)
	{
		ptrArray[sizeArray] = val;
		sizeArray++;
	}
	return flag;
}

Array Array::copy()
{
	return Array(*this);
}


bool Array::remove(int val)
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

bool Array::removeByIndex(int index)
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

int Array::search(int item)
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

bool Array::chekSize()
{
	bool flag = false;
	if (size() < maxSize())
		flag = true;
	return flag;

}

bool Array::replace(int index, int value)
{
	bool flag = false;
	if (index >= 0 && index < sizeArray)
	{
		ptrArray[index] = value;
		flag = true;
	}
	return flag;
}

int Array::maxSize() const
{
	return maxSizeArray;
}
int Array::size() const
{
	return sizeArray;
}
int Array::get(int index) const
{
	int tmp = NULL;
	if (index<sizeArray)
		tmp = ptrArray[index];
	return tmp;
}
int Array::max() const
{
	int tmp = ptrArray[0];
	{
		for (int i = 1; i < sizeArray; i++)
			if (tmp < ptrArray[i])
				tmp = ptrArray[i];
	}
	return tmp;
}

int Array::min() const
{
	int tmp = ptrArray[0];
	{
		for (int i = 1; i < sizeArray; i++)
			if (tmp > ptrArray[i])
				tmp = ptrArray[i];
	}
	return tmp;
}



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