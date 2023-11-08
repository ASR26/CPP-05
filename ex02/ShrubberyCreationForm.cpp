/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:58:13 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/08 08:59:54 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): _name("Unknown Shrubbery"), _sign(false), _signgrade(145), _exgrade(137), _target("unknown")
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Signed: " << this->getSign() << std::endl;
	std::cout << "Sign grade: " << this->getSignGrade() << std::endl;
	std::cout << "Execution grade: " << this->getExGrade() << std::endl;
	std::cout << "Target: " << this->getTarget() << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): _name(copy.getName()), _sign(copy.getSign()), _signgrade(copy.getSignGrade()), _exgrade(copy.getExGrade()), _target(copy.getTarget())
{
	std::cout << "Copy ShrubberyCreationForm constructor called" << std::endl;
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Signed: " << this->getSign() << std::endl;
	std::cout << "Sign grade: " << this->getSignGrade() << std::endl;
	std::cout << "Execution grade: " << this->getExGrade() << std::endl;
	std::cout << "Target: " << this->getTarget() << std::endl;
	if (this->getExGrade() < 1)
		throw ShrubberyCreationForm::GradeTooHighException();
	else if (this->getExGrade() > 150)
		throw ShrubberyCreationForm::GradeTooLowException();
	if (this->getSignGrade() < 1)
		throw ShrubberyCreationForm::GradeTooHighException();
	else if (this->getSignGrade() > 150)
		throw ShrubberyCreationForm::GradeTooLowException();
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	if (!this->getSign())
		throw ShrubberyCreationForm::UnsignedException();
	if (executor.getGrade() > this->getExGrade())
		throw ShrubberyCreationForm::GradeTooLowException();
	std::ofstream newFile(this->getTarget()+ "_shrubbery");
	newFile << "
                 .              .              ;%     ;;   
                   ,           ,                :;%  %;   
                    :         ;                   :;%;'     .,   
           ,.        %;     %;            ;        %;'    ,;
             ;       ;%;  %%;        ,     %;    ;%;    ,%'
              %;       %;%;      ,  ;       %;  ;%;   ,%;' 
               ;%;      %;        ;%;        % ;%;  ,%;'
                `%;.     ;%;     %;'         `;%%;.%;'
                 `:;%.    ;%%. %@;        %; ;@%;%'
                    `:%;.  :;bd%;          %;@%;'
                      `@%:.  :;%.         ;@@%;'   
                        `@%.  `;@%.      ;@@%;         
                          `@%%. `@%%    ;@@%;        
                            ;@%. :@%%  %@@%;       
                              %@bd%%%bd%%:;     
                                #@%%%%%:;;
                                %@@%%%::;
                                %@@@%(o);  . '         
                                %@@@o%;:(.,'         
                            `.. %@@@o%::;         
                               `)@@@o%::;         
                                %@@(o)::;        
                               .%@@@@%::;         
                               ;%@@@@%::;.          
                              ;%@@@@%%:;;;. 
                          ...;%@@@@@%%:;;;;,..    " << std::endl;
	newFile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

const std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}