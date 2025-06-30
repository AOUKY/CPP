# include "RPN.hpp"

int main(int c, char** v)
{
	if(c < 2){
		std::cerr << "argements ? " << std::endl;
		return 1;
	}
	return RPN(v);
}