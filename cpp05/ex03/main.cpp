/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:06:38 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/15 12:22:17 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "intern.hpp"

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

	std::cout << "<-----------[ShrubberyCreation tests]----------->" << std::endl;
	try {
		ShrubberyCreationForm shrub("home");
		Bureaucrat treeLover("Ellie", 1);

		treeLover.signForm(shrub);
		shrub.execute(treeLover);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "<-----------[Robotomy request  tests]----------->" << std::endl;
	try {
		RobotomyRequestForm robot("Bender");
		Bureaucrat technician("Rick", 1);

		technician.signForm(robot);
		robot.execute(technician);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		RobotomyRequestForm robot2("Bender");
		Bureaucrat technician2("Morty", 1);

		technician2.signForm(robot2);
		robot2.execute(technician2);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "<-----------[Presidential pardon tests]----------->" << std::endl;
	try {
		PresidentialPardonForm form("Bendy");
		Bureaucrat boss("Mike", 1);

		boss.signForm(form);
		form.execute(boss);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "<-----------[other tests]----------->" << std::endl;

	ShrubberyCreationForm shrub("backyard");
	Bureaucrat tooWeak("Todd", 150);

	try {
		tooWeak.signForm(shrub);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat goodGuy("Alex", 1);
	goodGuy.signForm(shrub);

	try {
		shrub.execute(tooWeak);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	goodGuy.signForm(shrub); 
	
	std::cout << "<-----[Shrubbery - invalid signer]----->" << std::endl;
	try {
		ShrubberyCreationForm shrub("Garden");
		Bureaucrat tooWeak("Todd", 150);
		tooWeak.signForm(shrub);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "<-----[Shrubbery - valid signer, invalid executor]----->" << std::endl;
	try {
		ShrubberyCreationForm shrub("Garden");
		Bureaucrat good("Alice", 1);
		Bureaucrat weak("Todd", 150);
		good.signForm(shrub);
		shrub.execute(weak);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "<-----[Shrubbery - sign twice]----->" << std::endl;
	try {
		ShrubberyCreationForm shrub("Garden");
		Bureaucrat signer("Alice", 1);
		signer.signForm(shrub);
		signer.signForm(shrub);
		shrub.execute(signer);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "<-----[Robotomy - invalid signer]----->" << std::endl;
	try {
		RobotomyRequestForm robo("Marvin");
		Bureaucrat weakling("Stan", 150);
		weakling.signForm(robo);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "<-----[Robotomy - valid signer, invalid executor]----->" << std::endl;
	try {
		RobotomyRequestForm robo("Marvin");
		Bureaucrat smart("Sarah", 1);
		Bureaucrat tooLow("Stan", 150);
		smart.signForm(robo);
		robo.execute(tooLow);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "<-----[Robotomy - sign twice]----->" << std::endl;
	try {
		RobotomyRequestForm robo("Marvin");
		Bureaucrat strong("Sarah", 1);
		strong.signForm(robo);
		strong.signForm(robo);
		robo.execute(strong);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "<-----[Presidential - invalid signer]----->" << std::endl;
	try {
		PresidentialPardonForm pardon("Waluigi");
		Bureaucrat weak("Jerry", 150);
		weak.signForm(pardon);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "<-----[Presidential - valid signer, invalid executor]----->" << std::endl;
	try {
		PresidentialPardonForm pardon("Waluigi");
		Bureaucrat prez("Sam", 1);
		Bureaucrat intern("Jerry", 150);
		prez.signForm(pardon);
		pardon.execute(intern);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "<-----[Presidential - sign twice]----->" << std::endl;
	try {
		PresidentialPardonForm pardon("Waluigi");
		Bureaucrat boss("Sam", 1);
		boss.signForm(pardon);
		boss.signForm(pardon);
		pardon.execute(boss);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "<-----[Bureaucrat::executeForm() - success]----->" << std::endl;
	try {
		Bureaucrat top("Director", 1);
		ShrubberyCreationForm form("TestShrub");
		top.signForm(form);
		top.executeForm(form);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "<-----[Bureaucrat::executeForm() - failure]----->" << std::endl;
	try {
		Bureaucrat intern("Intern", 150);
		ShrubberyCreationForm form("TestShrub");
		intern.signForm(form);
		intern.executeForm(form);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

		std::cout << "<-----------[Intern Form Creation tests]----------->" << std::endl;
	Intern someRandomIntern;

	try {
		AForm* form1 = someRandomIntern.makeForm("ShrubberyCreationForm", "Garden");
		Bureaucrat executor("Frank", 1);
		executor.signForm(*form1);
		executor.executeForm(*form1);
		delete form1;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		AForm* form2 = someRandomIntern.makeForm("PresidentialPardonForm", "Neo");
		Bureaucrat executor("Trinity", 1);
		executor.signForm(*form2);
		executor.executeForm(*form2);
		delete form2;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		AForm* form3 = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
		Bureaucrat executor("Fry", 1);
		executor.signForm(*form3);
		executor.executeForm(*form3);
		delete form3;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		AForm* failForm = someRandomIntern.makeForm("this does not exist", "nowhere");
		delete failForm;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	delete g;
	delete h; 
	delete i;
	delete j;
	delete k;
}