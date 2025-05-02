/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:06:38 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/02 09:47:49 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void){
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

	std::cout << "<-----------[Copy constructor tests]----------->" << std::endl;
	Bureaucrat e("Emile", 130);
	Bureaucrat f(e);

	std::cout << "<-----------[Construction with new tests]----------->" << std::endl;
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
		
	delete g;
	delete h; 
	delete i;
	delete j;
	delete k;
}