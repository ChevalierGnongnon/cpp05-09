/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:40:21 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/10 13:34:26 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	private :
		std::string	_target;
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(PresidentialPardonForm &src);
		~PresidentialPardonForm();
		
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &src);
		std::string				getTarget();
		void 					execute(Bureaucrat const & executor) const;
};

#endif