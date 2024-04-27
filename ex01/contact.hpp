/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 00:32:24 by alaassir          #+#    #+#             */
/*   Updated: 2024/04/27 00:45:51 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	number;
		std::string	secret;
	public:
		contact(void);
		~contact();
		void	set_fname(std::string _set_f);
		void	set_lname(std::string _set_l);
		void	set_nname(std::string _set_n);
		void	set_num(std::string _set_num);
		void	set_sec(std::string _set_s);
		std::string	get_fname(void);
		std::string	get_lname(void);
		std::string	get_nname(void);
		std::string	get_num(void);
		std::string	get_sec(void);
		
};


#endif