/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:29:40 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/16 17:31:31 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &input){
    bool number = true;
    bool negate = false;
    
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
        if (input[0] == '-')
            negate = true;
        if ((input[0] == '-' && input.length() > 1) || isdigit(input[0]))
        {
            int i = 0;
            if (input[0] == '-')
                i++;
            while (i < input.length()){
                if (!isdigit(input[i])){
                    number = false;
                }
                i++;
            }
            if (!number){
                
            }
            else {
                
            }
        }
    }
}
