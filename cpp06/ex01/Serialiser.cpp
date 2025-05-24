/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialiser.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:28:14 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/22 13:12:16 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialiser.hpp"

Serialiser::Serialiser(){
    
}

Serialiser::Serialiser(const Serialiser &src){
    
}

Serialiser::~Serialiser(){
    
}

Serialiser &Serialiser::operator=(const Serialiser &src){
    return (*this);
}

uintptr_t    Serialiser::serialise(Data *ptr){
    uintptr_t res;

    res = reinterpret_cast<uintptr_t>(ptr);
    
    return (res);
}

Data        *Serialiser::deserialise(uintptr_t raw){
    Data *res;

    res = reinterpret_cast<Data *>(raw);

    return (res);
}


