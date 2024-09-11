/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:28:47 by fmarggra          #+#    #+#             */
/*   Updated: 2024/06/19 16:52:58 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main() {
    PhoneBook PhoneBook;
    Contact Contact;
    std::string input;

    while (1) {
        //no endl here
        std::cout << "enter your promt: ";
        std::cin >> input;
        if (input == "EXIT")
            break ;
        else if (std::cin.eof()) {
            std::cout << "EXIT" << std::endl;
            break ;
        }
        else if (input == "SEARCH")
            PhoneBook.searchContacts();
        else if (input == "ADD")
            PhoneBook.addContact();
        else
            errorMessage(input);
    }
    return (0);
}
