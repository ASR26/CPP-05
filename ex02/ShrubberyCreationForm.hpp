/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:19:22 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/06 09:19:22 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		const std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &form);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();

		const std::string getTarget() const;
		void execute(Bureaucrat const & executor);
};

ShrubberyCreationForm::ShrubberyCreationForm(/* args */)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


#endif