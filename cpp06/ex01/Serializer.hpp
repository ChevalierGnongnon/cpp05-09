/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:28:41 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/22 13:17:16 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <cstdint>
# include "Data.hpp"

class Serializer{
    private:
        Serializer();
        Serializer(const Serializer &src);
        Serializer &operator=(const Serializer &src);
        ~Serializer();
    public:
        static uintptr_t    serialize(Data *ptr);
        static Data        *deserialize(uintptr_t raw);
};

#endif