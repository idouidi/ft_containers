/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:44:29 by idouidi           #+#    #+#             */
/*   Updated: 2022/10/15 21:17:42 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TESTER_HPP__
# define __TESTER_HPP__

# include <iostream>
# include <fstream>
# include <string>

template <class T>
std::string equal(const T& t1, const T& t2)
{
    return (t1 == t2 ? "✔" : "✘");
}

void vector_tester();

#endif