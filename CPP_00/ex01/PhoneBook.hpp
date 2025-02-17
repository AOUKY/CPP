#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact contact[8];
	int i;
public:
	PhoneBook();
	void add();
	void search();
	bool list_contacts();
	void get_contact_info(int i);
};

#endif