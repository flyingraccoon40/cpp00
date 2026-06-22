#include "PhoneBook.hpp"



std::string truncate(std::string str){
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return (str);
}

// bool reader(std::string inputContact, std::string &dest){

// }

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

            std::cout << "First Name: ";
            if (!std::getline(std::cin, inputContact))
                return 0;
            while (inputContact == ""){
                std::cout << "First Name: ";
                if(!std::getline(std::cin, inputContact))
                    return 0;
            }
            newcontact.setFirstName(inputContact);

            std::cout <<"Last Name: ";
            if (!std::getline(std::cin, inputContact))
                return 0;
            while (inputContact == ""){
                std::cout << "Last Name: ";
                if (!std::getline(std::cin, inputContact))
                    return 0;
            }
            newcontact.setLastName(inputContact);

            std::cout <<"NickName: ";
            if (!std::getline(std::cin, inputContact))
                return(0);
            while (inputContact == ""){
                std::cout << "Nick Name: ";
                if (!std::getline(std::cin, inputContact))
                    return 0;
            }
            newcontact.setNickName(inputContact);

            std::cout << "Phone Number: ";
            if (!std::getline(std::cin, inputContact))
                return 0;
            while (inputContact == ""){
                std::cout << "Phone Number: ";
                if (!std::getline(std::cin, inputContact))
                    return 0;
            }
            newcontact.setPhoneNumber(inputContact);

            std::cout << "Darkest secret: ";
            if (!std::getline(std::cin, inputContact))
                return 0;
            while (inputContact == ""){
                std::cout << "Darkest secret: ";
                if (!std::getline(std::cin, inputContact))
                    return 0;
            }
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

