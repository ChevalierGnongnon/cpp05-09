/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:01:56 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/15 15:43:17 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>
# include <iostream>

class ScalarConverter{
	private :
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		
		ScalarConverter &operator=(const ScalarConverter &src);
	public :
		static void convert(const std::string &represent);
};

#endif