/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:04:26 by orudek            #+#    #+#             */
/*   Updated: 2023/10/17 22:51:55 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	total = 0;
}

static void wait_for_key()
{
	std::cout << "(Press any key to continue)" << std::endl;
	std::string input;
	std::getline(std::cin, input);
	system("clear");
}

static void	save_str(Contact &contact, void (Contact::*func)(std::string), std::string element_name)
{
	std::string input;
	
	do{
		std::cout << "Enter " << element_name << ": " << std::flush;
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << element_name << " can't be empty" << std::endl;
	} while (input.empty());
	(contact.*func)(input);
}

static void	save_number(Contact &contact)
{
	int is_num;
	std::string input;

	do {
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
		is_num = 1;
		for (auto i: input)
			if (!isdigit(i))
			{
				std::cout << "Phone number must be only numbers" << std::endl;
				is_num = 0;
				break;
			}
		if (is_num == 1 && input.length() != 9)
		{
			std::cout << "Invalid phone number length, must be 9 numbers" << std::endl;
			continue ;
		}
	} while(is_num == 0 || input.length() != 9);
	contact.set_phone_number(input);
}

void PhoneBook::add_contact()
{
	std::string input;

	system("clear");
	std::cout << "ADD Contact" << std::endl;
	save_str(contact[index], &Contact::set_first_name, "first name");
	save_str(contact[index], &Contact::set_last_name, "last name");
	save_str(contact[index], &Contact::set_nickname, "nickname");
	save_number(contact[index]);
	save_str(contact[index], &Contact::set_darkest_secret, "darkest secret");
	index = (index + 1) % 8;
	if (total < 8)
		total++;
	std::cout << "Contact added" << std::endl;
	wait_for_key();
	system("clear");
}

static void	display_contact(const Contact &contact, int index)
{
	system("clear");
	std::cout << "Displaying Contact" << index << std::endl;
	std::cout << std::setw(10) << "First name: " << contact.get_first_name() << std::endl;
	std::cout << std::setw(10) << "Last name: " << contact.get_last_name() << std::endl;
	std::cout << std::setw(10) << "Nickname: " << contact.get_nickname() << std::endl;
	std::cout << std::setw(10) << "Phone number: " << contact.get_phone_number() << std::endl;
	std::cout << std::setw(10) << "Darkest secret: " << contact.get_darkest_secret() << std::endl;
}

void PhoneBook::search_contact() const
{
	system("clear");
	std::cout << "SEARCH Contact" << std::endl;
	std::cout << "|" << std::setw(10) << std::right << "index" << "|";
	std::cout << std::setw(10) << std::right << "first name" << "|";
	std::cout << std::setw(10) << std::right << "last name" << "|";
	std::cout << std::setw(10) << std::right << "nickname" << "|" << std::endl;
	for (int i = 0; i < total; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		std::cout <<  std::setw(10) << (contact[i].get_first_name().length() > 10 ? contact[i].get_first_name().substr(0, 9) + "." : contact[i].get_first_name()) << "|";
		std::cout <<  std::setw(10) << (contact[i].get_last_name().length() > 10 ? contact[i].get_last_name().substr(0, 9) + "." : contact[i].get_last_name()) << "|";
		std::cout <<  std::setw(10) << (contact[i].get_nickname().length() > 10 ? contact[i].get_nickname().substr(0, 9) + "." : contact[i].get_nickname()) << "|";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	if (total == 0)
	{
		std::cout << "No contacts to show" << std::endl;
		wait_for_key();
		return ;
	}
	int i;
	do{
		std::cout << "Enter index of contact: ";
		std::cin >> i;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
		if (i <= 0 || i > total)
			std::cout << "Invalid index" << std::endl;
	} while (i <= 0 || i > total);
	display_contact(contact[i - 1], i);
	wait_for_key();
}
