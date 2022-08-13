#pragma once
#include"Data.h"
#include<initializer_list>
#include<cassert>
#include"Func.h"

template<class T>
class ForwardList
{
	Data<T>* first = nullptr;
	Data<T>* last = nullptr;
	size_t   size = 0;

public:
	ForwardList() {	}
	ForwardList(initializer_list<T> list);
	~ForwardList();
	ForwardList(const ForwardList& l);
	ForwardList<T>& operator=(const ForwardList<T>& l);

	void push_back(const T& value);
	void push_front(const T& value);
	void insert(const T& value, size_t ind);

	void pop_back();
	void pop_front();
	void remove(size_t ind);

	T front();
	T back();
	T at(size_t ind);

	T& operator[](size_t ind);

	size_t length() const;
	bool isEmpty() const;
	void clear();
	void print(char t = ' ') const;
	void print_reverse(char t = ' ') const;

	void clone(const ForwardList<T> l);

	ForwardList<T> operator+(const ForwardList<T>& l);
	ForwardList<T> operator*(const ForwardList<T>& l);

	void operator+=(const ForwardList<T>& l);
	void operator*=(const ForwardList<T>& l);

	bool operator==(const ForwardList<T>& l);
	bool operator!=(const ForwardList<T>& l);

	void sort(bool(*method)(T, T) = asc);
	void reverse();

	//https://en.cppreference.com/w/cpp/container/list/splice
	void splice(const ForwardList<T>& other, size_t pos, size_t count);

};

template<class T>
ForwardList<T>::ForwardList(initializer_list<T> list)
{
	for (T l : list)
	{
		push_back(l);
	}
}

template<class T>
ForwardList<T>::~ForwardList()
{
	this->clear();
}

template<class T>
ForwardList<T>::ForwardList(const ForwardList& l)
{

	Data<T>* temp = l.first;
	while (temp)
	{
		this->push_back(temp->value);
		temp = temp->next;
	}
}

template<class T>
ForwardList<T>& ForwardList<T>::operator=(const ForwardList<T>& l)
{
	if (this == &l)
		return *this;

	this->clear();

	Data<T>* temp = l.first;
	while (temp)
	{
		this->push_back(temp->value);
		temp = temp->next;
	}

	return *this;
}

template<class T>
void ForwardList<T>::push_back(const T& value)
{
	if (size == 0)
	{
		last = new Data<T>;
		last->value = value;
		first = last;
	}
	else
	{
		last->next = new Data<T>;
		last->next->value = value;
		last = last->next;
	}
	size++;
}

template<class T>
void ForwardList<T>::push_front(const T& value)
{
	if (size == 0)
	{
		last = new Data<T>;
		last->value = value;
		first = last;
	}
	else
	{
		Data<T>* temp = new Data<T>;
		temp->value = value;
		temp->next = first;
		first = temp;
	}
	size++;
}

template<class T>
void ForwardList<T>::insert(const T& value, size_t ind)
{
	assert(ind >= 0 && ind <= size);
	if (ind == 0)
	{
		this->push_front(value);
	}
	else if (ind == size)
	{
		this->push_back(value);
	}
	else
	{
		Data<T>* pos = first;
		for (size_t i = 0; i < ind - 1; i++)
		{
			pos = pos->next;
		}
		Data<T>* temp = new Data<T>;
		temp->value = value;
		temp->next = pos->next;
		pos->next = temp;
		size++;
	}
}

template<class T>
void ForwardList<T>::pop_back()
{
	assert(size > 0);
	Data<T>* pos = first;
	for (size_t i = 0; i < size - 2; i++)
	{
		pos = pos->next;
	}
	delete last;
	last = pos;
	size--;
	if (size == 0)
	{
		last = first = nullptr;
	}
	else
	{
		last->next = nullptr;
	}
}

template<class T>
void ForwardList<T>::pop_front()
{
	assert(size > 0);
	Data<T>* temp = first;
	first = first->next;
	delete temp;
	size--;
	if (size == 0)
	{
		last = nullptr;
	}
}

template<class T>
void ForwardList<T>::remove(size_t ind)
{
	assert(ind >= 0 && ind < size);
	if (ind == 0)
	{
		this->pop_front();
	}
	else if (ind == size - 1)
	{
		this->pop_back();
	}
	else
	{
		Data<T>* pos = first;
		for (size_t i = 0; i < ind - 1; i++)
		{
			pos = pos->next;
		}
		Data<T>* temp = pos->next;
		pos->next = pos->next->next;
		delete temp;
		size--;
	}
}

template<class T>
T ForwardList<T>::front()
{
	assert(size > 0);
	return first->value;
}

template<class T>
T ForwardList<T>::back()
{
	assert(size > 0);
	return last->value;
}

template<class T>
T ForwardList<T>::at(size_t ind)
{
	assert(ind >= 0 && ind < size);
	return this->operator[](ind);
}

template<class T>
T& ForwardList<T>::operator[](size_t ind)
{
	assert(ind >= 0 && ind < size);
	Data<T>* pos = first;
	for (size_t i = 0; i < ind; i++)
	{
		pos = pos->next;
	}
	return pos->value;
}

template<class T>
size_t ForwardList<T>::length() const
{
	return size;
}

template<class T>
bool ForwardList<T>::isEmpty() const
{
	return size == 0;
}

template<class T>
void ForwardList<T>::clear()
{
	Data<T>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	last = nullptr;
	size = 0;
}

template<class T>
void ForwardList<T>::print(char t) const
{
	Data<T>* temp = first;
	while (temp)
	{
		cout << temp->value << t;
		temp = temp->next;
	}
	cout << endl;
}

template<class T>
void ForwardList<T>::print_reverse(char t) const
{
	Data<T>* temp = last;
	while (temp)
	{
		cout << temp->value << t;
		temp = temp->prev;
	}
	cout << endl;
}

template<class T>
void ForwardList<T>::clone(const ForwardList<T> l)
{
	*this = l;
}

template<class T>
ForwardList<T> ForwardList<T>::operator+(const ForwardList<T>& l)
{
	Data<T>* temp = l.first;
	while (temp)
	{
		this->push_back(temp->value);
		temp = temp->next;
	}

	return *this;
}

template<class T>
ForwardList<T> ForwardList<T>::operator*(const ForwardList<T>& l)
{





	return ForwardList<T>();
}

template<class T>
void ForwardList<T>::operator+=(const ForwardList<T>& l)
{
	*this = *this + l;
}

template<class T>
void ForwardList<T>::sort(bool(*method)(T, T))
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - 1 - i; j++)
		{
			T& val1 = this->operator[](j);
			T& val2 = this->operator[](j + 1);
			if (method(val1, val2))
			{
				swap(val1, val2);
			}
		}
	}
}

template<class T>
void ForwardList<T>::reverse()
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - 1 - i; j++)
		{
			T& val1 = this->operator[](j);
			T& val2 = this->operator[](j + 1);
			if (val1 < val2)
			{
				swap(val1, val2);
			}
		}
	}
}
