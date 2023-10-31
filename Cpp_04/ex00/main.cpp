/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:39:09 by orudek            #+#    #+#             */
/*   Updated: 2023/10/31 14:57:53 by orudek           ###   ########.fr       */
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
		const Animal* animal= new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		
		std::cout << std::endl;
		std::cout << "Animal sound: ";
		animal->makeSound();
		std::cout << "Dog sound: ";
		dog->makeSound();
		std::cout << "Cat sound: ";
		cat->makeSound();
		std::cout << std::endl;
		delete animal;
		delete dog;
		delete cat;
		std::cout << std::endl;
	}
	{
		const WrongAnimal* animal= new WrongAnimal();
		const WrongAnimal* cat = new WrongCat();
		
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