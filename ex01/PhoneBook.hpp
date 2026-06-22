#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include "color.hpp"
#include <cstdlib>

class PhoneBook{
    public:
    PhoneBook();
    ~PhoneBook();
    void addContact(Contact newc);
    int  getCount();
    Contact getContact(int index) const;
    void  printContact(int index) const;
    
    private:
    Contact _contact[8];
    int _count;
    int _index;
    
};

#endif



