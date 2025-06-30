# include "RPN.hpp"
# include <stack>

bool isOperator(char c)
{
	if(c == '*' || c == '-' || c == '/' |c == '+')
		return 1;
	return 0;
}

bool makeOperator(std::stack<double>& s, char c)
{
	int a = s.top();
	s.pop();
	if(!s.size()){
		std::cerr << "Error" << std::endl;
		return 1;
	}
	else if(c == '-')
		s.top() = s.top() - a;
	else if(c == '+')
		s.top() = s.top() + a;
	else if(c == '*')
		s.top() = s.top() * a;
	else if(c == '/' && a != 0)
		s.top() = s.top() / a;
	else if(a == 0){
		std::cerr << "Error: Division by zero" << std::endl; 
		return 1;
	}
	return 0;
}

bool RPN(char** arr)
{
	std::stack<double> s;
	for(int i = 1; arr[i]; i++){
		std::string arg(arr[i]);
		for(size_t i = 0; i < arg.length(); i++){
			if(arg[i] == ' ')
				continue;
			else if(std::isdigit(arg[i]))
				s.push(arg[i] - '0'); 
			else if(isOperator(arg[i])){
				if(makeOperator(s, arg[i]))
					return 1;
			}
			else{
				std::cerr << "Error" << std::endl;
				return 1; 
			}
		}
	}
	if(s.size() != 1) {
		std::cerr << "Error: Invalid operation" << std::endl; 
		return 1;
	}
	std::cout << s.top() << std::endl;
	return 0;
}
























