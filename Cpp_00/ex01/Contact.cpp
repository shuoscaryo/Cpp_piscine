/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:49:46 by orudek            #+#    #+#             */
/*   Updated: 2023/10/18 15:35:27 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::set_first_name(std::string input)
{
	first_name = input;
}

void Contact::set_last_name(std::string input)
{
	last_name = input;
}

void Contact::set_nickname(std::string input)
{
	nickname = input;
}

void Contact::set_phone_number(std::string input)
{
	phone_number = input;
}

void Contact::set_darkest_secret(std::string input)
{
	darkest_secret = input;
}

std::string Contact::get_first_name() const
{
	return (first_name);
}

std::string Contact::get_last_name() const
{
	return (last_name);
}

std::string Contact::get_nickname() const
{
	return (nickname);
}

std::string Contact::get_phone_number() const
{
	return (phone_number);
}

std::string Contact::get_darkest_secret() const
{
	return (darkest_secret);
}

std::ostream& operator <<(std::ostream &os, const Contact &contact)
{
	os << std::setw(10) << "First name: " << contact.get_first_name() << std::endl;
	os << std::setw(10) << "Last name: " << contact.get_last_name() << std::endl;
	os << std::setw(10) << "Nickname: " << contact.get_nickname() << std::endl;
	os << std::setw(10) << "Phone number: " << contact.get_phone_number() << std::endl;
	os << std::setw(10) << "Darkest secret: " << contact.get_darkest_secret() << std::endl;
	return (os);
}
