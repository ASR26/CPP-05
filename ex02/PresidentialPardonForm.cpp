/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:58:13 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/08 08:50:22 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential pardon", 25, 5)
{
	this->setTarget("Unknown target");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential pardon", 25, 5)
{
	this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm(copy.getName(), copy.getSignGrade(), copy.getExGrade())
{
	this->setTarget(copy.getTarget());
	this->setSign(copy.getSign());
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	this->setTarget(copy.getTarget());
	this->setSign(copy.getSign());
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSign())
		throw PresidentialPardonForm::UnsignedException();
	if (executor.getGrade() > this->getExGrade())
		throw PresidentialPardonForm::GradeTooLowException();
	std::cout << this->getName() << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}
