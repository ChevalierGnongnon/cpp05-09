/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:30:44 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/11 17:10:37 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP
# include <string>
# include "Bureaucrat.hpp"

class AForm {
	private :
		const std::string	name;
		bool 				isSigned;
		const int			sign_grade;
		const int			execute_grade;
	public :
		AForm();
		AForm(const std::string name, int signGrade, int executeGrade);
		AForm(const AForm &src);
		virtual ~AForm();

		AForm &operator=(const AForm &src);
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FileCreationException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		const std::string getName() const;
		bool getIsSigned() const;
		const int getSignGrade() const;
		const int getExecuteGrade()const;

		void	beSigned(Bureaucrat &signer);
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &src);

#endif