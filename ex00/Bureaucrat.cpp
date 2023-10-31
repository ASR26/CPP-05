/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:54:44 by asolano-          #+#    #+#             */
/*   Updated: 2023/10/31 11:57:33 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	this->_name = "Unknown bureaucrat";
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
{
	this->_name = name;
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bur)
{
	this->_name = bur.getName();
	this->_grade = bur.getGrade();
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bur)
{
	this->_name = bur.getName();
	this->_grade = bur.getGrade();
	return *this;
}

void	Bureaucrat::increment()
{
	try
	{
		if (this.getGrade() -= 1 < 1)
			throw;
		else
			this->_grade--;
	}
	catch (std::string)
	{

	}
}

Bureaucrat::~Bureaucrat()
{
}