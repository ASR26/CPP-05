/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:44:29 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/23 09:12:59 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "Intern.hpp"

int	main()
{
	srand(time(NULL));

	//std::cout << time(NULL) << std::endl;
	Intern jeff;

	Bureaucrat John("John", 2);
	Bureaucrat Tom("Tom", 149);
	/* PresidentialPardonForm Meperdonas("ABC");
	ShrubberyCreationForm Shrub("DEF");
	RobotomyRequestForm Robocop("GHI"); */
	AForm *Meperdonas = jeff.makeForm("presidential pardon", "ABC");
	AForm *Shrub = jeff.makeForm("shrubbery creation", "DEF");
	AForm *Robocop = jeff.makeForm("robotomy request", "GHI");
	AForm *Random = jeff.makeForm("random request", "random target");
	
	std::cout << "\n";	
	if (Meperdonas)
	{
		John.executeForm(*Meperdonas);
		Tom.signForm(*Meperdonas);
		John.signForm(*Meperdonas);
		Tom.executeForm(*Meperdonas);
		John.executeForm(*Meperdonas);
		delete Meperdonas;
		std::cout << "\n";
	}
	if (Shrub)
	{
		Tom.signForm(*Shrub);
		John.signForm(*Shrub);
		Tom.executeForm(*Shrub);
		John.executeForm(*Shrub);
		delete Shrub;
		std::cout << "\n";
	}
	if (Robocop)
	{
		Tom.signForm(*Robocop);
		John.signForm(*Robocop);
		Tom.executeForm(*Robocop);
		John.executeForm(*Robocop);
		delete Robocop;
		std::cout << "\n";
	}
	if (Random)
	{
		Tom.signForm(*Random);
		John.signForm(*Random);
		Tom.executeForm(*Random);
		John.executeForm(*Random);
		delete Random;
		std::cout << "\n";
	}
}