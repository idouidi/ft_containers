/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tester.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:40:14 by idouidi           #+#    #+#             */
/*   Updated: 2022/10/15 21:49:20 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <vector>
# include "../../includes/vector.hpp"
# include "../../includes/tester.hpp"

template <class T>
static bool compAttribute( std::fstream& os, std::vector<T>& stl_vector, ft::vector<T>& ft_vector)
{
    
}

void vector_tester()
{
    mkdir("./output", 0777);
    std::fstream os;

    std::cout<< "\033[1;31m             = = =>      VECTOR      <= = =\033[0m\n\n";

    std::cout<< "\033[1;33m + CONSTRUCTOR + \033[0m\n";
    std::cout<< "Default Constructor:\n";
    {
        std::vector<int> stl_default_vector;
        ft::vector<int> ft_default_vector;
        os.open("./output/default_constructor", std::fstream::in | std::fstream::out | std::fstream::trunc);
        std::cout << ((compAttribute(os, stl_default_vector, ft_default_vector)) ? "\033[1;32m[OK]\033[0m\n" : "\033[1;31m[KO]\033[0m\n");
        os.close();
    }
}
