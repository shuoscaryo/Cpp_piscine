/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:47:00 by orudek            #+#    #+#             */
/*   Updated: 2023/10/18 00:03:27 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;

	system("clear");
	while (1)
	{
		std::cout << "Enter command: ";
		std::string input;
		getline(std::cin, input);
		if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else if (input == "EXIT")
			break ;
		else
		{
			std::cout << "Invalid input" << std::endl;
			std::cout << "Enter ADD, SEARCH or EXIT" << std::endl;
		}
	}
	system("clear");
	return (0);
}