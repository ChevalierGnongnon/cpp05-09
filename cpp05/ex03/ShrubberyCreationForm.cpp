/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:40:31 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/11 17:51:00 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), _target("default"){
    std::cout << "Shrubbery Creation Form default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target){
    std::cout << "Shrubbery Creation Form constructor called" << std::endl;

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src)
: AForm("ShrubberyCreationForm", 145, 137), _target(src._target){
    std::cout << "Shrubbery Creation Form copy constructor called" << std::endl;
	
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "Shrubbery Creation Form destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src){
    if (this != &src){
		this->_target = src._target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
	std::ofstream file;
	std::string filename = this->_target + "_shrubbery";
	int res;

	if (!getIsSigned()){
		throw FormNotSignedException();
	}
	if(executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	file.open(filename.c_str());
	if (!file.is_open())
		throw FileCreationException();
	file << "    /\\\n";
	file << "   /  \\\n";
	file << "  /++++\\\n";
	file << " /  ()  \\\n";
	file << "/_______\\\n";
	file << "   ||||\n";
	file << "   ||||\n";

	file.close();
}

std::string ShrubberyCreationForm::getTarget(){
    return (this->_target);
}