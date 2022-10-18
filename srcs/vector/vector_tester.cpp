/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tester.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:40:14 by idouidi           #+#    #+#             */
/*   Updated: 2022/10/18 15:22:47 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <vector>
# include "../../includes/vector.hpp"
# include "../../includes/tester.hpp"


//U(*ptr_stl)(my_int = int())

template <class T, typename U>
static bool compAttribute(char *os, std::vector<T>& stl_vector, ft::vector<T>& ft_vector)
{
        os.open(os, std::fstream::in | std::fstream::out | std::fstream::trunc);
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
        std::cout << ((compAttribute("./output/default_constructor", stl_default_vector, ft_default_vector)) ? "\033[1;32m[OK]\033[0m\n" : "\033[1;31m[KO]\033[0m\n");
        os.close();
    }
}
