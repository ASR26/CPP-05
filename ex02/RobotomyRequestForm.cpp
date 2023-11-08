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

RobotomyRequestForm::RobotomyRequestForm(): _name("Unknown Robotomy"), _sign(false), _signgrade(72), _exgrade(45), _target("unknown"), _counter(0)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Signed: " << this->getSign() << std::endl;
	std::cout << "Sign grade: " << this->getSignGrade() << std::endl;
	std::cout << "Execution grade: " << this->getExGrade() << std::endl;
	std::cout << "Target: " << this->getTarget() << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): _name(copy.getName()), _sign(copy.getSign()), _signgrade(copy.getSignGrade()), _exgrade(copy.getExGrade()), _target(copy.getTarget()), _counter(copy.getCounter()))
{
	std::cout << "Copy RobotomyRequestForm constructor called" << std::endl;
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Signed: " << this->getSign() << std::endl;
	std::cout << "Sign grade: " << this->getSignGrade() << std::endl;
	std::cout << "Execution grade: " << this->getExGrade() << std::endl;
	std::cout << "Target: " << this->getTarget() << std::endl;
	if (this->getExGrade() < 1)
		throw RobotomyRequestForm::GradeTooHighException();
	else if (this->getExGrade() > 150)
		throw RobotomyRequestForm::GradeTooLowException();
	if (this->getSignGrade() < 1)
		throw RobotomyRequestForm::GradeTooHighException();
	else if (this->getSignGrade() > 150)
		throw RobotomyRequestForm::GradeTooLowException();
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	if (!this->getSign())
		throw RobotomyRequestForm::UnsignedException();
	if (executor.getGrade() > this->getExGrade())
		throw RobotomyRequestForm::GradeTooLowException();
	if (this->getCounter() % 2)
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << this->getTarget() << " robotomization failed" << std::endl;
	this->_counter++;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

const std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

int RobotomyRequestForm::getCounter()
{
	return this->_counter;
}