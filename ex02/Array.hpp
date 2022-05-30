/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:06:32 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/30 19:46:03 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <stdexcept>
# include "colors.h"

template <typename T>
class Array
{
	public:

		Array(void);
		Array(unsigned int size);
		Array(Array const & obj);

		Array & operator=(Array<T> const & obj);
		T & operator[](unsigned int index);

		unsigned int	size(void);

		~Array(void);

	protected:

	private:
	
		T				* _array;
		unsigned int	_size;
	
};

template <typename T>
Array<T>::Array(void)
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Array] default constructor called." << std::endl << COLOR_DEFAULT;
	_size = 0;
	_array = NULL;
}

template <typename T>
Array<T>::Array(unsigned int size)
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Array] parameter constructor called." << std::endl << COLOR_DEFAULT;
	_array = new T[size];
	_size = size;
}

template <typename T>
Array<T>::Array(Array<T> const & obj)
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Array] copy constructor called." << std::endl << COLOR_DEFAULT;
	this->_size = 0;
	*this = obj;
}

template <typename T>
Array<T> & Array<T>::operator=(Array<T> const & obj)
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Array] assignement constructor called." << std::endl << COLOR_DEFAULT;
	if (this == &obj)
		return (*this);
	if (this->_size > 0)
		delete [] this->_array;
	this->_size = obj._size;
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = obj._array[i];
	return (*this);
}

template <typename T>
T & Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw std::out_of_range("Array::Index out of bounds!");
	return (this->_array[index]);
}

template <typename T>
unsigned int	Array<T>::size(void)
{
	return (this->_size);
}

template <typename T>
Array<T>::~Array(void)
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Array] deconstructor called." << std::endl << COLOR_DEFAULT;
	if (this->_size > 0)
		delete [] this->_array;
}

#endif
