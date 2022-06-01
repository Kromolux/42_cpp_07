/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:36:40 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/30 15:37:52 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T>
void	iter(T * array, size_t len, void (*function)(T & element))
{
	for (size_t i = 0; i < len; i++)
	{
		(*function)(array[i]);
	}
}

template <typename T>
void	test_print(T & element)
{
	std::cout << "[" << element << "] ";
}

template <typename T>
void	test_increment(T & element)
{
	element++;
}

#endif
