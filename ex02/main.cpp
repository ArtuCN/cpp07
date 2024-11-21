#include "includes/Array.hpp"
#include <exception>

int main()
{
	Array<double> arr1;
	Array<int> arr2(5);
	Array<double> arr3(3);
	arr3[0] = 5;
	arr3[1] = 1.1;
	arr3[2] = 0;
	std::cout<< arr3.getSize() << "\n";
	try
	{
		std::cout<< arr3[2]<< "\n";
	}
	catch(std::exception &e)
	{
		std::cout<<e.what();
	}
	try
	{
		std::cout<< arr3[4]<< "\n";
	}
	catch(std::exception &e)
	{
		std::cout<<e.what();
	}
	Array<double> arr4(arr3);
	Array<double> arr5 = arr3;
}