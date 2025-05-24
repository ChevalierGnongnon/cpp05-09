/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:30:03 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/24 13:32:56 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array{
	private:
		T 				*data;;
		unsigned int	_size;
		
	public:
		Array();
		Array (unsigned int n);
		~Array();
		Array(const Array &src);
		Array &operator = (const Array &src);
	
};

#endif
#include "Array.tpp"