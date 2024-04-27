/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 00:41:34 by alaassir          #+#    #+#             */
/*   Updated: 2024/04/27 00:49:18 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

contact::contact(void)
{
}

contact::~contact()
{
}

void	contact::set_fname(std::string _set_f){this->first_name = _set_f;}

void	contact::set_lname(std::string _set_l){this->last_name = _set_l;}

void	contact::set_nname(std::string _set_n){this->nickname = _set_n;}

void	contact::set_num(std::string _set_num){this->number = _set_num;}

void	contact::set_sec(std::string _set_s){this->secret = _set_s;}

std::string	contact::get_fname(void){return (this->first_name);}

std::string	contact::get_lname(void){return (this->last_name);}

std::string	contact::get_nname(void){return (this->nickname);}

std::string	contact::get_num(void){return (this->number);}

std::string	contact::get_sec(void){return (this->secret);}
