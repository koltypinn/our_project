/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flyte <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:13:40 by flyte             #+#    #+#             */
/*   Updated: 2021/09/27 17:13:43 by flyte            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./includes/Phonebook.class.hpp"

int	Phonebook::_counter = 0;

Phonebook::Phonebook(void) {
    return ;
}

Phonebook::~Phonebook(void) {
    return ;
}

void Phonebook::_printRepeatedChar(char c, int len)
{
  while (len)
  {
    std::cout << c;
    len--;
  }
}

void Phonebook::_printStr(std::string str)
{
  int i;
  int char_count;
  int len;

  i = 0;
  char_count = 0;
  len = str.length();
  if (len < 10)
  {
    std::cout << str;
    this->_printRepeatedChar(' ', 10 - len);
  }
  else 
  {
    while (i < 9)
    {
      std::cout << str[i];
      i++;
    }
    std::cout <<".";
  } 
}

void Phonebook::_printTableHeader(void)
{
  std::cout << std::setfill ('-') << std::setw (45) << "";
  std::cout << std::endl;
  std::cout << "|";
  std::cout << "   index  " << "|" << "   name   " << "|";
  std::cout << "familyname" << "|" << "  nikname " << "|";
  std::cout << std::endl;
  std::cout << std::setfill ('-') << std::setw (45) << "";
  std::cout << std::endl;
}

void Phonebook::_printTable(void)
{
  int i;
  int index;

  i = 0;
  this->_printTableHeader();
  while (i < 8)
  {
    if (!this->contacts[i].getFirstName().empty()) {
      index = i + 1;
      std::cout << "|";
      std::cout << index << std::setfill (' ') << std::setw (9) <<  "";
      std::cout << "|";
      this->_printStr(this->contacts[i].getFirstName());
      std::cout << "|";
      this->_printStr(this->contacts[i].getLastName());
      std::cout << "|";
      this->_printStr(this->contacts[i].getNickName());
      std::cout << "|";
      std::cout << std::endl;
    }
    i++;
  }
}

void Phonebook::addContact(void)
{
  char    buff[512];
  Contact contact;
  int     i;
  
  i = 0;
  std::cout << "Input your first name: ";
  std::cin >> buff;
  contact.setFirstName(buff);
  std::cout << "Input your last name: ";
  std::cin >> buff;
  contact.setLastName(buff);
  std::cout << "Input your nickname: ";
  std::cin >> buff;
  contact.setNickName(buff);
  std::cout << "Input your phone number: ";
  std::cin >> buff;
  contact.setPhoneNumber(buff);
  std::cout << "Input your darkest secret: ";
  std::cin >> buff;
  contact.setDarkestSecret(buff);
  while(i != _counter)
    i++;
  this->contacts[i] = contact;
  _counter++;
  if (this->_counter == 8)
    this->_counter = 0;
}

void Phonebook::searchContacts(void)
{
  int wanted_index = 0;

  this->_printTable();
  std::cout << "Input index of wanted contact: ";
  std::cin >> wanted_index;
  if(!std::cin) 
  {
    std::cin.clear();
    std::cin.ignore(512, '\n');
    std::cout << "Sorry, it is wrong index." <<  std::endl;
    return ;
  }
  if ((wanted_index >= 1 && wanted_index <= 8) && !this->contacts[wanted_index - 1].getFirstName().empty())
  {
    std::cout << "first name: " << this->contacts[wanted_index - 1].getFirstName() <<  std::endl;
    std::cout << "last name: " << this->contacts[wanted_index - 1].getLastName() <<  std::endl;
    std::cout << "nickname: " << this->contacts[wanted_index - 1].getNickName() <<  std::endl;
    std::cout << "phone: " << this->contacts[wanted_index - 1].getPhoneNumber() <<  std::endl;
    std::cout << "darkest secret: " << this->contacts[wanted_index - 1].getDarkestSecret() <<  std::endl;
  }
  else 
    std::cout << "Sorry, there is no such contact." <<  std::endl;
  return ;
}
