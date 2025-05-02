/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:57:43 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/02 09:50:42 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150){
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade){
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name), grade(src.grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src){
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	this->grade = src.grade;
	return (*this);
}

void Bureaucrat::gradeUp(){
	if (grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::gradeDown(){
	if (grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

const std::string  Bureaucrat::getName()const {
	return (this->name);
}

int Bureaucrat::getGrade() const {
	return(this->grade);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src){
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return (out);
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Error ! Grade too high !");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Error ! Grade too low !");
}
