#include "PhoneBook.hpp"

PhoneBook::PhoneBook () : _count(0), _index(0)
{

}

PhoneBook::~PhoneBook() {

 std::cout << "\nGOOD BYE USER ..BOOP ..BOOP!" << std::endl;
}

void PhoneBook::addContact(Contact newc)
{
    this->_contact[this->_index] = newc;
    this->_index = (this->_index + 1) % 8;
    
    if (this->_count < 8)
    this->_count++;
    std::cout << U_GREEN"A new contact has been added" RESET<< std::endl;
    std::cout << B_YELLOW"Enter a command: 'ADD', 'SEARCH', 'EXIT'." RESET<< std::endl;

}

Contact PhoneBook::getContact(int index) const
{
    return(_contact[index]);
}

int PhoneBook::getCount(){
    return this->_count;
}

void PhoneBook::printContact(int index)const 
{
    Contact a = this->_contact[index];

    std::cout << "First Name: " << a.getFirstName() << std::endl;
    std::cout << "Last Name: " << a.getLastName() << std::endl;
    std::cout << "NickName: " << a.getNickName() << std::endl;
    std::cout << "Phone Number: " << a.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << a.getDarkestSecret() << std::endl;
}



