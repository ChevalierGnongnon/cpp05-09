/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:35:17 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/20 16:47:28 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

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

void    identify(Base *p){
    
}

void    identify(Base &p){
    
}