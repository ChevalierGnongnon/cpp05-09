/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:35:17 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/20 17:05:20 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base    *generate(void){
    int res = rand() % 3;
    Base *ret = NULL;
    
    switch (res){
        case 0:
            ret = new A();
            break ;
        case 1:
            ret = new B();
            break;
        case 2:
            ret = new C();
            break;
        default :
            break;
    }
    return (ret);
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "C" << std::endl;
    }
    else {
        std::cout << "Unknown Type" << std::endl;
    }
}

void    identify(Base &p){
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    } catch (std::bad_cast&) {
        
    }
    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    } catch (std::bad_cast&) {
        
    }
    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    } catch (std::bad_cast&) {

    }
    
}