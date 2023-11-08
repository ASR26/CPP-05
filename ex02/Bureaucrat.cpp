/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:54:44 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/08 11:08:13 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Unknown"), _grade(150)
{
	std::cout << this->getName() << " Bureaucrat constructor called, grade asigned: " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << this->getName() << " Bureaucrat constructor called, grade asigned: " << this->getGrade() << std::endl;
	if (this->getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bur): _name(bur.getName()), _grade(bur.getGrade())
{
	std::cout << this->getName() << " Bureaucrat copy constructor called, grade asigned: " << this->getGrade() << std::endl;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bur)
{
	this->_grade = bur.getGrade();
	std::cout << this->getName() << " Bureaucrat operator called, grade asigned: " << this->getGrade() << std::endl;
	return *this;
}

void	Bureaucrat::increment()
{
	if (this->_grade - 1 >= 1)
	{
		this->_grade--;
		std::cout << "Grade incremented correctly. Current grade: " << this->getGrade() << std::endl;
	}
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrement()
{
	if (this->_grade + 1 <= 150)
	{
		this->_grade++;
		std::cout << "Grade decremented correctly. Current grade: " << this->getGrade() << std::endl;
	}
	else
		throw Bureaucrat::GradeTooLowException();
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() 
{
	return ("Exception - Grade too High!!");
}
const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception - Grade too Low!!");
}

const std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &copy)
{
	os << copy.getName() << ", bureaucrat grade " << copy.getGrade() << std::endl;
	return (os);
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because his grade is too low"<< std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
	}
	
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}