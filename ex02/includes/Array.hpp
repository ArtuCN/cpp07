#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T> 

class Array
{
	private:
		T *_array;
		unsigned int _size;
	public:
		Array() : _array(NULL), _size(0) {};
		
		Array(unsigned int size) : _array(new T[size]), _size(size) {};
		
		Array(const Array &a) { _size(a._size); _array(new T[_size]);
			for(unsigned int i = 0; i < _size; i++) 
			{_array[i] = a._array[i]; }};
		
		T& operator=(const Array<T>&a) { if (this != *a) {
			if (_array) { delete _array; }
			_array = new T[a._size]; _size = a._size;
			if (a._array) { for (unsigned int i = 0; i < a._size; i++) { _array[i] = a._array[i]; }}
			else { _size = 0; _array = NULL; } }
			return *this; }
		
		class IndexOutOfBound : public std::exception {
			public: virtual const char* what() const throw()
			{
				return "Index out of bonds!\n";
			}
		};

		T& operator[](unsigned int n) { if (n >= _size) { throw IndexOutOfBound(); } return _array[n]; };

		unsigned int getSize() {return _size;};

		~Array() { if (_array) {delete _array; } };

};
#endif