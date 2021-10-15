/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flyte <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:13:12 by flyte             #+#    #+#             */
/*   Updated: 2021/09/27 17:13:19 by flyte            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./includes/Contact.class.hpp"

Contact::Contact(void) {
    return ;
}

Contact::~Contact(void) {
    return ;
}

std::string Contact::getFirstName(void) {
    return this->_first_name;
}

std::string Contact::getLastName(void) {
    return this->_last_name;
}

std::string Contact::getNickName(void) {
    return this->_nickname;
}

std::string Contact::getPhoneNumber(void) {
    return this->_phone_number;
}

std::string Contact::getDarkestSecret(void) {
    return this->_darkest_secret;
}

void Contact::setFirstName(std::string firstName) {
    this->_first_name = firstName;
    return ;
}

void Contact::setLastName(std::string lastName) {
    this->_last_name = lastName;
    return ;
}

void Contact::setNickName(std::string nickName) {
    this->_nickname = nickName;
    return ;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
    this->_phone_number = phoneNumber;
    return ;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
    this->_darkest_secret = darkestSecret;
    return ;
}
