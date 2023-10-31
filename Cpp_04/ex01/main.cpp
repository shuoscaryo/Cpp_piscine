/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:13:24 by orudek            #+#    #+#             */
/*   Updated: 2023/10/31 17:08:52 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "cstdlib"

int main()
{
	const Animal* animals[10];
	for (int i = 0; i < 5; i ++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i ++)
		animals[i] = new Cat();
	
	for (int i = 0; i < 10; i ++)
		delete animals[i];
	
	std::cout << std::endl;
	Dog* dog= new Dog();

	dog->addIdea("I want to eat");
	dog->addIdea("I want to sleep");
	dog->addIdea("I want to go poop");
	dog->printIdeas();

	Dog* dog2 = new Dog(*dog);
	dog2->printIdeas();
	delete dog;
	delete dog2;
	//system("leaks brain");
	return (0);
}