/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:49:06 by fmarggra          #+#    #+#             */
/*   Updated: 2024/06/19 16:53:38 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>

#define SINGLE 0
#define DOUBLE 1

class Contact
{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _darkestSecret;
        std::string _phoneNumber;
   
    public:
        Contact();
        void        setContact(void);
        std::string getMember(std::string member);
        void        printContact(int index);
        void        inputCheck(int operation, std::string &member);
};

class PhoneBook
{
    private:
        Contact _contacts[8];
        int     _numContacts;
        int     _index;

    public:
        PhoneBook();
        void        addContact(void);
        void        searchContacts(void);
        void        printContacts(void);
};

int         main();
bool        isNum(std::string number);
std::string format(std::string member);
void        errorMessage(std::string input);

#endif
