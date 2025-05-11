/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:06:38 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/11 15:53:53 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"

int main(void){
	srand(time(NULL));
	std::cout << "<-----------[Bureaucrat default constructor tests]----------->" << std::endl;
	try {
		Bureaucrat a;
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "<-----------[Bureaucrat constructor tests]----------->" << std::endl;
	try {
		Bureaucrat b("Bob", 150);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "Too high grade constructor test" << std::endl;
	try {
		Bureaucrat c("Cedric", 0);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Too low grade constructor test" << std::endl;
	try {
		Bureaucrat d("Dylan", 151);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "<-----------[Bureaucrat copy constructor tests]----------->" << std::endl;
	Bureaucrat e("Emile", 130);
	Bureaucrat f(e);

	std::cout << "<-----------[Bureaucrat new construction tests]----------->" << std::endl;
	Bureaucrat *g = new Bureaucrat();
	Bureaucrat *h = new Bureaucrat("Haymich", 23);
	Bureaucrat *i = new Bureaucrat(*h);
	Bureaucrat *j = new Bureaucrat("Jannet", 150);
	Bureaucrat *k = new Bureaucrat("Karen", 1);
	
	std::cout << "<-----------[Grade up and down tests]----------->" << std::endl;

	try {
		g->gradeUp();
		std::cout << *g <<std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	try {
		h->gradeUp();
		std::cout << *h <<std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		i->gradeUp();
		std::cout << *i <<std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		j->gradeDown();
		std::cout << *j <<std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	try {
		k->gradeUp(); 
		std::cout << *k << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "<-----------[Form default constructor tests]----------->" << std::endl;
	try {
		Form fa;
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	
	try {
		Form fb;
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "<-----------[Form constructor tests]----------->" << std::endl;
	try {
		Form fc("testc", 45, 45);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	
	try {
		Form fd("testd", 150, 150);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try {
		Form fe("teste", 165, 165);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	
	try {
		Form ff("testf", 0, 0);
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "<-----------[Form copy constructor tests]----------->" << std::endl;
	Form fg("a28", 28, 12);
	Form fh(fg);
	
	std::cout << "<-----------[Form new construction tests]----------->" << std::endl;
	Form *fi = new Form("i", 130, 130);
	
	std::cout << "<-----------[Form assignment operator tests]----------->" << std::endl;
	Form f1("original", 42, 42);
	Form f2("placeholder", 150, 150);

	f2 = f1;

	std::cout << "Assigned f1 to f2:\n";
	std::cout << "f1: " << f1 << std::endl;
	std::cout << "f2: " << f2 << std::endl;
		
	std::cout << "<-----------[Sign form tests]----------->" << std::endl;

	Form signTest("ShrubberyRequest", 50, 25);
	Bureaucrat goodBureaucrat("Alice", 40); // good enough
	Bureaucrat badBureaucrat("Dave", 100);  // too low

	std::cout << signTest << std::endl;

	goodBureaucrat.signForm(signTest);
	std::cout << signTest << std::endl;

	goodBureaucrat.signForm(signTest);

	badBureaucrat.signForm(signTest);
	

	delete g;
	delete h; 
	delete i;
	delete j;
	delete k;
	delete fi;
}