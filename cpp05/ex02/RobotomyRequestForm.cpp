/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:40:24 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/11 16:12:32 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), _target("default"){
    std::cout << "Robotomy Request form default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: AForm("RobotomyRequestForm", 72, 45), _target(target){
    std::cout << "Robotomy Request form constructor called" << std::endl;

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src)
: AForm("RobotomyRequestForm", 72, 45), _target(src._target){
    std::cout << "Robotomy Request form copy constructor called" << std::endl;
	
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "Robotomy Request form destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src){
    if (this != &src){
		this->_target = src._target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const{
	int res;
	
	if (!getIsSigned()){
		throw FormNotSignedException();
	}
	if(executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	std::cout << "*drilling noises*" << std::endl;
	res = rand();
	if (res % 2 == 0)
		std::cout << this->_target << " has been robotomized properly." << std::endl;
	else
		std::cout << this->_target << " hasn't been robotomized, operation failed." << std::endl;
}

std::string RobotomyRequestForm::getTarget(){
    return (this->_target);
}