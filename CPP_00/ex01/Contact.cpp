#include "Contact.hpp"

Contact::Contact() : full(false) {}

void Contact::setFName( std::string firstName) { fname = firstName; }
void Contact::setLName( std::string lastName) { lname = lastName; }
void Contact::setNickname( std::string nick) { nickname = nick; }
void Contact::setPhoneN( std::string phone) { phone_n = phone; }
void Contact::setDarkSecret( std::string secret) { dark_secret = secret; }
void Contact::setContactStatus(bool value) { full = value; }

std::string Contact::getFName()  { return fname; }
std::string Contact::getLName()  { return lname; }
std::string Contact::getNickname()  { return nickname; }
std::string Contact::getPhoneN()  { return phone_n; }
std::string Contact::getDarkSecret()  { return dark_secret; }
bool Contact::getContactStatus()  { return full; }