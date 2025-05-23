# include "PhoneBook.hpp"

void start()
{
	std::cout<<"===================PhoneBook==================="<<std::endl;
	std::cout<<"===> Commands  :"<<std::endl;
	std::cout<<"      * ADD    : save a new contact."<<std::endl;
	std::cout<<"      * SEARCH : display a specific contact."<<std::endl;
	std::cout<<"      *  EXIT  : exiting the program and all the contacts are lost forever!"<<std::endl;
	std::cout<<"==============================================="<<std::endl;

}

int main()
{
	PhoneBook  book;
	std::string str;
	start();
	std::cout<< ">";
	while(std::getline(std::cin, str))
	{
		if(!str.compare("ADD"))
			book.add();
		else if(!str.compare("SEARCH"))
			book.search();
		else if(!str.compare("EXIT"))
		{
			std::cout<<"All the contacts are lost forever"<<std::endl;
			exit(0);
		}
		else
			std::cout<<"Command not found. Please enter a valid command (ADD, SEARCH, EXIT)"<<std::endl;
		std::cout<< ">";
	}
}
