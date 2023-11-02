/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:16:26 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/02 11:25:38 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Unknown"), _sign(false), _signgrade(1), _exgrade(1)
{
	std::cout << this->getName() << " Bureaucrat constructor called, grade asigned: " << this->getGrade() << std::endl;
}

const char	*Form::GradeTooHighException::what() const throw() 
{
	return ("Exception - Grade too High!!");
}
const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Exception - Grade too Low!!");
}

const std::string Form::getName()
{
	return this->_name;
}

Form::~Form()
{
	
}