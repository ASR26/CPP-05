/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:59:42 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/23 09:12:54 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

Intern &Intern::operator=(const Intern &intern)
{
	(void) intern;
	return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(std::string type, std::string target) const
{
	std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*funct[3])(std::string) const = {&Intern::createShrub, &Intern::createRobo, &Intern::createPardon};
	int i = 0;
	while (i < 3)
	{
		if(!type.compare(types[i]))
			return (this->*funct[i])(target);
		i++;
	}
	std::cout << "Form " << type << " does not exist" << std::endl;
	return (NULL);
}
AForm* Intern::createShrub(std::string target) const
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createPardon(std::string target) const
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::createRobo(std::string target) const
{
	return new RobotomyRequestForm(target);
}