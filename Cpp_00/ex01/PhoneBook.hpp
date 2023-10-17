/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:20:06 by orudek            #+#    #+#             */
/*   Updated: 2023/10/17 20:41:30 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include <iomanip>
#include <limits>

class PhoneBook{
private:
	Contact contact[8];
	int index;
	int	total;
public:
	PhoneBook();
	void add_contact();
	void search_contact() const;
};
