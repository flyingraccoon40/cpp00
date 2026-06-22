#include "PhoneBook.hpp"



std::string truncate(std::string str){
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return (str);
}

bool readField(std::string const &field, std::string &dest){
    std::cout << field;
    if (!std::getline(std::cin, dest))
        return false;
    while (dest == ""){
        std::cout << field;
                if (!std::getline(std::cin, dest))
                    return false;
    }
    return true;
}

int main(void)
{
    PhoneBook phonebook;
    std::string inputCmd;
    std::string inputContact;


    std::cout << "Hello user, welcome to PhoneBook !" << std::endl;
    std::cout << "Available commands : 'ADD', 'SEARCH', 'EXIT'." << std::endl;
    if (!std::getline(std::cin, inputCmd))
        return 0;

    while(inputCmd != "EXIT")
    {
        if(inputCmd == "ADD")
        {
            Contact newcontact;
            if (!readField("First Name: ", inputContact))
                return (0);
            newcontact.setFirstName(inputContact);
            if (!readField("Last Name: ", inputContact))
                return (0);
            newcontact.setLastName(inputContact);
            if (!readField("NickName: ", inputContact))
                return (0);
            newcontact.setNickName(inputContact);
            if (!readField("Phone Number: ", inputContact))
                return (0);
            newcontact.setPhoneNumber(inputContact);
            if (!readField("Darkest Secret: ", inputContact))
                return (0);
            newcontact.setDarkestSecret(inputContact);
            phonebook.addContact(newcontact);
        }
        else if (inputCmd == "SEARCH")
        {
            std::cout << std::setw(10) << "Index" << "|"
                      << std::setw(10) << "First Name" << "|"
                      << std::setw(10) << "Last Name" << "|"
                      << std::setw(10) << "NickName" << std::endl;               
            for (int i = 0; i < phonebook.getCount(); i++){
                std::cout << std::setw(10) << i << "|";
                std::cout << std::setw(10) << truncate(phonebook.getContact(i).getFirstName()) << "|";
                std::cout << std::setw(10) << truncate(phonebook.getContact(i).getLastName()) << "|";
                std::cout << std::setw(10) << truncate(phonebook.getContact(i).getNickName()) << std::endl;
            }
            std::cout << "Choose an index: ";
            if (!std::getline(std::cin, inputContact))
                return 0;
            int index = atoi(inputContact.c_str());

            bool is_valid = !inputContact.empty();
            for (size_t i =0; i < inputContact.length(); i++) {
                if(!isdigit(inputContact[i])){
                    is_valid = false;
                    break;
                }
            }
            if (is_valid == false || index >= phonebook.getCount()){
                std::cout << "Try again with a valid index" << std::endl;
            }
            else {
                phonebook.printContact(index);
            }

            

        }
        if (!std::getline(std::cin, inputCmd))
            return 0;
    }
}

