/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:40:27 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/07 13:39:10 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class  RobotomyRequestForm : public AForm{
	private :
		const std::string	target;
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(RobotomyRequestForm &src);
		~RobotomyRequestForm();
		
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

		void execute(Bureaucrat const & executor) const;
	
};

#endif