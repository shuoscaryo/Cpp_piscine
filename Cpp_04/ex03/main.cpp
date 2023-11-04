/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:36:19 by orudek            #+#    #+#             */
/*   Updated: 2023/11/01 19:06:35 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
	std::cout << "==============SUBJECT===============" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	std::cout << "==============MY_TEST===============" << std::endl;
	std::cout << "Creating a MateriaSource" << std::endl;
	MateriaSource src2;
	std::cout << "Learning Ice 4 times" << std::endl;
	src2.learnMateria(new Ice());
	src2.learnMateria(new Ice());
	src2.learnMateria(new Ice());
	src2.learnMateria(new Ice());
	std::cout << "Trying to learn cure as 5th element" << std::endl;
	AMateria *cure = new Cure();
	src2.learnMateria(cure);
	delete cure;
	std::cout << "Creating a Character called you" << std::endl;
	ICharacter *you = new Character("you");
	std::cout << "Creating an Ice materia item" << std::endl;
	AMateria* ice = src2.createMateria("ice");
	std::cout << "Equiping the Ice materia item on you" << std::endl;
	you->equip(ice);
	you->use(0, *you);
	std::cout << "Unequiping ice from you" << std::endl;
	you->unequip(0);
	std::cout << "Trying to use ice on you" << std::endl;
	you->use(0, *you);
	std::cout << "Trying to equip ice twice on you" << std::endl;
	you->equip(ice);
	you->equip(ice);
	std::cout << "Deleting you. (ice will be destroyed too)" << std::endl;
	delete you;
	return 0;
}