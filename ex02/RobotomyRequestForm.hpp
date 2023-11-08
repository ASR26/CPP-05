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

#ifndef ROBORTOMYREQUESTFORM_HPP
# define ROBORTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		const std::string _target;
		int	_counter;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &form);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();

		const std::string getTarget() const;
		int	getCounter();
		void execute(Bureaucrat const & executor) const;
};

#endif