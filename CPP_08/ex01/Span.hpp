#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

#define PRINT 0

class Span {
private:
	unsigned int N;
	std::vector<int> nbrs;
public:
	Span();
	Span(unsigned int N);

	Span(const Span& other);
	Span& operator=(const Span& other);

	void addNumber(int n);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	template <typename Iterator>
	void addNumber(Iterator begin, Iterator end); 

	~Span();

};


template <typename Iterator>
void Span::addNumber(Iterator begin, Iterator end) {
    for (Iterator it = begin; it != end; ++it) {
        if (nbrs.size() >= N) {
            throw std::out_of_range("Span is full");
        }
        nbrs.push_back(*it);
    }
}

#endif
