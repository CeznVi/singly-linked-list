#include<iostream>
#include<Windows.h>
#include"ForwardList.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	ForwardList<int> l{ 1,2,3,4,5,6,7 };

	l.push_back(80);
	l.push_back(90);
	l.push_back(100);
	l.push_front(10);
	l.push_front(11);
	l.push_front(12);
	l.print();
	l.insert(99, 2);
	l.print();
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
	std::cout << "Список до сортування: \n";
	l.print();
	l.sort(asc);
	std::cout << "Список після сортування від меньшого до більшого значення: \n";
	l.print();
	l.reverse();
	std::cout << "Список після сортування від більшого до меньшого значення: \n";
	l.print();
	std::cout << "Клонування списку: \n";
	ForwardList<int> l2;
	l2.clone(l);
	l2.print();
	std::cout << "Оператор +  //(l + l2) \n";
	l += l2;
	l.print();



	return 0;
}