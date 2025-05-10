/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:40:11 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/10 14:43:17 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), _target("default"){
    std::cout << "Presidential pardon form default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: AForm("PresidentialPardonForm", 25, 5), _target(target){
    std::cout << "Presidential pardon form constructor called" << std::endl;

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src)
: AForm("PresidentialPardonForm", 25, 5), _target(src._target){
    std::cout << "Presidential pardon form copy constructor called" << std::endl;
	
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "Presidential pardon form destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src){
    if (this != &src){
		this->_target = src._target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const{
	if (!getIsSigned()){
		throw FormNotSignedException();
	}
	if(executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget(){
    return (this->_target);
}