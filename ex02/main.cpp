/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:44:29 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/09 10:51:43 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

int	main()
{
	srand(time(NULL));

	//std::cout << time(NULL) << std::endl;

	Bureaucrat John("John", 2);
	Bureaucrat Tom("Tom", 149);
	PresidentialPardonForm Meperdonas("ABC");
	ShrubberyCreationForm Shrub("DEF");
	RobotomyRequestForm Robocop("GHI");
	
	std::cout << "\n";
	John.executeForm(Meperdonas);
	Tom.signForm(Meperdonas);
	John.signForm(Meperdonas);
	Tom.executeForm(Meperdonas);
	John.executeForm(Meperdonas);
	std::cout << "\n";
	Tom.signForm(Shrub);
	John.signForm(Shrub);
	Tom.executeForm(Shrub);
	John.executeForm(Shrub);
	std::cout << "\n";
	Tom.signForm(Robocop);
	John.signForm(Robocop);
	Tom.executeForm(Robocop);
	John.executeForm(Robocop);
	std::cout << "\n";
	//AForm Formulario2(Formulario);
}