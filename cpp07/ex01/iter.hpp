/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:42:29 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/21 18:16:52 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T>
void iter(T *arr, int length, void (*func)(T const &)){
    for (int i = 0; i < length; i++){
        func(arr[i]);
    }
}

template <typename T2>
void printElement(T2 const &x) {
    std::cout << x << std::endl;
}

#endif