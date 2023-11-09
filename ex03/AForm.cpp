/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:16:26 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/08 11:25:49 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("Unknown"), _sign(false), _signgrade(1), _exgrade(1)
{
	std::cout << "AForm constructor called" << std::endl;
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Signed: " << this->getSign() << std::endl;
	std::cout << "Sign grade: " << this->getSignGrade() << std::endl;
	std::cout << "Execution grade: " << this->getExGrade() << std::endl;
}

AForm::AForm(const std::string name, const int signgrade, const int exgrade): _name(name), _sign(false), _signgrade(signgrade), _exgrade(exgrade)
{
	std::cout << "AForm constructor called" << std::endl;
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Signed: " << this->getSign() << std::endl;
	std::cout << "Sign grade: " << this->getSignGrade() << std::endl;
	std::cout << "Execution grade: " << this->getExGrade() << std::endl;
	if (this->getExGrade() < 1 || this->getSignGrade() < 1)
		throw AForm::GradeTooHighException();
	else if (this->getExGrade() > 150 || this->getSignGrade() > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &aform): _name(aform.getName()), _sign(aform.getSign()), _signgrade(aform.getSignGrade()), _exgrade(aform.getExGrade())
{
	std::cout << "Copy Aform constructor called" << std::endl;
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Signed: " << this->getSign() << std::endl;
	std::cout << "Sign grade: " << this->getSignGrade() << std::endl;
	std::cout << "Execution grade: " << this->getExGrade() << std::endl;
	if (this->getExGrade() < 1 || this->getSignGrade() < 1)
		throw AForm::GradeTooHighException();
	else if (this->getExGrade() > 150 || this->getSignGrade() > 150)
		throw AForm::GradeTooLowException();
}

const char	*AForm::GradeTooHighException::what() const throw() 
{
	return ("Exception - Grade too High!!");
}
const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Exception - Grade too Low!!");
}

const char	*AForm::UnsignedException::what() const throw()
{
	return ("Exception - Unsigned form!!");
}

std::string AForm::getName() const
{
	return this->_name;
}

int AForm::getSignGrade() const
{
	return this->_signgrade;
}

int AForm::getExGrade() const
{
	return this->_exgrade;
}

bool AForm::getSign() const
{
	return this->_sign;
}

std::string AForm::getTarget() const
{
	return this->_target;
}

void AForm::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	this->_sign = true;
}

AForm &AForm::operator=(const AForm &form)
{
	this->_sign = form.getSign();
	return *this;
}


void AForm::setTarget(std::string target)
{
	this->_target = target;
}

void	AForm::setSign(bool s)
{
	this->_sign = s;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}