/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftnspace.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 00:33:50 by asimon            #+#    #+#             */
/*   Updated: 2023/02/27 17:44:15 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_NAMESPACE__
# define __FT_NAMESPACE__

# include <iostream>    // for stL
# include <vector>      // for vector
# include <stack>       // for stack
# include <map>         // for map
# include <fstream>     // for fd
# include <cstdlib>     // for exit
# include <cstring>     // for memcmp
# include <sys/stat.h>  // for mdkir
# include <sys/time.h>  // for gettimeofday
# include <iomanip>     //for setw

# include "./iterator.hpp"
# include "./utils.hpp"
# include "./red_black_tree_iterator.hpp"
# include "./red_black_tree.hpp" 
# include "./vector.hpp"
# include "./map.hpp"
# include "./stack.hpp"

# if STD == 1 
#	define NAMESPACE    std
# else
#	define NAMESPACE    ft
# endif 

# define RESET	        "\033[0m"
# define BLACK	        "\033[1;30m"
# define RED	        "\033[1;31m"
# define GREEN	        "\033[1;32m"
# define YELLOW         "\033[1;33m"
# define MAGENTA        "\033[1;35m"
# define CYAN	        "\033[1;36m"

# define OK             "\033[1;32m[OK]\033[0m"
# define KO             "\033[1;31m[KO]\033[0m"

extern  std::string     __NAME_SPACE__;
extern  unsigned long   __CURRENT_TIME__;

/*      *       *       *   FUNCTION TO TEST       *       *       */

unsigned long	        current_time();
void                    printTime(const char *filename);
bool                    compareTime(const char *filename);
int                     compareFile(FILE* f1, FILE* f2);
void                    vector_tester();
void                    stack_tester();
// void                 map_tester();

/*      *       *       *       *       *          *       *       */

/*      *       *       *       VECTOR      *       *       *       */

template <class T>
static void             printIterator(std::fstream  &os, NAMESPACE::vector<T> &vec)
{
    os << "#    #   #   #   #   #   #   #   #   #   #   #   #\n"<<std::endl; 
    os << "BEGIN    ->  END:   ";
    typename NAMESPACE::vector<T>::iterator it = vec.begin();
    for (;it != vec.end(); it++)
        os << "[" << *it << "]";
    os << std::endl;
    os << "RBEGIN   ->  REND:  ";
    typename NAMESPACE::vector<T>::reverse_iterator r_it = vec.rbegin();
    for (; r_it != vec.rend(); r_it++)
        os << "[" << *r_it << "]";
    os << "\n\n#    #   #   #   #   #   #   #   #   #   #   #   #\n"<<std::endl; 
}

template <class T>
static void             printElemAccess(std::fstream &os, NAMESPACE::vector<T> &vec)
{
    os << "#    #   #   #   #   #   #   #   #   #   #   #   #\n"<<std::endl; 
    os << "Operator[2]  = " << vec[2] << std::endl;
    os << "At(4)        = " << vec.at(0) << std::endl;
    os << "Front        = " << vec.front() << std::endl;
    os << "Back         = " << vec.back() << std::endl;
    os << "\n#    #   #   #   #   #   #   #   #   #   #   #   #"<<std::endl; 
}

template <class T>
static void             printContent(const char *filename, const char *msg,  NAMESPACE::vector<T> &vec)
{
    std::fstream os;
    os.open(filename, std::fstream::in | std::fstream::out |  std::ios_base::app);
    if (!os.is_open()) 
    {
        std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (msg)
        os << "\n               " << msg << std::endl;
    os << "#    #   #   #   #   #   #   #   #   #   #   #   #\n"<<std::endl; 
    os << "SIZE     = " << vec.size() << std::endl;
    os << "MAXSIZE  = " << vec.max_size() << std::endl;
    os << "CAPACITY = " << vec.capacity() << std::endl;
    os << "EMPTY    = " << (vec.empty() ? "YES" : "NO")  << std::endl;
    if (vec.size())
    {
        os << std::endl;
        printIterator(os, vec);
        printElemAccess(os, vec);
    }
    else
        os << "\n#    #   #   #   #   #   #   #   #   #   #   #   #\n"<<std::endl;
    os.close();
}

/*      *       *       *       STACK      *       *       *       */  

template <class T>
static void             printCapacity(const char *filename, const char *msg,  NAMESPACE::stack<T> &stk)
{
    std::fstream os;
    os.open(filename, std::fstream::in | std::fstream::out |  std::ios_base::app);
    if (!os.is_open()) 
    {
        std::cerr << "Could not open the file - '" << filename << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (msg)
        os << "\n               " << msg << std::endl;
    os << "#    #   #   #   #   #   #   #   #   #   #   #   #\n"<<std::endl; 
    os << "SIZE     = " << stk.size() << std::endl;
    os << "EMPTY    = " << (stk.empty() ? "YES" : "NO") << std::endl;
    if (stk.size())
        os << "TOP      = " << stk.top() << std::endl;
    os << "\n#    #   #   #   #   #   #   #   #   #   #   #   #\n"<<std::endl;
    os.close();
}
#endif