/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:28:14 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/21 15:03:34 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){
    
}

Serializer::Serializer(const Serializer &src){
    
}

Serializer::~Serializer(){
    
}

Serializer &Serializer::operator=(const Serializer &src){
    
}

uintptr_t    Serializer::serialize(Data *ptr){
    uintptr_t res;

    res = reinterpret_cast<uintptr_t>(ptr);
    
    return (res);
}

Data        *Serializer::deserialise(uintptr_t raw){
    Data *res;

    res = reinterpret_cast<Data *>(raw);

    return (res);
}


