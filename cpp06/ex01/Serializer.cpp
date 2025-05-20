/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:28:14 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/20 14:44:00 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

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