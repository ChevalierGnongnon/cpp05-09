/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:29:40 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/16 15:48:35 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &input){
	if (input == "+inff" || input == "nanf" || input == "-inff"){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input << std::endl;
        std::cout << "double: " << input << std::endl;
        return ;
    }
    else if (input == "nan" || input == "+inf" || input == "-inf"){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input << "f" << std::endl;
        std::cout << "double: " << input << std::endl;
        return;
    }
    else {
        if (input.length() == 1 && isprint(input[0])){
            std::cout << "char: " << input << std::endl;
            std::cout << "int: " << static_cast<int>(input[0])<< std::endl;
            std::cout << "float: " << static_cast<float>(input[0]) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
            return;
        }
        
    }
}
