/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tester.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:23:15 by idouidi           #+#    #+#             */
/*   Updated: 2023/01/17 20:55:18 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include  "../../../includes/ftnspace.hpp"

void vector_constructor_tester();
void vector_iterator_tester();
void vector_capacity_tester();
void vector_elem_access_tester();
// void vector_modifier_tester();

void vector_tester()
{
    std::srand(time(NULL));

    STD !=  1 ?  std::cout<< "\n" << MAGENTA << "        = = =>      VECTOR      <= = =\n" << RESET << std::endl : 0;

    vector_constructor_tester();
    vector_iterator_tester();
    vector_capacity_tester();
    vector_elem_access_tester();
    // vector_modifier_tester();
}
