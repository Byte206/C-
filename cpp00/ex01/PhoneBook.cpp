/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamorcil <gamorcil@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:26:54 by gamorcil          #+#    #+#             */
/*   Updated: 2026/01/26 08:26:55 by gamorcil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <stdlib.h>

PhoneBook::PhoneBook() : contactCount(0), _index(0) {}

std::string get_input(std::string prompt) {
    std::string input;
    while (true) {
        if (std::cin.eof())
            exit(0);
        std::cout << prompt;
        if (!std::getline(std::cin, input))
        {
            std::cout << "\nExiting PhoneBook. Goodbye!" << std::endl;
            exit(0);
        }
        if (!input.empty()) {
            bool all_spaces = true;
            for (size_t i = 0; i < input.length(); i++) {
                if (!std::isspace(input[i])) {
                    all_spaces = false;
                    break;
                }
            }
            if (!all_spaces)
                return input;
        }
        std::cout << "Field cannot be empty. Please try again." << std::endl;
    }
}

void PhoneBook::addContact()
{
    Contact newContact;

    newContact.setFirstName(get_input("Enter First Name: "));
    newContact.setLastName(get_input("Enter Last Name: "));
    newContact.setNickname(get_input("Enter Nickname: "));

    while (true)
    {
        std::string input = get_input("Enter Phone Number: ");
        bool is_valid = true;
        for (size_t i = 0; i < input.length(); i++)
        {
            if (!std::isdigit(input[i]))
            {
                is_valid = false;
                break;
            }
        }
        if (is_valid)
        {
            newContact.setPhoneNumber(input);
            break;
        }
        std::cout << "Invalid phone number. Digits only." << std::endl;
    }

    newContact.setDarkestSecret(get_input("Enter Darkest Secret: "));

    contacts[_index % MAX_CONTACTS] = newContact;
    _index++;
    if (contactCount < MAX_CONTACTS)
        contactCount++;
    
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContacts() const
{
    if (contactCount == 0)
    {
        std::cout << "No contacts available." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    for (int i = 0; i < contactCount; i++)
    {
        std::cout << std::setw(10) << i + 1 << "|"
                  << std::setw(10) << (contacts[i].getFirstName().length() > 10 ? contacts[i].getFirstName().substr(0, 9) + "." : contacts[i].getFirstName()) << "|"
                  << std::setw(10) << (contacts[i].getLastName().length() > 10 ? contacts[i].getLastName().substr(0, 9) + "." : contacts[i].getLastName()) << "|"
                  << std::setw(10) << (contacts[i].getNickname().length() > 10 ? contacts[i].getNickname().substr(0, 9) + "." : contacts[i].getNickname()) << std::endl;
    }

    std::string input = get_input("Enter the index of the contact to view details: ");
    
    // Verificar si es un número
    bool is_num = true;
    for (size_t i = 0; i < input.length(); i++) {
        if (!std::isdigit(input[i])) {
            is_num = false;
            break;
        }
    }

    if (!is_num) {
        std::cout << "Invalid index: please enter a number." << std::endl;
        return;
    }

    // Convertir string a int (en C++98 se usa atoi de <cstdlib> o sscanf)
    int index = std::atoi(input.c_str());

    if (index < 1 || index > contactCount)
    {
        std::cout << "Invalid index: out of range." << std::endl;
        return;
    }

    const Contact &contact = contacts[index - 1];
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}