/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:57:50 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/21 17:17:14 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T1>
void swap(T1 &a, T1 &b){
    T1 tmp;

    tmp = a;
    a = b;
    b = tmp;
}
template <typename T2>
const T2 &min(T2 const &c, T2 const &d){
    if (c < d)
        return (c);
    return (d);
}
template <typename T3>
const T3 &max(T3 const &e, T3 const &f){
    if (e > f)
        return (e);
    return (f);
}

#endif