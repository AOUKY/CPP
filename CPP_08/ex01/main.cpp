
#include <iostream>
#include <vector>
#include <list>
#include "Span.hpp"

int main() {
     
    std::cout << "===== TEST 1: Basic Functionality =====" << std::endl;
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; 
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;   
    }

    std::cout << "\n===== TEST 2: Edge Cases =====" << std::endl;
    {
        Span sp_empty(0);
        try {
            sp_empty.addNumber(42); 
        } catch (const std::exception& e) {
            std::cerr << "Expected error (empty Span): " << e.what() << std::endl;
        }

        Span sp_single(1);
        sp_single.addNumber(42);
        try {
            std::cout << sp_single.shortestSpan() << std::endl; 
        } catch (const std::exception& e) {
            std::cerr << "Expected error (single element): " << e.what() << std::endl;
        }
    }

    std::cout << "\n===== TEST 3: Range Insertion =====" << std::endl;
    {
        Span sp(10);
        std::vector<int> vec;
        vec.push_back(100);
        vec.push_back(200);
        vec.push_back(300);

        sp.addNumber(vec.begin(), vec.end()); 
        std::cout << "Shortest span after range insert: " << sp.shortestSpan() << std::endl; 
        std::cout << "Longest span after range insert: " << sp.longestSpan() << std::endl;   

        
        std::list<int> lst;
        for (int i = 0; i < 20; ++i) lst.push_back(i);

        try {
            sp.addNumber(lst.begin(), lst.end()); 
        } catch (const std::exception& e) {
            std::cerr << "Expected error : " << e.what() << std::endl;
        }
    }

    std::cout << "\n===== TEST 4: Large Dataset =====" << std::endl;
    {
        Span sp_large(20000);
        std::vector<int> big_vec(20000, 42); 
        big_vec[5000] = 21;                  

        sp_large.addNumber(big_vec.begin(), big_vec.end());
        std::cout << "Shortest span (large dataset): " << sp_large.shortestSpan() << std::endl; 
        std::cout << "Longest span (large dataset): " << sp_large.longestSpan() << std::endl;   
    }


    return 0;
}