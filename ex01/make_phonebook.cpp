/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_phonebook.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flyte <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:13:29 by flyte             #+#    #+#             */
/*   Updated: 2021/09/27 17:13:31 by flyte            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Phonebook.class.hpp"

int main()
{
    char        buff[512];
    Phonebook   my_phonebook;
  
    while (1)
    {
      std::cout << "Input a command: ";
      std::cin >> buff;
      if (!strcmp(buff, "ADD"))
        my_phonebook.addContact();
      else if (!strcmp(buff, "SEARCH"))
        my_phonebook.searchContacts();
      else if (!strcmp(buff, "EXIT"))
      {
        std::cout << "Good bye! " << std::endl;
        return (0);
      }
      std::cout << std::endl;
    }
    return (0);
}
