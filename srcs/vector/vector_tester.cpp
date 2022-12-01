/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tester.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:40:14 by idouidi           #+#    #+#             */
/*   Updated: 2022/12/01 18:10:50 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fstream>
# include <sys/stat.h>
# include <iostream>

# include "../../includes/vector.hpp"

# define OK "\033[1;32m[OK]\033[0m\n"
# define KO "\033[1;31m[KO]\033[0m\n"

template <class T>
static void printContent(const char * file_name, const char *__name_space__, T vec)
{
        std::fstream os;

        os.open(file_name, std::fstream::in | std::fstream::out | std::fstream::trunc);

        os << __name_space__ << ":" <<  std::endl;
        os << "SIZE = "   << vec.size() << std::endl;
        os << "MAXSIZE = " << vec.max_size() << std::endl;
        os << "CAPACITY = " << vec.capacity() << std::endl;
        os << "EMPTY = " << (vec.empty() ? "true" : "false") << std::endl;

        typename T::iterator it = vec.begin();
        for (; it < vec.end(); it++)
            os << "[" << *it << "]";
        std::cout << std::endl; 
        os.close();
}

template <class T>
static bool compareContent(const char *file_name, std::vector<T> stl_vector, ft::vector<T> ft_vector)
{
    bool ret;

    printContent(file_name, "STL", stl_vector);
    printContent(file_name, "FT", ft_vector);

    ret = (stl_vector.size() == ft_vector.size()) ? 0 : 1; 
    ret = (stl_vector.max_size() == ft_vector.max_size()) ? 0 : 1;     
    ret = (stl_vector.capacity() == ft_vector.capacity()) ? 0 : 1; 
    ret = (stl_vector.empty() == ft_vector.empty()) ? 0 : 1; 
    //ret = (stl_vector == ft_vector) ? 0 : 1; 

    return (ret);
}

void vector_tester()
{
    mkdir("./output", 0777);

    std::cout<< "\033[1;31m             = = =>      VECTOR      <= = =\033[0m\n\n";

    std::cout<< "\033[1;33m + CONSTRUCTOR + \033[0m\n";
    
    std::cout<< "Default Constructor:\n";
    {
        std::vector<int> stl_vector;
        ft::vector<int> ft_vector;
        std::cout << ((compareContent("./output/default_constructor", stl_vector, ft_vector)) ? OK : KO ) << std::endl;
    }
}
