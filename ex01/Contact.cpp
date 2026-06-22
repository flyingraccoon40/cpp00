#include "Contact.hpp"

Contact::Contact() : _firstName(""), _lastName(""),
                    _nickName(""), _phoneNumber(""),
                    _darkestSecret("")
{

}
Contact::~Contact()
{
}

std::string Contact::getFirstName(){
    return this->_firstName;
}

void Contact::setFirstName(std::string string)
{
 this->_firstName = string;
}

std::string Contact::getLastName(){
    return this->_lastName;
}

void Contact::setLastName(std::string string){
    this->_lastName = string;
}

std::string Contact::getNickName(){
    return this->_nickName;
}

void Contact::setNickName(std::string string){
    this->_nickName = string;
}

std::string Contact::getPhoneNumber(){
    return this->_phoneNumber;
}

void Contact::setPhoneNumber(std::string numbeer){
    this->_phoneNumber = numbeer;
}

std::string Contact::getDarkestSecret(){
    return this->_darkestSecret;
}

void Contact::setDarkestSecret(std::string secret){
    this->_darkestSecret = secret;
}
