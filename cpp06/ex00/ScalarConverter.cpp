/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:29:40 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/17 18:12:07 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>

static bool isValidValue(const std::string &input){
	for (int i = 0; i < input.length(); i++){
		if (!isdigit(input[i]) && input[i] != '-'
			&& input[i] != '+' && input[i] != '.'
			&& !(input[i] == 'f' && i == input.length() - 1)){
				return (false);
			}
	}
	return (true);
}

static bool findDot(const std::string &input){
	int nbDots = 0;
	int j = 0;
	
	if (!isValidValue(input)){
		return (false);
	}
	if (input[0] == '-' || input[0] == '+')
		j++;
	if (input[j] == '.'){
		std::cerr << "Error ! invalid input" << std::endl;
		return (false);
	}
	while ( j < input.length()){
		if (input[j] == '.'){
			nbDots++;
		}
		j++;
	}
	if (input[input.length() - 1] == '.') {
		std::cerr << "Error ! invalid input" << std::endl;
		return false;
	}
	if (nbDots == 1)
		return (true);
	std::cerr << "Error ! invalid input" << std::endl;
	return(false);
}

static void printBadInput(void){
	std::cout << "char: imposssible" << std::endl;
	std::cout << "int: imposssible" << std::endl;
	std::cout << "float: imposssible" << std::endl;
	std::cout << "double: imposssible" << std::endl;
}

void ScalarConverter::convert(const std::string &input){
    bool 				number = true;
    bool				negate = false;
	std::istringstream	iss(input);
    
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
				printBadInput();
				return;
            }
            else {
                int		value;
				char 	leftover;
				char	c;
				
				iss >> value;
				if (iss.fail()){
					printBadInput();
					return;
				}
				if (iss >> leftover){
					printBadInput();
					return;
				}
				if (value < 0 || value > 127)
					std::cout << "char: impossible" << std::endl;
				else if (!isprint(static_cast<char>(value)))
					std::cout << "char: Non displayable" << std::endl;
				else
					std::cout << "char: " << static_cast<char>(value) << std::endl;
				c = static_cast<char>(value);
				std::cout << "int: " << static_cast<int>(value)<< std::endl;
				std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
				std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
				return ;
			}
        }
		if (findDot(input) && input[input.length() - 1] == 'f'){
			std::string 		pureValue;
			float				value;
			char				garbage;
			int 				k = 0;
			
			while (k < input.length() && input[k] != 'f'){
				pureValue += input[k];
				k++;
			}
			std::istringstream	parsed(input);
			parsed >> value;
			if (parsed.fail()){
				printBadInput();
				return;
			}
			if (parsed >> garbage){
				printBadInput();
				return ;
			}
			std::cout << "char: " << input << std::endl;
            std::cout << "int: " << static_cast<int>(input[0])<< std::endl;
            std::cout << "float: " << static_cast<float>(input[0]) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
			
		}
		if (findDot(input) && input[input.length() - 1] != 'f'){
			
		}
		
    }
}
