/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tester.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:52:37 by idouidi           #+#    #+#             */
/*   Updated: 2023/01/25 15:16:31 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include  "../../../includes/ftnspace.hpp"

void stack_member_func_tester();

void stack_tester()
{
    if (STD != 1)
        std::cout<< "\n\n" << MAGENTA << "        = = =>      STACK      <= = =\n" << RESET << std::endl;
    
    stack_member_func_tester();
}