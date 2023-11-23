/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:44:29 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/23 08:31:19 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
# include "Form.hpp"

int	main()
{
	Bureaucrat John("John", 2);
	Bureaucrat Tom("Tom", 149);
	Form Formulario("ABC", 50, 50);
	
	try
	{
		Formulario.beSigned(John);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
	try
	{
		Formulario.beSigned(Tom);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
	try
	{
		Tom.signForm(Formulario);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		John.signForm(Formulario);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << Formulario << std::endl;
	Form Formulario2(Formulario);
}