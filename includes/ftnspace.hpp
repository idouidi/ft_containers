/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftnspace.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 00:33:50 by asimon            #+#    #+#             */
/*   Updated: 2022/12/29 21:38:55 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_NAMESPACE__
# define __FT_NAMESPACE__


# include "./vector.hpp"
// # include "./stack.hpp"
// # include "./map.hpp"
# include "./utils.hpp"
# include <fstream>
# include <cstdlib>
# include <sys/stat.h>
# include <cstring>
# include <iostream>
# include <vector>
# include <cstddef>

# if STD == 1 
#	define NAMESPACE std
# else
#	define NAMESPACE ft
# endif 

// # include "header.hpp"
// # include <is_integral.hpp>
// # include <enable_if.hpp>
// # include <iterator_traits.hpp>
// # include <iterator.hpp>
// # include <reverse_iterator.hpp> 
// # include <vector.hpp>
// # include <stack.hpp>
// # include <map.hpp>
// # include <Bst.hpp>
// # include <pair.hpp>


# define YELLOW "\033[1;33m"
# define GREEN	"\033[1;32m"
# define RED	"\033[1;31m"
# define BLACK	"\033[1;30m"
# define CYAN	"\033[1;36m"
# define RESET	"\033[0m"

# define OK "\033[1;32m[OK]\033[0m"
# define KO "\033[1;31m[KO]\033[0m"



int compareFile(FILE* f1, FILE* f2);

void vector_tester();


template <class T>
static void printContent(const char *filename, T &vec)
{
     std::fstream os;
     os.open(filename, std::fstream::in | std::fstream::out |  std::ios_base::trunc);

    os << "#    #   #   #   #   #   #   #   #   #   #   #   #\n"<<std::endl; 
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
static void printIterator(const char *filename, T &vec)
{
    std::fstream os;

    os.open(filename , std::fstream::in | std::fstream::out |  std::ios_base::trunc);

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

#endif