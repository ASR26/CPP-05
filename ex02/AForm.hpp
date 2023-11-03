/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:16:19 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/03 11:25:38 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	protected:
		virtual const std::string _name;
		virtual bool	_sign;
		virtual const int _signgrade;
		virtual const int _exgrade;
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


#endif