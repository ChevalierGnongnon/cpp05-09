/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:50:53 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/20 15:10:46 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void){
    Data *d1 = new Data;
    d1->str = "abc";
    d1->test = false;
    d1->valInt = 2;

    uintptr_t test1 = Serializer::serialize(d1);
    std::cout << test1 << std::endl;
    Data *red1 = Serializer::deserialise(test1);
    std::cout << red1->str << " " << red1->test << " " << red1->valInt << std::endl;

    Data *d2 = new Data;
    d2->str = "";
    d2->test = true;
    d2->valInt = -82;

    uintptr_t test2 = Serializer::serialize(d2);
    std::cout << test2 << std::endl;
    Data *red2 = Serializer::deserialise(test2);
    std::cout << red2->str << " " << red2->test << " " << red2->valInt << std::endl;

    Data *d3 = new Data;
    d3->str = "def";
    d3->test = false;
    d3->valInt = +2;

    uintptr_t test3 = Serializer::serialize(d3);
    std::cout << test3 << std::endl;
    Data *red3 = Serializer::deserialise(test3);
    std::cout << red3->str << " " << red3->test << " " << red3->valInt << std::endl;

    delete d1;
    delete d2;
    delete d3;
}