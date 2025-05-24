/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:26:56 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/24 15:45:04 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

int main(void){
	Array<int> a(5);
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i * 10;

	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << "a[" << i << "] = " << a[i] << std::endl;

	Array<std::string> s(2);
	s[0] = "hello";
	s[1] = "world";
	std::cout << s[0] << " " << s[1] << std::endl;

	Array<int> a2(5);
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i * 10;

	Array<int> b(a);
	a[0] = 999;

	std::cout << "b[0] = " << b[0] << " (should be 0)" << std::endl;

	Array<int> c;
	c = a; // ASSIGNMENT OPERATOR
	a[1] = 888;

	std::cout << "c[1] = " << c[1] << " (should be 10)" << std::endl;

	a = a;
	std::cout << "a[0] = " << a[0] << " (should be 999)" << std::endl;	
	try {
		std::cout << "TRYING OOB" << std::endl;
		std::cout << a[999] << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Caught exception: out-of-bounds access!" << std::endl;
	}
}