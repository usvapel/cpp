/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:50:59 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/23 14:00:49 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	// Animal* animals[100];

	// for (int i = 0; i < 50; i++)
	// 	animals[i] = new Dog();

	// for (int i = 50; i < 100; i++)
	// 	animals[i] = new Cat();
		
	// for (int i = 0; i < 100; i++)
	// 	delete animals[i];
	//Animal a;
    std::cout << "=== Testing Deep Copy ===" << std::endl;
    
    // Test 1: Copy constructor
    std::cout << "\n--- Test 1: Copy Constructor ---" << std::endl;
    Dog original;
    Dog copied(original);  // Should create new Brain
    
    std::cout << "Original Dog brain address: " << &original << std::endl;
    std::cout << "Copied Dog brain address: " << &copied << std::endl;
    // If deep copy works, destroying one shouldn't affect the other
    
    // Test 2: Assignment operator
    std::cout << "\n--- Test 2: Assignment Operator ---" << std::endl;
    Cat cat1;
    Cat cat2;
    cat2 = cat1;  // Should create new Brain for cat2
    
    // Test 3: Scope test (most important)
    std::cout << "\n--- Test 3: Scope Test ---" << std::endl;
    Dog* dog1 = new Dog();
    Dog* dog2;
    {
        Dog tempDog(*dog1);  // Copy constructor
        dog2 = new Dog(tempDog);  // Another copy
        std::cout << "tempDog going out of scope..." << std::endl;
    }  // tempDog is destroyed here
    
    // If deep copy works, dog2 should still be valid
    std::cout << "dog2 still alive after tempDog destruction" << std::endl;
    dog2->makeSound();  // This would crash with shallow copy
    
    delete dog1;
    delete dog2;
    
    // Test 4: Array test like your original
    std::cout << "\n--- Test 4: Array Test ---" << std::endl;
    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog(*static_cast<Dog*>(animals[0]));  // Copy
    animals[3] = new Cat(*static_cast<Cat*>(animals[1]));  // Copy
    
    for (int i = 0; i < 4; i++)
        delete animals[i];  // Should not crash with deep copies
    
    std::cout << "\nAll tests completed successfully!" << std::endl;

	return 0;
}
