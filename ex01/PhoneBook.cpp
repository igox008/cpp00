/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 00:50:10 by alaassir          #+#    #+#             */
/*   Updated: 2024/05/29 13:17:55 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->contact_index = 0;
	this->size = 0;
	std::cout << BG_WHT"" B_BLK "Welcome to 90s PhoneBook" RST << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Wassafi wassiiiiiir! JK" << std::endl;
}

std::string	resize_it(std::string s)
{
	if (s.size() > 10)
	{
		s.resize(10);
		s[s.size() - 1] = '.';
	}
	return (s);
}

bool	is_valid_number(std::string s)
{
	for (int i = 0;s[i];i++)
	{
		if (!isdigit(s[i]))
		{
			std::cout << "The number must contain only digit!! " << std::endl;
			return (false);
		}
	}
	if (s.size() < 10)
	{
		std::cout << "The number must be at least 10 digits!! " << std::endl;
		return (false);
	}
	return (true);
}

bool	all_space(std::string str)
{
	for (int i = 0;str[i];i++)
	{
		if (!isspace(str[i]))
			return (false);
	}
	return (true);
}

std::string	prompt(std::string _get)
{
	std::string input;

	while (true)
	{
		if (std::cin.eof())
			break ;
		std::cout << "Enter the " << _get << " : ";
		if (!std::getline(std::cin, input))
			break ;
		if (input.empty() || all_space(input))
		{
			std::cout << _get << " can't be empty, try again : ";
			if (!std::getline(std::cin, input))
				break ;
			while (input.empty() || all_space(input))
			{
				std::cout << _get << " can't be empty, try again : ";
				if (!std::getline(std::cin, input))
					return (input);
			}
			return (input);
		}
		else if (_get == "number" && !is_valid_number(input))
			continue ;
		else
			break ;
	}
	return (input);
}

void    PhoneBook::add_contact(void)
{
	if (this->contact_index > 7)
	{
		std::cout << B_RED "WARNING : the contact with the name " \
		<< this->my_contacts[this->contact_index % 8].get_fname() << " " \
		<< this->my_contacts[this->contact_index % 8].get_lname() \
		<< " will be overwritten" RST << std::endl;
	}
	this->my_contacts[this->contact_index % 8].set_fname(prompt("first name"));
	this->my_contacts[this->contact_index % 8].set_lname(prompt("last name"));
	this->my_contacts[this->contact_index % 8].set_nname(prompt("nickname"));
	this->my_contacts[this->contact_index % 8].set_num(prompt("number"));
	this->my_contacts[this->contact_index % 8].set_sec(prompt("secret"));
	this->contact_index++;
	if (this->size < 8)
		this->size++;
}

std::string	add_spaces(std::string s)
{
	std::string	tmp = "";
	while (s.size() + tmp.size() < 10)
		tmp.append(" ");
	s.insert(0, tmp);
	return (s);
}

void	PhoneBook::printIindex(void)
{
	std::string	input;
	int			i;

	while (true)
	{
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
		std::cout << "What index you want : ";
		if (!std::getline(std::cin, input))
			break ;
		if (input.size() == 1 && isdigit(input[0]) && input[0] - 48 < this->size)
		{
			i = input[0] - 48;
			std::cout << "First name     : " << this->my_contacts[i].get_fname() << std::endl;
			std::cout << "Last name      : " << this->my_contacts[i].get_lname() << std::endl;
			std::cout << "nickname       : " << this->my_contacts[i].get_nname() << std::endl;
			std::cout << "Phone number   : " << this->my_contacts[i].get_num() << std::endl;
			std::cout << "darkest secret : " << this->my_contacts[i].get_sec() << std::endl;
			break ;
		}
		else
			std::cout << "Invalid index! try again..." << std::endl;
	}
}

void	PhoneBook::search(void)
{
	int	i = 0;
	char c = '0';
	std::string	tmp;

	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (i < this->contact_index % 8)
	{
		tmp = c;
		std::cout << "|" << add_spaces(tmp);
		std::cout << "|" << ((this->my_contacts[i].get_fname().size() > 10) ? \
		resize_it(this->my_contacts[i].get_fname()) : add_spaces(this->my_contacts[i].get_fname()));
		std::cout << "|" << ((this->my_contacts[i].get_lname().size() > 10) ? \
		resize_it(this->my_contacts[i].get_lname()) : add_spaces(this->my_contacts[i].get_lname()));
		std::cout << "|" << ((this->my_contacts[i].get_nname().size() > 10) ? \
		resize_it(this->my_contacts[i].get_nname()) : add_spaces(this->my_contacts[i].get_nname()));
		std::cout << "|" << std::endl;
		i++;
		c++;
	}
	std::cout << " ------------------------------------------- " << std::endl;
	if (this->size > 0)
		this->printIindex();
	else
		std::cout << "The PhoneBook is empty as you see !!" << std::endl;
}
