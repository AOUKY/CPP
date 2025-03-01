#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
private:
    std::string fname;
    std::string lname;
    std::string nickname;
    std::string phone_n;
    std::string dark_secret;
    bool full;

public:
    Contact();

    void setFName( std::string firstName);
    void setLName( std::string lastName);
    void setNickname( std::string nick);
    void setPhoneN( std::string  );
    void setDarkSecret( std::string secret);
    void setContactStatus(bool value);

    std::string getFName() ;
    std::string getLName() ;
    std::string getNickname() ;
    std::string getPhoneN() ;
    std::string getDarkSecret() ;
    bool getContactStatus() ;
};

#endif