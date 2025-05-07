/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:56:47 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/07 11:09:51 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("d1"),
isSigned(false),
sign_grade(1),
execute_grade(1){
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::~AForm(){
	std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const std::string name, int signGrade, int executeGrade) : name(name),
isSigned(false), 
sign_grade(signGrade),
execute_grade(executeGrade){
	std::cout << "AForm constructor called" << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();

}

AForm::AForm(const AForm &src) : name(src.name),
isSigned(false),
sign_grade(src.sign_grade),
execute_grade(src.execute_grade){
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &src){
	if (this != &src) {
		this->isSigned = src.isSigned;
	}
	return (*this);
}

const std::string AForm::getName() const{
	return (this->name);
}

bool AForm::getIsSigned() const{
	return (this->isSigned);
}

const int AForm::getSignGrade() const{
	return (this->sign_grade);
}

const int AForm::getExecuteGrade()const {
	return (this->execute_grade);
}

const char* AForm::GradeTooLowException::what() const throw(){
	return ("Error ! Grade too low !");
}

const char* AForm::GradeTooHighException::what() const throw(){
	return ("Error ! Grade too high !");
}

std::ostream &operator<<(std::ostream &out, const AForm &src){
	out << "Name : "<< src.getName() << "Sign grade : " << src.getSignGrade() << "Execute grade : " << src.getExecuteGrade() << "signed : "<< src.getIsSigned();
	return (out);
}

void AForm::beSigned(Bureaucrat &signer){
	if (signer.getGrade() <= this->sign_grade) {
		this->isSigned = true;
	} else {
		throw AForm::GradeTooLowException();
	}
}


