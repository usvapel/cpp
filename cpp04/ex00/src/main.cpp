/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:50:59 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/22 19:52:03 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal *meta = new Animal();
	const Animal *dog  = new Dog();
	const Animal *cat  = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;

	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	const WrongAnimal *wrong = new WrongCat();
	std::cout << wrong->getType() << " " << std::endl;
	wrong->makeSound();

	delete meta; delete dog; delete cat; delete wrong;
	return 0;
}
