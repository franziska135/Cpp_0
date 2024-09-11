/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarggra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:28:47 by fmarggra          #+#    #+#             */
/*   Updated: 2024/06/19 16:54:12 by fmarggra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

bool    isNum(std::string number) {
    for (int i = 0; number[i]; i++) {
        if (number[i] < 48 || number[i] > 57)
            return false;
    }
    return true;
}
std::string format(std::string member) {
    if (member.length() > 10)
        return member.substr(0, 9) + ".";
    else
        return member;
}

void    errorMessage(std::string input) {
    if (input == "add")
        std::cout << "ERROR: did you mean 'ADD'?" << std::endl;
    else if (input == "search")
        std::cout << "ERROR: did you mean 'search'?" << std::endl;
    else if (input == "exit")
        std::cout << "ERROR: did you mean 'EXIT'?" << std::endl;
    else {
        std::cout << "____________________________________________________\n" << std::endl;
        std::cout << "ADD: add a contact to your phone book" << std::endl;
        std::cout << "SEARCH: search a contact in your phone book" << std::endl;
        std::cout << "EXIT: exits the phone book\n" << std::endl;
        std::cout << "Attention, the phone book can only store 8 contacts\n" <<
                        "more contacts will replace previous ones" << std::endl;
        std::cout << "____________________________________________________\n" << std::endl;
    }
}
