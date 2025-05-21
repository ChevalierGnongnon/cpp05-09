/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:27:46 by chhoflac          #+#    #+#             */
/*   Updated: 2025/05/21 15:20:26 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Identify.hpp"
#include <ctime>
#include <cstdlib>

int main(void){
    srand(time(NULL));
    Base *tab[10];
    
    for (int i = 0; i < 10; i++){
        tab[i] = generate();
    }

    for (int j = 0; j < 10; j++){
        identify(tab[j]);
        identify(*tab[j]);
    }

    for (int k = 0; k < 10; k++){
        delete tab[k];
    }
}