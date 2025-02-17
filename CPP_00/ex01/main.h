#ifndef MAIN_H
#define MAIN_H

#include "PhoneBook.hpp"

void  get_info(std::string &str, std::string s,bool (*valid)(const char *));
bool valid_names(const char *s);
bool valid_phone_number(const char *s);
void write_10C(std::string &s);
#endif