/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:16:19 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/07 11:44:32 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	protected:
		const std::string _name;
		bool	_sign;
		const int _signgrade;
		const int _exgrade;
	public:
		AForm();
		AForm(const std::string name, const int signgrade, const int exgrade);
		AForm(const AForm &aform);
		AForm &operator=(const AForm &aform);
		~AForm();

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
		class	UnsignedException: public std::exception 
		{
			virtual const char *what() const throw();
		};
		
		virtual void execute(Bureaucrat const & executor) const = 0;
};


#endif