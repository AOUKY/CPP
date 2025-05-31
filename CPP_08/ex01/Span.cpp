# include "Span.hpp"

# include <iostream>
# include <algorithm>

Span::Span() : N(0) {
	if(PRINT)
		std::cout << "Defatult constructer called" << std::endl;
}
Span::Span(unsigned int N) : N(N) {
	if(PRINT)
		std::cout << "constructer called" << std::endl;
}
Span::Span(const Span& other) : N(other.N) , nbrs(other.nbrs) {}
Span& Span::operator=(const Span& other)
{
	if(this != &other)
	{
		N = other.N;
		nbrs = other.nbrs;
	}
	return *this;
}

Span::~Span() {	
	if(PRINT)
		std::cout << "destructer called" << std::endl;}


void Span::addNumber(int n)
{
	if(nbrs.size() == N)
		throw std::out_of_range("Span is full");
	nbrs.push_back(n);
}

unsigned int Span::shortestSpan() const
{
	if (nbrs.size() < 2)
        throw std::logic_error("Not enough elements");
	std::vector<int> tmp(nbrs);
    std::sort(tmp.begin(), tmp.end());
    int min_diff = tmp[1] - tmp[0];
    for (size_t i = 2; i < tmp.size(); ++i) {
        int diff = tmp[i] - tmp[i - 1];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
    return min_diff;
}

unsigned int Span::longestSpan() const
{
	if (nbrs.size() < 2) 
        throw std::logic_error("Not enough elements");
    std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> minmax = 
        std::minmax_element(nbrs.begin(), nbrs.end());
    return *minmax.second - *minmax.first;
}


