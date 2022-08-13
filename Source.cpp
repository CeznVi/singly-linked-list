#include<iostream>
#include<Windows.h>

#include"List.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	

	List<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_front(40);
	l.push_front(50);
	l.push_front(60);
	l.print();
	l.insert(99, 2);
	l.print();
	//l.sort(desc);
	//l.print();
	l.pop_back();
	l.pop_front();
	l.print();
	l.remove(2);
	l.print();
	l[2] = 88;
	l.print();

	return 0;
}