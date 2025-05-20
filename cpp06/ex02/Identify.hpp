/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:50:16 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/20 15:51:51 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP
# include "Base.hpp"

Base    *generate(void);
void    identify(Base *p);
void    identify(Base &p);

#endif