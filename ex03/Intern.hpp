/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:59:46 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/14 10:59:30 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &intern);
		Intern &operator=(const Intern &intern);
		~Intern();
		AForm* makeForm(std::string type, std::string target) const;
		AForm* createShrub(std::string target) const;
		AForm* createPardon(std::string target) const;
		AForm* createRobo(std::string target) const;
};

#endif