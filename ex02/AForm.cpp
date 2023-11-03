/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:16:26 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/03 11:19:57 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

Form::Form(): _name("Unknown"), _sign(false), _signgrade(1), _exgrade(1)
{
	std::cout << "Form constructor called" << std::endl;
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Signed: " << this->getSign() << std::endl;
	std::cout << "Sign grade: " << this->getSignGrade() << std::endl;
	std::cout << "Execution grade: " << this->getExGrade() << std::endl;
}

Form::Form(const std::string name, const int signgrade, const int exgrade): _name(name), _sign(false), _signgrade(signgrade), _exgrade(exgrade)
{
	std::cout << "Form constructor called" << std::endl;
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Signed: " << this->getSign() << std::endl;
	std::cout << "Sign grade: " << this->getSignGrade() << std::endl;
	std::cout << "Execution grade: " << this->getExGrade() << std::endl;
	if (this->getExGrade() < 1)
		throw Form::GradeTooHighException();
	else if (this->getExGrade() > 150)
		throw Form::GradeTooLowException();
		if (this->getSignGrade() < 1)
		throw Form::GradeTooHighException();
	else if (this->getSignGrade() > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &form): _name(form.getName()), _sign(form.getSign()), _signgrade(form.getSignGrade()), _exgrade(form.getExGrade())
{
	std::cout << "Copy form constructor called" << std::endl;
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Signed: " << this->getSign() << std::endl;
	std::cout << "Sign grade: " << this->getSignGrade() << std::endl;
	std::cout << "Execution grade: " << this->getExGrade() << std::endl;
	if (this->getExGrade() < 1)
		throw Form::GradeTooHighException();
	else if (this->getExGrade() > 150)
		throw Form::GradeTooLowException();
	if (this->getSignGrade() < 1)
		throw Form::GradeTooHighException();
	else if (this->getSignGrade() > 150)
		throw Form::GradeTooLowException();
}

const char	*Form::GradeTooHighException::what() const throw() 
{
	return ("Exception - Grade too High!!");
}
const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Exception - Grade too Low!!");
}

std::string Form::getName() const
{
	return this->_name;
}

int Form::getSignGrade() const
{
	return this->_signgrade;
}

int Form::getExGrade() const
{
	return this->_exgrade;
}

bool Form::getSign() const
{
	return this->_sign;
}

void Form::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
	this->_sign = true;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}