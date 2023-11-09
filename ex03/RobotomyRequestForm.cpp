/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:58:13 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/08 08:50:22 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():  AForm("Robotomy request", 72, 45) 
{
	this->setTarget("Unknown target");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target):  AForm("Robotomy request", 72, 45) 
{
	this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm(copy.getName(), copy.getSignGrade(), copy.getExGrade())
{
	this->setTarget(copy.getTarget());
	this->setSign(copy.getSign());
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	this->setTarget(copy.getTarget());
	this->setSign(copy.getSign());
	return *this;
}


void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSign())
		throw RobotomyRequestForm::UnsignedException();
	if (executor.getGrade() > this->getExGrade())
		throw RobotomyRequestForm::GradeTooLowException();
	std::cout << "* drilling noise *" << std::endl;
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << this->getTarget() << " robotomization failed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}
