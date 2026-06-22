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

    std::cout << B_GREEN"Hello user, welcome to PhoneBook !" RESET << std::endl;
    std::cout << B_YELLOW"Enter a command: 'ADD', 'SEARCH', 'EXIT'." RESET << std::endl;
    std::cout<< B_BLUE;
    if (!std::getline(std::cin, inputCmd))
        return 0;
    // std::cout<< RESET;
    

    while(1)
    {
        if(inputCmd == "ADD")
        {
            std::cout<< B_BLUE;
            Contact newcontact;
            if (!readField(B_WHITE "First Name: " B_BLUE, inputContact))
                return (0);
            newcontact.setFirstName(inputContact);
            if (!readField(B_WHITE"Last Name: " B_BLUE, inputContact))
                return (0);
            newcontact.setLastName(inputContact);
            if (!readField(B_WHITE"NickName: " B_BLUE, inputContact))
                return (0);
            newcontact.setNickName(inputContact);
            if (!readField(B_WHITE"Phone Number: " B_BLUE, inputContact))
                return (0);
            newcontact.setPhoneNumber(inputContact);
            if (!readField(B_WHITE"Darkest Secret: " B_BLUE, inputContact))
                return (0);
            newcontact.setDarkestSecret(inputContact);
            phonebook.addContact(newcontact);
            if (!std::getline(std::cin, inputCmd))
            {
                std::cout<< RESET;
                return 0;

            }
        }
        else if (inputCmd == "SEARCH")
        {
            std::cout<< BGHI_GREEN;
            std::cout << std::setw(10) << "Index" << "|"
                      << std::setw(10) << "First Name" << "|"
                      << std::setw(10) << "Last Name" << "|"
                      << std::setw(10) << "NickName" <<std::endl;  
            std::cout<< RESET;             
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
        else if (inputCmd == "EXIT")
            return 1;

        else
        std::cout<< B_RED;
        std::cout << "invalid command: 'ADD', 'SEARCH', 'EXIT'." << std::endl;
        if (!std::getline(std::cin, inputCmd))
            return 0;
        std::cout<< RESET;
    }
}

