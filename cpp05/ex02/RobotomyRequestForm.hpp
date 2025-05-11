/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:40:27 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/11 15:51:07 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"
# include <ctime>
# include <cstdlib>

class  RobotomyRequestForm : public AForm{
	private :
		std::string	_target;
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(RobotomyRequestForm &src);
		~RobotomyRequestForm();
		
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
		std::string				getTarget();
		void execute(Bureaucrat const & executor) const;
	
};

#endif