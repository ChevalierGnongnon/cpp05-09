/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialiser.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:28:41 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/22 13:12:08 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Serialiser_HPP
# define Serialiser_HPP
# include <cstdint>
# include "Data.hpp"

class Serialiser{
    private:
        Serialiser();
        Serialiser(const Serialiser &src);
        Serialiser &operator=(const Serialiser &src);
        ~Serialiser();
    public:
        static uintptr_t    serialise(Data *ptr);
        static Data        *deserialise(uintptr_t raw);
};

#endif