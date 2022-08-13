#include<iostream>
#include<Windows.h>

#include"List.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	List<int> l{ 1,2,3,4,5,6,7 };
	//l.push_back(10);
	//l.push_back(20);
	//l.push_back(30);
	//l.push_front(40);
	//l.push_front(50);
	//l.push_front(60);
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
	std::cout << "Друк списку: \n";
	l.print();
	std::cout << "Друк списку у зворотньому порядку: \n";
	l.print_reverse();
	std::cout << "Розмір списку: " << l.length() << '\n';


	return 0;
}