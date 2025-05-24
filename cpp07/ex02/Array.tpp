/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:57:25 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/24 14:41:06 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(){
	this->_size = 0;
	this->data = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n){
	this->_size = n;
	this->data = new T[n];
}

template <typename T>
Array<T>::Array(const Array &src){
	this->_size = src._size;
	this->data = new T[src._size];
	for (int i = 0; i < this->_size; i++)
		this->data[i] = src.data[i];
}

template <typename T>
Array<T>::~Array(){
	std::cout << "Template class destructor called" << std::endl;
	delete[] this->data;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &src){
	if (this != &src){
		delete[] this->data;
		this->_size = src._size;
		this->data = new T[src._size];
		for (int i = 0; i < this->_size; i++)
			this->data[i] = src.data[i];
	}
	return (*this);
}