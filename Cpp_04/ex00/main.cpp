/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:39:09 by orudek            #+#    #+#             */
/*   Updated: 2023/10/31 15:23:31 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

#define RED         "\033[31m"
#define RESET       "\033[0m"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		delete j;
		delete i;
		delete meta;
		std::cout << std::endl;
	}
	{
		const WrongAnimal* animal= new WrongAnimal();
		const WrongAnimal* cat = new WrongCat();
		
		std::cout << std::endl;
		std::cout << "WrongAnimal type: " << animal->getType() << std::endl;
		std::cout << "WrongCat type: " << cat->getType() << std::endl;
		std::cout << std::endl;

		std::cout << "WrongAnimal sound: ";
		animal->makeSound();
		std::cout << "WrongCat sound: ";
		cat->makeSound();
		std::cout << RED << "Should be:\n\tWrongCat sound: meow" << RESET << std::endl;
		std::cout << std::endl;
		delete animal;
		delete cat;
		std::cout << RED << "Should be:\n\tWrongCat destructor called\n\tWrongAnimal destructor called" << RESET << std::endl;
	}
	return (0);
}