# ifndef CONTACT_HPP
# define  CONTACT_HPP
#include <iostream>

class Contact {
public:
    Contact();
    ~Contact();
    std::string getFirstName();
    std::string getLastName();
    std::string getNickName();
    std::string getPhoneNumber();
    std::string getDarkestSecret();

    void setFirstName(std::string);
    void setLastName(std::string);
    void setNickName(std::string);
    void setPhoneNumber(std::string);
    void setDarkestSecret(std::string);

private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkestSecret;

};

#endif



