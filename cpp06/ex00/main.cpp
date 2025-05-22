/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:36:37 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/22 13:00:49 by chhoflac         ###   ########.fr       */
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
    std::cout << "---------------------" << std::endl;
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("2147483647");
    ScalarConverter::convert("2147483648");
    ScalarConverter::convert("-2147483648");
    ScalarConverter::convert("-2147483649");

}