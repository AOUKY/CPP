# include "PhoneBook.hpp"

PhoneBook::PhoneBook(){	i = 0; }

bool PhoneBook::valid_names(std::string &s)
{
	size_t i = 0;
	if (s.empty())
        return false;
    while (i < s.size()) 
	{
        if (!std::isspace(s[i++]))
            return true; 
    }
    return false; 
}
bool PhoneBook::valid_phone_number(std::string &s) 
{
    if (s.empty())
        return false;
    if (!(isdigit(s[0]) || s[0] == '+'))
		return false;
    for (size_t i = 1; i < s.size(); ++i) 
	{
        if (!isdigit(s[i]))
            return false; 
    }
    return true;
}

void  PhoneBook::get_info(std::string &str, std::string s, bool switsh)
{
	while (true)
	{
		std::cout<<s;
		std::getline(std::cin, str);
		if(switsh && valid_names(str))
			break;
		else if(!switsh && valid_phone_number(str))
			break;
		else
			std::cout<< "this is not valid"<<std::endl;
	}
}

void PhoneBook::write_10C(const std::string &s) 
{
    size_t len = s.length(); 
    if (len > 10)
        std::cout << s.substr(0, 9) << ".";
	else 
	{
        for (size_t i = len; i < 10; i++) 
            std::cout << ' ';
        std::cout << s;
    }
    std::cout << "|";
}

void  PhoneBook::add()
{
	std::string str;
	std::cout<<"*****************Adding contact******************"<<std::endl;
	get_info(str ,"Enter First name      :",true);
	contact[i].setFName(str);
	get_info(str ,"Enter Last name       :",true);
	contact[i].setLName(str);
	get_info(str ,"Enter Nickname        :",true);
	contact[i].setNickname(str);
	get_info(str,"Enter Phone Number    :",false);
	contact[i].setPhoneN(str);
	get_info(str ,"Enter dark secret     :",true);
	contact[i].setDarkSecret(str);
	contact[i].setContactStatus(true);
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
	if(!contact[i].getContactStatus())
	{
		std::cout <<"ther is no contact right now add some"<< std::endl;
		return (0);
	}
	std::cout<<"  INDEX   |FIRST NAME|LAST NAME | NICKNAME |"<<std::endl;
	std::cout<<"----------|----------|----------|----------|"<<std::endl;
	while (contact[i].getContactStatus() && i < 8)
	{
		std::cout<<"         "<<i + 1<<'|';
		write_10C(contact[i].getFName());
		write_10C(contact[i].getLName());
		write_10C(contact[i].getNickname());
		std::cout<<std::endl;
		i++;
	}
	return (1);
}
void PhoneBook::get_contact_info(int i)
{
	std::cout<<"First Name     : "<<contact[i].getFName()<<std::endl;
	std::cout<<"Last Name      : "<<contact[i].getLName()<<std::endl;
	std::cout<<"NickName       : "<<contact[i].getNickname()<<std::endl;
	std::cout<<"Phone Number   : "<<contact[i].getPhoneN()<<std::endl;
	std::cout<<"Darkest Secret : "<<contact[i].getDarkSecret()<<std::endl;
}
void PhoneBook::search()
{
	std::string s;
	int n;

	n = 0;
	if(!list_contacts())
		return;
	std::cout<<"Enter contact index :";
	while (std::getline(std::cin, s))
	{
		if(valid_phone_number(s))
			n = std::stoi(s);
		if((n > 8 || n < 1) || (!contact[n - 1].getContactStatus()))
			std::cout<<"Not a valid index !!!"<<std::endl;
		else
			break;
		std::cout<<"Enter contact index :";
	}
	get_contact_info(n - 1);
}
