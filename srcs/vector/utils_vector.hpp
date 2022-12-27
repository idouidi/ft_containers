/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vector.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:51:18 by idouidi           #+#    #+#             */
/*   Updated: 2022/12/26 20:14:18 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILS_VECTOR_HPP__
# define __UTILS_VECTOR_HPP__

# include <fstream>
# include <cstdlib>
# include <sys/stat.h>
# include <cstring>
# include <iostream>
# include "../../includes/vector.hpp"

# define OK "\033[1;32m[OK]\033[0m"
# define KO "\033[1;31m[KO]\033[0m"

template <class T>
static void printContent(const char * file_name, const char *__name_space__, T &vec)
{
        std::fstream os;

        os.open(file_name, std::fstream::in | std::fstream::out |  std::ios_base::app);

        os << "#    #   #   #   #   #   #   #   #   #   #   #   #\n"<<std::endl; 
        os << __name_space__ << ":" <<  std::endl;
        os << "SIZE     = "   << vec.size() << std::endl;
        os << "MAXSIZE  = " << vec.max_size() << std::endl;
        os << "CAPACITY = " << vec.capacity() << std::endl;
        os << "EMPTY    = " << (vec.empty() ? "true" : "false") << std::endl;

        typename T::iterator it = vec.begin();
        os << "CONTENT  = ";
        for (; it < vec.end(); it++)
            os << "[" << *it << "]";
        os << std::endl;
        os << "#    #   #   #   #   #   #   #   #   #   #   #   #\n"<<std::endl; 
        os.close();
}

template <class T>
const char  *compareContent(const char *file_name, std::vector<T>& stl_vector, ft::vector<T>& ft_vector)
{
    const char *ret;

    printContent(file_name, "STL", stl_vector);
    printContent(file_name, "FT", ft_vector);

    ret = (stl_vector.size() == ft_vector.size()) ? OK : KO; 
    ret = (stl_vector.max_size() == ft_vector.max_size()) ? OK : KO;     
    ret = (stl_vector.capacity() == ft_vector.capacity()) ? OK : KO; 
    ret = (stl_vector.empty() == ft_vector.empty()) ? OK : KO; 
    for (size_t i = 0; i < stl_vector.size(); i++)
		if (ft_vector[i] != stl_vector[i])
				return (KO); 
    return (OK);
}

template <class T>
static void printIterator(const char *file_name, const char * __name_space__, T &vec)
{
    std::fstream os;

    os.open(file_name , std::fstream::in | std::fstream::out |  std::ios_base::app);

    os << __name_space__ << ":" <<  std::endl;
    os << "BEGIN    ->  END:   ";
    typename T::iterator it = vec.begin();
    for (;it != vec.end(); it++)
        os << "[" << *it << "]";
    os << std::endl;

    os << "RBEGIN   ->  REND:  ";
    typename T::reverse_iterator r_it = vec.rbegin();
    for (; r_it != vec.rend(); r_it++)
        os << "[" << *r_it << "]";
    os << std::endl;
    os << std::endl;
    os.close();
}

template <class T>
const char * compareIterator(const char *file_name, std::vector<T>& stl_vector, ft::vector<T>& ft_vector)
{
    const char *ret;
    printIterator(file_name, "STL", stl_vector);
    printIterator(file_name, "FT", ft_vector);
    
    std::cout << "BEGIN:                 " << (ret = (*stl_vector.begin() == *ft_vector.begin() ? OK : KO)) << std::endl;
    std::cout << "END:                   " << (ret = (*(stl_vector.end() - 1) == *(ft_vector.end() - 1) ? OK : KO)) << std::endl;
    std::cout << "RBEGIN:                " << (ret = (*stl_vector.rbegin() == *ft_vector.rbegin() ? OK : KO)) << std::endl;
    std::cout << "REND:                  " << (ret = (*(--stl_vector.rend()) == *(--ft_vector.rend()) ? OK : KO)) << std::endl;
    return (ret);
}


template <class T>
static void printElemAccess(const char *file_name, const char * __name_space__, T &vec)
{
    std::fstream os;

    os.open(file_name , std::fstream::in | std::fstream::out |  std::ios_base::app);

    os << "#    #   #   #   #   #   #   #   #   #   #   #   #\n"<<std::endl; 
    os << __name_space__ << ":" <<  std::endl;
    os << "Operator[2]  = " << vec[2] << std::endl;
    os << "At           = " << vec.at(4) << std::endl;
    os << "Front        = " << vec.front() << std::endl;
    os << "Back         = " << vec.back() << std::endl;
    os << std::endl;
    os << "#    #   #   #   #   #   #   #   #   #   #   #   #\n"<<std::endl; 
     os.close();
}

template <class T>
static void compareElemAccess(const char *file_name, std::vector<T>& stl_vector, ft::vector<T>& ft_vector)
{
    const char *ret;
    printElemAccess(file_name, "STL", stl_vector);
    printElemAccess(file_name, "FT", ft_vector);

    std::cout << "Operator[]             " << (ret = (stl_vector[2] == ft_vector[2] ? OK : KO)) << std::endl;
    std::cout << "At                     " << (ret = (stl_vector.at(4) == ft_vector.at(4) ? OK : KO)) << std::endl;
    std::cout << "Front                  " << (ret = (stl_vector.front() == ft_vector.front() ? OK : KO)) << std::endl;
    std::cout << "Back                   " << (ret = (stl_vector.back()== ft_vector.back() ? OK : KO)) << std::endl;
}

void constructor_tester();

#endif