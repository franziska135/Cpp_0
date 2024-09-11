/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:28:47 by fmarggra          #+#    #+#             */
/*   Updated: 2024/06/19 16:53:24 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

//error check for adding a contact to the phone book
void    Contact::inputCheck(int operation, std::string &member) {
    if (std::cin.eof()) {
        std::cout << "EXIT" << std::endl;
        exit (1);
    }
    if (operation == SINGLE) {
        while (member.empty()) {
            std::cout << "Error " << member << "cannot be empty, enter again: ";
            std::getline(std::cin, member);
        }
    }
    else if (operation == DOUBLE) {
        while (!isNum(this->_phoneNumber) || this->_phoneNumber.empty()) {
            if (this->_phoneNumber.empty()) {
                std::cout << "ERROR: Phone number cannot be empty, enter again: ";
            }
            else if (!isNum(this->_phoneNumber)) {
                std::cout << "ERROR: Invalid phone number, enter a numeric value: ";
                std::cin.clear();
            }
            std::getline(std::cin, this->_phoneNumber);
        }
    }
}

std::string Contact::getMember(std::string member) {
    if (member == "fn")
        return _firstName;
    else if (member == "ln")
        return _lastName;
    else if (member == "nn")
        return _nickName;
    else if (member == "ds")
        return _darkestSecret;
    return _phoneNumber;
}

//prints all contacts (except phone nbr and darkest secret)
void    PhoneBook::printContacts(void) {
    std::cout << "____________________________________________________\n" << std::endl;
    std::cout << std::setw(10) << "#" << "|";
    std::cout << std::setw(10) << "first name" << "|";
    std::cout << std::setw(10) << "last name" << "|";
    std::cout << std::setw(10) << "nick name" << std::endl;
    std::cout << "............................................" << std::endl;
    for (int i = 0; i < this->_numContacts; i++) {
        std::cout << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << format(_contacts[i].getMember("fn")) << "|";
        std::cout << std::setw(10) << format(_contacts[i].getMember("ln")) << "|";
        std::cout << std::setw(10) << format(_contacts[i].getMember("nn")) << std::endl;
    }
    std::cout << "____________________________________________________\n" << std::endl;
}

//prints all details of a single contact
void    Contact::printContact(int index) {
    std::cout << std::left << std::setw(15) << "#" << "|  " << index << std::endl;
    std::cout << std::left << std::setw(15) << "first name:" << "|  " << _firstName << std::endl;
    std::cout << std::left << std::setw(15) << "last name:" << "|  " << _lastName << std::endl;
    std::cout << std::left << std::setw(15) << "phone number:" << "|  " << _phoneNumber << std::endl;
    std::cout << std::left << std::setw(15) << "darkest secret:" << "|  " << _darkestSecret << std::endl;
}

//adds a contact to the phone book
void    PhoneBook::addContact(void) {
    this->_contacts[this->_index % 8].setContact();
    this->_index++;
    if (this->_numContacts < 8)
        this->_numContacts++;
}

//adds a contact information to contact in phone book
void    Contact::setContact(void) {
    std::cout << "____________________________________________________\n" << std::endl;
    std::cin.clear();
    std::cin.ignore(200, '\n');

    std::cout << "enter first name: ";
    std::getline(std::cin, this->_firstName);
    Contact::inputCheck(SINGLE, this->_firstName);

    std::cout << "enter last name: ";
    std::getline(std::cin, this->_lastName);
    Contact::inputCheck(SINGLE, this->_lastName);

    std::cout << "enter nick name: ";
    std::getline(std::cin, this->_nickName);
    Contact::inputCheck(SINGLE, this->_nickName);

    std::cout << "enter phone number: ";
    std::getline(std::cin, this->_phoneNumber);
    Contact::inputCheck(DOUBLE, this->_nickName);

    std::cout << "enter darkest secret: ";
    std::getline(std::cin, this->_darkestSecret);
    Contact::inputCheck(SINGLE, this->_darkestSecret);
    std::cout << "\ncontact added!" << std::endl;
    std::cout << "____________________________________________________\n" << std::endl;
}

//searches for a contact in the phone book
void    PhoneBook::searchContacts(void) {
    printContacts();

    std::cout << "enter number of contact you are looking for: ";
    int index;
    while (!(std::cin >> index)) {
        if (std::cin.eof()) {
            std::cout << "EXIT" << std::endl;
            exit(1);
        }
        std::cout << "ERROR: Invalid input. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(200, '\n');
    }
    std::cout << "____________________________________________________\n" << std::endl;
    if (index < 9 && index > 0 && index <= this->_numContacts)
        this->_contacts[index - 1].printContact(index);
    else if (index > 8 || index < 1)
        std::cout << "ERROR: nbr out of bound for this phone book" << std::endl;
    else
        std::cout << "ERROR: no contact for this number" << std::endl;
    std::cout << "____________________________________________________\n" << std::endl;
}
