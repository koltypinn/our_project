/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flyte <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:12:19 by flyte             #+#    #+#             */
/*   Updated: 2021/09/27 17:12:33 by flyte            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include <string>
#include <locale>

int main(int argc, char *argv[])
{
    int     i;
    int     j;
    char    c;

    if (argc == 1) 
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else if (argc > 1)
    {
        i = 1;
        while(i < argc)
        {
            j = 0;
            while(argv[i][j])
            {
                c = argv[i][j];
                std::cout << (char)(toupper(c));
                j++;
            }
            i++;
        }
        std::cout << std::endl;
    }
    return (0);
}

