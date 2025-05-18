/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:36:37 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/18 14:01:19 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(void){
	ScalarConverter::convert("a");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("42");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("4.2f");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("4.2");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("nan");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("notanumber");
     std::cout << "---------------------" << std::endl;
    ScalarConverter::convert(".42");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("42..");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("-4.2");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("nanf");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("inff");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("inf");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("++42");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("--42");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("127");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("128");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("-1");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("0");
}