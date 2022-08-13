﻿#pragma once

#include"Data.h"
#include<initializer_list>
#include<cassert>
#include"Func.h"

template<class T>
class List
{
	Data<T>* first = nullptr;
	Data<T>* last = nullptr;
	size_t   size = 0;
	Data<T>* find(size_t ind);

public:
	List() {	}
	List(initializer_list<T> list);
	~List();
	//Конструктор копіювання
	List(const List& l);
	//оператор присвоєння
	List<T>& operator=(const List<T>& l);

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

	//todo
	List<T> operator+(const List<T>& l);
	List<T> operator*(const List<T>& l);
	void operator+=(const List<T>& l);
	void operator*=(const List<T>& l);

	bool operator==(const List<T>& l);
	bool operator!=(const List<T>& l);

	void sort(bool(*method)(T, T) = asc);
	void reverse();

	void splice(const List<T>& other, size_t pos, size_t count);
};

template<class T>
Data<T>* List<T>::find(size_t ind)
{
	Data<T>* pos;
	if (ind <= size / 2)
	{
		pos = first;
		for (size_t i = 0; i < ind - 1; i++)
		{
			pos = pos->next;
		}
	}
	else
	{
		pos = last;
		for (size_t i = 0; i < size - ind; i++)
		{
			pos = pos->prev;
		}
	}
	return pos;
}

template<class T>
List<T>::List(initializer_list<T> list)
{
	for (T l : list)
	{
		push_back(l);
	}
}

template<class T>
List<T>::~List()
{
	this->clear();
}

template<class T>
void List<T>::push_back(const T& value)
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
		last->next->prev = last;
		last = last->next;
	}
	size++;
}

template<class T>
void List<T>::push_front(const T& value)
{
	if (size == 0)
	{
		last = new Data<T>;
		last->value = value;
		first = last;
	}
	else
	{
		first->prev = new Data<T>;
		first->prev->value = value;
		first->prev->next = first;
		first = first->prev;
	}
	size++;
}

template<class T>
void List<T>::insert(const T& value, size_t ind)
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
		Data<T>* pos = find(ind);
		Data<T>* temp = new Data<T>;
		temp->value = value;
		temp->next = pos->next;
		temp->next->prev = temp;
		pos->next = temp;
		temp->prev = pos;
	}
}

template<class T>
void List<T>::pop_back()
{
	assert(size > 0);
	if (size == 1)
	{
		delete last;
		last = first = nullptr;
	}
	else
	{
		last = last->prev;
		delete last->next;
		last->next = nullptr;
	}
	size--;
}

template<class T>
void List<T>::pop_front()
{
	assert(size > 0);
	if (size == 1)
	{
		delete first;
		first = last = nullptr;
	}
	else
	{
		first = first->next;
		delete first->prev;
		first->prev = nullptr;
	}
}

template<class T>
void List<T>::remove(size_t ind)
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
		Data<T>* pos = find(ind + 1);
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		delete pos;
		size--;
	}
}

template<class T>
T List<T>::front()
{
	assert(size > 0);
	return first->value;
}

template<class T>
T List<T>::back()
{
	assert(size > 0);
	return last->value;
}

template<class T>
T List<T>::at(size_t ind)
{
	return this->operator[](ind);
}

template<class T>
T& List<T>::operator[](size_t ind)
{
	assert(ind >= 0 && ind < size);
	return find(ind + 1)->value;
}

template<class T>
size_t List<T>::length() const
{
	return size;
}

template<class T>
bool List<T>::isEmpty() const
{
	return size == 0;
}

template<class T>
void List<T>::clear()
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
void List<T>::print(char t) const
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
void List<T>::print_reverse(char t) const
{
	Data<T>* temp = last;
	while (temp)
	{
		cout << temp->value << t;
		temp = temp->prev;
	}
	cout << endl;
}
