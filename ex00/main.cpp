/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:44:29 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/02 11:06:20 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat John("John", 2);
	Bureaucrat Tom("Tom", 149);
	John.increment();
	try
	{
		John.increment();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Tom.decrement();
	try
	{
		Tom.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat Jim("Jim", 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat Sam("Sam", -10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}