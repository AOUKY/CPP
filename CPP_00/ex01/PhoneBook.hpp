#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact contact[8];
	int i;
	bool list_contacts();
	void get_contact_info(int i);
	void  get_info(std::string &str, std::string s , bool switsh);
	bool valid_names(std::string &s);
	bool valid_phone_number(std::string &s);
	void write_10C(const std::string &s);
public:
	PhoneBook();
	void add();
	void search();
};

#endif