/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:04:26 by orudek            #+#    #+#             */
/*   Updated: 2023/10/18 15:52:26 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	total = 0;
}

Contact PhoneBook::get_contact(int index) const
{
	return (contact[index]);
}

int PhoneBook::get_total_contacts() const
{
	return (total);
}

static void wait_for_key()
{
	std::cout << "(Press enter to continue)" << std::endl;
	std::string input;
	std::getline(std::cin, input);
	system("clear");
}

void	PhoneBook::save_str(Contact &contact, void (Contact::*func)(std::string), std::string element_name)
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

void	PhoneBook::save_number(Contact &contact)
{
	int is_num;
	std::string input;

	do {
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
		is_num = 1;
		long unsigned int input_len = input.length();
		for (long unsigned int i = 0; i < input_len; i++)
			if (!isdigit(input[i]))
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

int	PhoneBook::get_index(int total) const
{
	int i;
	do{
		std::cout << "Enter index of contact: ";
		std::cin >> i;
    	if (std::cin.fail()) {
        	std::cin.clear();
        	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        	std::cout << "Invalid input. Please enter a number." << std::endl;
			i = 0;
		}
		else if (i <= 0 || i > total)
			std::cout << "Invalid index" << std::endl;
	} while (i <= 0 || i > total);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	return (i);
}

void PhoneBook::search_contact() const
{
	system("clear");
	std::cout << "SEARCH Contact" << std::endl;
	std::cout << *this;
	std::cout << std::endl;
	if (total == 0)
	{
		std::cout << "No contacts to show" << std::endl;
		wait_for_key();
		return ;
	}
	int i = get_index(total);
	system("clear");
	std::cout << "Displaying Contact " << index << std::endl;
	std::cout << contact[i - 1];
	wait_for_key();
}

std::ostream& operator<<(std::ostream& os, const PhoneBook& pb)
{
    os << "|" << std::setw(10) << std::right << "index" << "|";
    os << std::setw(10) << std::right << "first name" << "|";
    os << std::setw(10) << std::right << "last name" << "|";
    os << std::setw(10) << std::right << "nickname" << "|" << std::endl;
    for (int i = 0; i < pb.get_total_contacts(); i++)
    {
		Contact contact = pb.get_contact(i);
        os << "|" << std::setw(10) << i + 1 << "|";
        os <<  std::setw(10) << (contact.get_first_name().length() > 10 ? contact.get_first_name().substr(0, 9) + "." : contact.get_first_name()) << "|";
        os <<  std::setw(10) << (contact.get_last_name().length() > 10 ? contact.get_last_name().substr(0, 9) + "." : contact.get_last_name()) << "|";
        os <<  std::setw(10) << (contact.get_nickname().length() > 10 ? contact.get_nickname().substr(0, 9) + "." : contact.get_nickname()) << "|";
        os << std::endl;
    }
	return (os);
}