#include "includes/iter.hpp"
#include <cctype>
#include <iostream>

void test1(int i)
{
	std::cout<< i << std::endl;
}

void test2(char a)
{
	std::cout<< static_cast<char>(std::toupper(a)) <<std::endl;
}

void test3(double d)
{
	static double oldNum = 0.0;
	if (d > oldNum)
		std::cout<< d << std::endl;
	oldNum = d;
}

int main( void ) {
	int arr[3] = {1, 2, 3};
	iter(arr, 3, test1);
	std::cout<<std::endl;
	char arr2[4] = {'m', 'i', 'a', 'o'};
	iter(arr2, 4, test2);
	std::cout<<std::endl;
	double arr3[5] = {1.0, 2.3, 5.6, 2.0, -1.0};
	iter(arr3, 5, test3);
	return 0;
}