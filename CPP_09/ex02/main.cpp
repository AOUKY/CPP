# include "PmergeMe.hpp"

int main(int c ,char **v)
{
	if(c < 2){
		std::cerr << "nbrs ?" << std::endl;
		return 1;
	}
	PmergeMe(v);
}

