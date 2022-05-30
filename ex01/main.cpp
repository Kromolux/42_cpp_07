/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:34:23 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/30 15:37:59 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include <climits>
#include "colors.h"

static void	print_text(std::string output);

int	main(void)
{
	int			int_array[5] = {6, 0, 42, INT_MIN, INT_MAX};
	long		long_array[5] = {45893, 1548935, 0, LONG_MIN, LONG_MAX};
	float		float_array[5] = {42.42, 3.14, 98.46, 0.0, -4789};
	char		char_array[9] = {'A', 'C', 'F', '-', '$', '6', '?', 'h', '!'};
	std::string	string_array[5] = {"Hello", "World", "!", "42", "rules"};

	print_text("Testing with int array.");
	std::cout << "total result of size of: " << sizeof(int_array) << " size of first element: " << sizeof(int_array[0]) << std::endl;
	::iter(int_array, sizeof(int_array) / sizeof(int_array[0]), &test_print);
	std::cout << std::endl;
	::iter(int_array, sizeof(int_array) / sizeof(int_array[0]), &test_increment);
	::iter(int_array, sizeof(int_array) / sizeof(int_array[0]), &test_print);
	std::cout << std::endl;

	print_text("Testing with long array.");
	std::cout << "total result of size of: " << sizeof(long_array) << " size of first element: " << sizeof(long_array[0]) << std::endl;
	::iter(long_array, sizeof(long_array) / sizeof(long_array[0]), &test_print);
	std::cout << std::endl;
	::iter(long_array, sizeof(long_array) / sizeof(long_array[0]), &test_increment);
	::iter(long_array, sizeof(long_array) / sizeof(long_array[0]), &test_print);
	std::cout << std::endl;

	print_text("Testing with float array.");
	std::cout << "total result of size of: " << sizeof(float_array) << " size of first element: " << sizeof(float_array[0]) << std::endl;
	::iter(float_array, sizeof(float_array) / sizeof(float_array[0]), &test_print);
	std::cout << std::endl;
	::iter(float_array, sizeof(float_array) / sizeof(float_array[0]), &test_increment);
	::iter(float_array, sizeof(float_array) / sizeof(float_array[0]), &test_print);
	std::cout << std::endl;

	print_text("Testing with char array.");
	std::cout << "total result of size of: " << sizeof(char_array) << " size of first element: " << sizeof(char_array[0]) << std::endl;
	::iter(char_array, sizeof(char_array) / sizeof(char_array[0]), &test_print);
	std::cout << std::endl;
	::iter(char_array, sizeof(char_array) / sizeof(char_array[0]), &test_increment);
	::iter(char_array, sizeof(char_array) / sizeof(char_array[0]), &test_print);
	std::cout << std::endl;

	print_text("Testing with string array.");
	std::cout << "total result of size of: " << sizeof(string_array) << " size of first element: " << sizeof(string_array[0]) << std::endl;
	::iter(string_array, sizeof(string_array) / sizeof(string_array[0]), &test_print);
	std::cout << std::endl;
	//::iter(string_array, sizeof(string_array) / sizeof(string_array[0]), &test_increment);
	::iter(string_array, sizeof(string_array) / sizeof(string_array[0]), &test_print);
	std::cout << std::endl;
	return (0);
}

static void	print_text(std::string output)
{
	std::cout << COLOR_YELLOW << "\n" << output << "\n\n" << COLOR_DEFAULT;
}
