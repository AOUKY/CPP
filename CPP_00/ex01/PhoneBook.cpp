# include "main.h"

PhoneBook::PhoneBook()
{
	i = 0;
}

void  PhoneBook::add()
{
	std::string str;
	std::cout<<"*****************Adding contact******************"<<std::endl;
	get_info(str ,"Enter First name      :",valid_names);
	contact[i].fname = str;
	get_info(str ,"Enter Last name       :",valid_names);
	contact[i].lname = str;
	get_info(str ,"Enter Nickname        :",valid_names);
	contact[i].nickname = str;
	get_info(str,"Enter Phone Number    :",valid_phone_number);
	contact[i].phone_n = str;
	get_info(str ,"Enter dark secret     :",valid_names);
	contact[i].dark_secret = str;
	contact[i].full = true;
	std::cout << "Contact added successfully!" << std::endl;
	if(i == 7)
		i = 0;
	else
		i++;
}

bool  PhoneBook::list_contacts()
{
	int i;

	i = 0;
	if(!contact[i].full)
	{
		std::cout <<"ther is no contact right now add some"<< std::endl;
		return (0);
	}
	std::cout<<"  INDEX   |FIRST NAME|LAST NAME | NICKNAME |"<<std::endl;
	std::cout<<"----------|----------|----------|----------|"<<std::endl;
	while (contact[i].full && i < 8)
	{
		std::cout<<"         "<<i + 1<<'|';
		write_10C(contact[i].fname);
		write_10C(contact[i].lname);
		write_10C(contact[i].nickname);
		std::cout<<std::endl;
		i++;
	}
	return (1);
}
void PhoneBook::get_contact_info(int i)
{
	std::cout<<"First Name     : "<<contact[i].fname<<std::endl;
	std::cout<<"Last Name      : "<<contact[i].lname<<std::endl;
	std::cout<<"NickName       : "<<contact[i].nickname<<std::endl;
	std::cout<<"Phone Number   : "<<contact[i].phone_n<<std::endl;
	std::cout<<"Darkest Secret : "<<contact[i].dark_secret<<std::endl;
}
void PhoneBook::search()
{
	std::string s;
	int n;

	if(!list_contacts())
		return;
	while (true)
	{
		std::cout<<"Enter contact index :";
		std::getline(std::cin, s);
		n = std::atoi(s.c_str());
		if((n > 8 || n < 1) || (!contact[n - 1].full))
			std::cout<<"Not a valid index !!!"<<std::endl;
		else
			break;
	}
	get_contact_info(n - 1);
}
