#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>

typedef std::string str;
bool Load_DB(std::map<std::string, float>& data);
void setPrice(char* filename, std::map<std::string, float>& data);

#endif 
