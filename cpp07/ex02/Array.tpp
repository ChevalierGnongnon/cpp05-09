/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:42:34 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/24 15:42:36 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

template <typename T>
Array<T>::Array() {
	this->_size = 0;
	this->data = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) {
	this->_size = n;
	this->data = new T[n];
}

template <typename T>
Array<T>::Array(const Array<T> &src) {
	this->_size = src._size;
	this->data = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->data[i] = src.data[i];
}

template <typename T>
Array<T>::~Array() {
	std::cout << "Template class destructor called" << std::endl;
	delete[] this->data;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &src) {
	if (this != &src) {
		delete[] this->data;
		this->_size = src._size;
		this->data = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->data[i] = src.data[i];
	}
	return *this;
}

template <typename T>
unsigned int Array<T>::size() const {
	return this->_size;
}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
	if (i >= this->_size)
		throw std::exception();
	return this->data[i];
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const {
	if (i >= this->_size)
		throw std::exception();
	return this->data[i];
}
