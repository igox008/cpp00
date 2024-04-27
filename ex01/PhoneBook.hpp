/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 00:26:16 by alaassir          #+#    #+#             */
/*   Updated: 2024/04/27 03:07:21 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cctype>
#include "contact.hpp"

# define RST "\033[0m"
# define BG_WHT "\033[47m"
# define B_BLK "\033[1;30m"
# define B_RED "\033[1;31m"

class PhoneBook
{
	private:
		contact	my_contacts[8];
		int		contact_index;
		int		size;
	public:
		PhoneBook();
		~PhoneBook();
		void		add_contact(void);
		void		search(void);
		void		printIindex(void);
};


#endif