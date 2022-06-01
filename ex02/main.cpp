/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:06:30 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/30 21:03:58 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750

static void	print_text(std::string output);

int main(int, char**)
{
	print_text("Creating two Arrays.");
	Array<int>	numbers(MAX_VAL);
	Array<int>	empty_array;
	int			* mirror = new int[MAX_VAL];

	std::cout << "Size of empty Array: " << empty_array.size() << std::endl;
	try
	{
		std::cout << "Accessing empty Array: " << empty_array[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << COLOR_RED << e.what() << '\n' << COLOR_DEFAULT;
	}
	
	std::cout << "\nSize of big Array: " << numbers.size() << std::endl;
	std::cout << "value of Array[5]: " << numbers[5] << std::endl;

	print_text("Assigning random numbers to Array.");
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	
	print_text("Testing with scope of Variables and calling copy constructor.");
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	print_text("Comparing values.");
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return (1);
		}
	}

	print_text("Try to access index out of bounds - negativ.");
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << COLOR_RED << e.what() << '\n' << COLOR_DEFAULT;
	}
	
	print_text("Try to access index out of bounds - greater max.");
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << COLOR_RED << e.what() << '\n' << COLOR_DEFAULT;
	}

	print_text("Assigning other random numbers for Array.");
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}

	print_text("Deleting Arrays.");
	delete [] mirror;
	return (0);
}

static void	print_text(std::string output)
{
	std::cout << COLOR_YELLOW << "\n" << output << "\n\n" << COLOR_DEFAULT;
}
