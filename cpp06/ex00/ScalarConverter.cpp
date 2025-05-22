/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:29:40 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/22 13:00:35 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <limits>

ScalarConverter::ScalarConverter(){
	
}

ScalarConverter::ScalarConverter(const ScalarConverter &src){
	
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src){
	return (*this);
}

ScalarConverter::~ScalarConverter(){
	
}

static bool isValidFloat(const std::string &input) {
	if (input.length() < 4)
		return (false);

	if (input[input.length() - 1] != 'f')
		return (false);

	std::string core = input.substr(0, input.length() - 1);

	// count dots
	int nbDots = 0;
	size_t dotPos = 0;
	bool dotFound = false;
	for (size_t i = 0; i < core.length(); ++i) {
		if (core[i] == '.') {
			nbDots++;
			if (!dotFound) {
				dotPos = i;
				dotFound = true;
			}
		}
	}

	if (nbDots != 1 || dotPos == 0 || dotPos == core.length() - 1)
		return (false);

	bool digitBefore = false;
	bool digitAfter = false;

	size_t i = 0;
	if (core[0] == '+' || core[0] == '-')
		i++;

	for (; i < dotPos; ++i)
		if (isdigit(core[i]))
			digitBefore = true;

	for (size_t j = dotPos + 1; j < core.length(); ++j)
		if (isdigit(core[j]))
			digitAfter = true;

	return (digitBefore && digitAfter);
}


static bool findDot(const std::string &input){
	int nbDots = 0;
	int j = 0;

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
	return (nbDots == 1);
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
	long long check;
	char leftover;

	std::istringstream test(input);
	test >> check;
	if (test.fail() || test >> leftover ||
		check > std::numeric_limits<int>::max() ||
		check < std::numeric_limits<int>::min()) {
		printBadInput();
		return;
	}

	int value = static_cast<int>(check);

	if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

	std::cout << "int: " << value << std::endl;

	std::cout << "float: " << static_cast<float>(value);
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(value);
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << std::endl;
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
	
	std::cout << "float: " << value;
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << "f" << std::endl;
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
	std::cout << "double: " << parsed;
	if (parsed == static_cast<int>(parsed))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &input){
    std::istringstream iss(input);

	if (input == "+inff" || input == "-inff" || input == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
		return;
	}
	if (input == "+inf" || input == "-inf" || input == "nan") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
		return;
	}
	if (input.length() == 1 && isprint(input[0])) {
		handleCharInput(input);
		return;
	}
	if ((((input[0] == '-' || input[0] == '+') && input.length() > 1) || isdigit(input[0]))
		&& !findDot(input)) {
		handleIntInput(input, iss);
		return;
	}
	if (isValidFloat(input)) {
		handleFloatInput(input);
		return;
	}
	if (findDot(input) && input[input.length() - 1] != 'f') {
		handleDoubleInput(input);
		return;
	}
	printBadInput();
}
