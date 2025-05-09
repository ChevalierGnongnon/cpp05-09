/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:40:21 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/09 17:17:28 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	private :
		const std::string	target;
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