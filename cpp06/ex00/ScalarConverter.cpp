/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:29:40 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/21 14:59:52 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>

ScalarConverter::ScalarConverter(){
	
}

ScalarConverter::ScalarConverter(const ScalarConverter &src){
	
}

ScalarConverter::ScalarConverter(){
	
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src){
	return (*this);
}



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
	if (!isValidValue(input)) {
		return (false);
	}
	if (input[0] == '-' || input[0] == '+') {
		j++;
	}
	if (j >= input.length() || input[j] == '.') {
		return (false);
	}
	while (j < input.length()) {
		if (input[j] == '.') {
			nbDots++;
		}
		j++;
	}
	if (input[input.length() - 1] == '.') {
		return (false);
	}
	if (nbDots == 1) {
		return (true);
	}
	return (false);
}

static void printBadInput(void){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static void handleCharInput(const std::string &input){
	std::cout << "char: '" << input[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(input[0])<< std::endl;
	std::cout << "float: " << static_cast<float>(input[0]) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
}

static void handleIntInput(const std::string &input, std::istringstream &iss){
	int		value;
	char 	leftover;
	
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
	std::cout << "int: " << static_cast<int>(value)<< std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

static void handleFloatInput(const std::string &input){
	std::string 		pureValue;
	float				value;
	char				garbage;
	int 				k = 0;
	
	while (k < input.length() && input[k] != 'f'){
		pureValue += input[k];
		k++;
	}
	std::istringstream	parsed(pureValue);
	parsed >> value;
	if (parsed.fail()){
		printBadInput();
		return;
	}
	if (parsed >> garbage){
		printBadInput();
		return ;
	}
	if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(value)<< std::endl;
	if (value == static_cast<int>(value))
		std::cout << "float: " << value << ".0f" << std::endl;
	else
		std::cout << "float: " << value << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

static void handleDoubleInput(const std::string &input){
	double parsed;
	std::istringstream out(input);
	out >> parsed;
	if (out.fail()){
		printBadInput();
		return ;
	}
	char leftover;
	if (out >> leftover) {
		printBadInput();
		return;
	}
	if (parsed < 0 || parsed > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(parsed)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(parsed) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(parsed)<< std::endl;
	if (parsed == static_cast<int>(parsed))
		std::cout << "float: " << static_cast<float>(parsed) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(parsed) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(parsed) << std::endl;
}

void ScalarConverter::convert(const std::string &input){
    bool 				number = true;
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
            handleCharInput(input);
            return;
        }
		if (((input[0] == '-' || input[0] == '+') && input.length() > 1) || isdigit(input[0]))
        {
            int i = 0;
			
            if (input[0] == '-' || input[0] == '+')
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
                handleIntInput(input, iss);
				return ;
			}
        }
		if (findDot(input) && input[input.length() - 1] == 'f'){
			handleFloatInput(input);
			return;
		}
		if (findDot(input) && input[input.length() - 1] != 'f'){
			handleDoubleInput(input);
			return ;
		}
		printBadInput();
    }
}
