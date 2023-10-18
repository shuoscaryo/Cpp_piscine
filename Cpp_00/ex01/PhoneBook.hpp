/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:20:06 by orudek            #+#    #+#             */
/*   Updated: 2023/10/18 15:52:36 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include <iomanip>
#include <limits>
#include <cstdlib>

class PhoneBook{
private:
	Contact contact[8];
	int index;
	int	total;
	
	void save_str(Contact &contact, void (Contact::*func)(std::string), std::string element_name);
	void save_number(Contact &contact);
	int get_index(int total) const;
public:
	PhoneBook();
	Contact get_contact(int index) const;
	int get_total_contacts() const;
	void add_contact();
	void search_contact() const;
};

std::ostream& operator<<(std::ostream& os, const PhoneBook& phonebook);
