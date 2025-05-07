/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:56:47 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/07 10:06:20 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("d1"),
isSigned(false),
sign_grade(1),
execute_grade(1){
	std::cout << "Form default constructor called" << std::endl;
}

Form::~Form(){
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(const std::string name, int signGrade, int executeGrade) : name(name),
isSigned(false), 
sign_grade(signGrade),
execute_grade(executeGrade){
	std::cout << "Form constructor called" << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();

}

Form::Form(const Form &src) : name(src.name),
isSigned(false),
sign_grade(src.sign_grade),
execute_grade(src.execute_grade){
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &src){
	if (this != &src) {
		this->isSigned = src.isSigned;
	}
	return (*this);
}

const std::string Form::getName() const{
	return (this->name);
}

bool Form::getIsSigned() const{
	return (this->isSigned);
}

const int Form::getSignGrade() const{
	return (this->sign_grade);
}

const int Form::getExecuteGrade()const {
	return (this->execute_grade);
}

const char* Form::GradeTooLowException::what() const throw(){
	return ("Error ! Grade too low !");
}

const char* Form::GradeTooHighException::what() const throw(){
	return ("Error ! Grade too high !");
}

std::ostream &operator<<(std::ostream &out, const Form &src){
	out << "Name : "<< src.getName() << "Sign grade : " << src.getSignGrade() << "Execute grade : " << src.getExecuteGrade() << "signed : "<< src.getIsSigned();
	return (out);
}

void Form::beSigned(Bureaucrat &signer){
	if (signer.getGrade() <= this->sign_grade) {
		this->isSigned = true;
	} else {
		throw Form::GradeTooLowException();
	}
}


