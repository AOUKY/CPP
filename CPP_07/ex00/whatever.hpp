#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b)
{
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T& min(T& a, T& b)
{
	if(b <= a)
		return b;
	return a;
}

template <typename T>
T& max(T& a, T& b)
{
	if(b >= a)
		return b;
	return a;
}

#endif
