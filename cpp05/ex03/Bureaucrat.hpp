/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:58:29 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/12 13:51:26 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>

class AForm;

class Bureaucrat {
	private :
		const std::string	name;
		int					grade;
	public :
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();
		
		Bureaucrat &operator=(const Bureaucrat &src);
		
		void				gradeUp();
		void				gradeDown();
		
		const std::string 	getName() const;
		int					getGrade() const;
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		void signForm(AForm &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src);

#endif