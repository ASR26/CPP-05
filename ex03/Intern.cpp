/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:59:42 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/09 11:23:52 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const &Intern intern)
{
}

Intern &Intern::operator=(const &Intern intern)
{
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(std::string type, std::string target)
{
	std::string types[3] = {"shrubbery creation", "robotomy request", "president pardon"}
	int i = 0
	while (i < 3)
	{
		if(!type.compare(types[i]))
			break;
		i++;
	}
	switch(i)
		case 0:
			std::cout << "Intern created a " type << " form" << std::endl;
			return(new SrubberyCreationForm(target));
		case 1:
			std::cout << "Intern created a " type << " form" << std::endl;
			return(new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern created a " type << " form" << std::endl;
			return(new PresidentPardonForm(target));
		default:
			std::cout << type << " form does not exist" << std::endl;
			return NULL;
		
}