/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:58:13 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/09 10:42:21 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery creation", 145, 137) 
{
	this->setTarget("Unknown target");
}


ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("Shrubbery creation", 145, 137) 
{
	this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm(copy.getName(), copy.getSignGrade(), copy.getExGrade())
{
	this->setTarget(copy.getTarget());
	this->setSign(copy.getSign());
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	this->setTarget(copy.getTarget());
	this->setSign(copy.getSign());
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSign())
		throw ShrubberyCreationForm::UnsignedException();
	if (executor.getGrade() > this->getExGrade())
		throw ShrubberyCreationForm::GradeTooLowException();
	std::ofstream file(this->getTarget()+ "_shrubbery");
	file << "             .              .              ;%     ;;   " << std::endl
    << "               ,           ,                :;%  %;   " << std::endl
    << "                :         ;                   :;%;'     .,   " << std::endl
    << "       ,.        %;     %;            ;        %;'    ,;" << std::endl
    << "         ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl
    << "          %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl
    << "           ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl
    << "            `%;.     ;%;     %;'         `;%%;.%;'" << std::endl
    << "             `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl
    << "                `:%;.  :;bd%;          %;@%;'" << std::endl
    << "                  `@%:.  :;%.         ;@@%;'   " << std::endl
    << "                    `@%.  `;@%.      ;@@%;         " << std::endl
    << "                      `@%%. `@%%    ;@@%;        " << std::endl
    << "                        ;@%. :@%%  %@@%;       " << std::endl
    << "                          %@bd%%%bd%%:;     " << std::endl
    << "                            #@%%%%%:;;" << std::endl
    << "                            %@@%%%::;" << std::endl
    << "                            %@@@%(o);  . '         " << std::endl
    << "                            %@@@o%;:(.,'         " << std::endl
    << "                        `.. %@@@o%::;         " << std::endl
    << "                           `)@@@o%::;         " << std::endl
    << "                            %@@(o)::;        " << std::endl
    << "                           .%@@@@%::;         " << std::endl
    << "                           ;%@@@@%::;.          " << std::endl
    << "                          ;%@@@@%%:;;;. " << std::endl
    << "                      ...;%@@@@@%%:;;;;,..    " << std::endl;
	file.close();
	std::cout << this->getTarget() << "_shrubbery created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}