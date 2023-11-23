/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:16:19 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/23 08:30:11 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool	_sign;
		const int _signgrade;
		const int _exgrade;
	public:
		Form();
		Form(const std::string name, const int signgrade, const int exgrade);
		Form(const Form &form);
		Form &operator=(const Form &form);
		~Form();

		std::string getName() const;
		bool getSign() const;
		int getSignGrade() const;
		int getExGrade() const;
		void	beSigned(class Bureaucrat &bur);

	class	GradeTooHighException: public std::exception 
	{
		virtual const char *what() const throw();
	};
	class	GradeTooLowException: public std::exception 
	{
		virtual const char *what() const throw();
	};
	
};

std::ostream &operator<<(std::ostream &os, const Form &copy);


#endif