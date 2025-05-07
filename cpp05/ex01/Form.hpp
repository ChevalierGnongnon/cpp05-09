/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:30:44 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/07 09:16:52 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include "Bureaucrat.hpp"

class Form {
	private :
		const std::string	name;
		bool 				isSigned;
		const int			sign_grade;
		const int			execute_grade;
	public :
		Form();
		Form(const std::string name, int signGrade, int executeGrade);
		Form(const Form &src);
		~Form();

		Form &operator=(const Form &src);
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		const std::string getName() const;
		bool getIsSigned() const;
		const int getSignGrade() const;
		const int getExecuteGrade()const;

		void	beSigned(Bureaucrat &signer);
};

std::ostream &operator<<(std::ostream &out, const Form &src);

#endif