/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:54:41 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/08 11:20:33 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"
class Bureaucrat
{
private:
	const std::string	_name;
	int	_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &bur);
	Bureaucrat &operator=(const Bureaucrat &copy);
	~Bureaucrat();
	const std::string getName() const;
	int	getGrade() const;
	void signForm(class AForm &form);

	class	GradeTooHighException: public std::exception 
	{
		virtual const char *what() const throw();
	};
	class	GradeTooLowException: public std::exception 
	{
		virtual const char *what() const throw();
	};

	void	increment();
	void	decrement();
	void executeForm(AForm const & form);
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bur);

#endif