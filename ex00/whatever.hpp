/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:13:36 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/24 21:30:08 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template < typename T>
void	swap(T & x, T & y)
{
	T tmp = x;

	x = y;
	y = tmp;
}

template < typename T>
T const &	min(T const & x, T const & y)
{
	if (x < y)
		return (x);
	return (y);
}

template < typename T>
T const &	max(T const & x, T const & y)
{
	if (x > y)
		return (x);
	return (y);
}

#endif
