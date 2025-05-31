#ifndef ARRAY_HPP
#define ARRAY_HPP



template <typename T>

class Array{
private:
	T* elements;
	unsigned int _size;

public:
	Array();
	Array(const Array& other);
	Array(unsigned int n);
	Array& operator=(const Array& other);
	T& operator[](unsigned int n);
	const T& operator[](unsigned int n) const;

	unsigned int size() const;

	~Array();
};

#include "Array.tpp"


#endif
