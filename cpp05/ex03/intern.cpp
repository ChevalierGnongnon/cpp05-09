/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:20:38 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/12 10:52:39 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.hpp"

Intern::Intern(){
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &src){
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern(){
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src){
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void) src;
	return (*this);
}

static AForm *makeShrubberyForm(const std::string &target){
	return (new ShrubberyCreationForm(target));
}

static AForm *makePresidentialPardon(const std::string &target){
	return (new PresidentialPardonForm(target));
}

static AForm *makeRobotomyRequest(const std::string &target){
	return (new RobotomyRequestForm(target));
}

const char *Intern::UnknownFormException::what() const throw(){
	return ("Error ! invalid form name !");
}

AForm *Intern::makeForm(const std::string name, const std::string &target){
	int i = 0;
	std::string types[4] = {"ShrubberyCreationForm", "PresidentialPardonForm", "RobotomyRequestForm", NULL};
	AForm* (*constructors[3])(const std::string&) = {makeShrubberyForm, makePresidentialPardon, makeRobotomyRequest};
	while (i < 3 && name.compare(types[i]) != 0){
		i++;
	}
	if (i < 3){
		return (constructors[i](target));
	}
	else
		throw UnknownFormException();
}