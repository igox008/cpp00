/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:42:57 by alaassir          #+#    #+#             */
/*   Updated: 2024/04/27 02:47:36 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook   phonebook;
    std::string input;

    while (true)
    {
        if (std::cin.eof())
        {
            std::cout << std::endl;
            break ;
        }
        std::cout << "COMMOND >> " ;
        if (!std::getline(std::cin, input))
        {
            std::cout << std::endl;
            break ;
        }
        if (input == "ADD")
            phonebook.add_contact();
        else if (input == "SEARCH")
            phonebook.search();
        else if (input == "EXIT")
            break ;
        else if (input.empty())
            std::cout << std::endl;
        else
            std::cout << "\n" << input << " Not a valid command try {ADD, SEARCH and EXIT}" << std::endl;
    }
    return (0);
}
