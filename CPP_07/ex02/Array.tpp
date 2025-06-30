#ifndef ARRAY_TPP
# define ARRAY_TPP

#include <iostream>

template <typename T>
Array<T>::Array() : elements(0), _size(0) {}


template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]()), _size(n) {}


template <typename T>
Array<T>::Array(const Array& other) : elements(new T[other._size]), _size(other._size) {
    for (size_t i = 0; i < _size; ++i)
        elements[i] = other.elements[i];
}


template <typename T>
Array<T>::~Array() {
    delete[] elements;
}


template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] elements;
        _size = other._size;
        elements = new T[_size];
        for (int i = 0; i < _size; ++i)
            elements[i] = other.elements[i];
    }
    return *this;
}


template <typename T>
T& Array<T>::operator[](unsigned int n) {
    if (n >= _size) 
        throw std::out_of_range("Index out of bounds");
    return elements[n];
}

template <typename T>
const T& Array<T>::operator[](unsigned int n) const {
    if (n >= _size) 
        throw std::out_of_range("Index out of bounds");
    return elements[n];
}


template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

#endif 