/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:03:39 by alaassir          #+#    #+#             */
/*   Updated: 2024/04/24 22:12:25 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    for (int i = 1; i < ac;i++)
    {
        for (int j = 0;av[i][j];j++)
            std::cout << (char)toupper(av[i][j]);
    }
    std::cout << "\n";
    return (0);
}