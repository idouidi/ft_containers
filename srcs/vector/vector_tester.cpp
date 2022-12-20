/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tester.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:40:14 by idouidi           #+#    #+#             */
/*   Updated: 2022/12/20 20:24:54 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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



void vector_tester()
{
    std::srand(time(NULL));
    std::cout<< "\n\033[1;31m             = = =>      VECTOR      <= = =\033[0m\n\n";

    std::cout<< "\033[1;33m + CONSTRUCTOR + \033[0m\n";
    
    std::cout<< "Default Constructor:   ";
    {
        std::vector<int> stl_vector;
        ft::vector<int> ft_vector;
        std::cout << (compareContent("./srcs/vector/output/Default_constructor", stl_vector, ft_vector))<< std::endl;
    }

    std::cout<< "Fill Constructor:      ";
    {
        std::vector<int> stl_vector(7);
        ft::vector<int> ft_vector(7);
        std::cout << (compareContent("./srcs/vector/output/Fill_constructor", stl_vector, ft_vector))<< " ";

        std::vector<int> stl_vector_val(7, 42);
        ft::vector<int> ft_vector_val(7, 42);
        std::cout << (compareContent("./srcs/vector/output/Fill_constructor", stl_vector_val, ft_vector_val))<< std::endl;
    }

    std::cout<< "Range Constructor:     ";
    {
        int randArray[5];
        
        for(int i = 0; i < 5; i++)
            randArray[i]=rand()%100;

        std::vector<int>::iterator stl_it(&randArray[2]);
        ft::vector<int>::iterator ft_it(&randArray[2]);
    
        std::vector<int> stl_vector(stl_it, stl_it + 3);
        ft::vector<int> ft_vector(ft_it, ft_it + 3);
        std::cout << (compareContent("./srcs/vector/output/Range_constructor", stl_vector, ft_vector))<< std::endl;
    }
    
    std::cout<< "Copy Constructor:      ";
    {
        int randArray[5];

        for(int i = 0; i < 5; i++)
            randArray[i]=rand()%100;

        std::vector<int>::iterator stl_it(&randArray[0]);
        ft::vector<int>::iterator ft_it(&randArray[0]);
    
        std::vector<int> stl_vector(stl_it, stl_it + 5);
        ft::vector<int> ft_vector(ft_it, ft_it + 5);

        std::vector<int> stl_vector_copy(stl_vector);
        ft::vector<int> ft_vector_copy(ft_vector);
        if (!std::strcmp(compareContent("./srcs/vector/output/Copy_constructor", stl_vector, ft_vector) , OK ) && (ft_vector == ft_vector_copy))
            std::cout << OK << std::endl;
        else
            std::cout << KO << std::endl;
    }

    std::cout<< "\n\033[1;33m + ITERATOR + \033[0m\n";
    {
       int         randArray[5];

       for(int i = 0; i < 5; i++)
           randArray[i]=rand()%100;

       std::vector<int>::iterator stl_it(&randArray[0]);
       ft::vector<int>::iterator ft_it(&randArray[0]);

       std::vector<int> stl_vector(stl_it, stl_it + 5);
       ft::vector<int> ft_vector(ft_it, ft_it + 5);

       compareIterator("./srcs/vector/output/Iterator", stl_vector, ft_vector);
    }
    
    std::cout << "\n\033[1;33m + CAPACITY + \033[0m\n";
    {
        int randArray[5];
        const char *ret; 

        for(int i = 0; i < 5; i++)
            randArray[i]=rand()%100;

        std::vector<int>::iterator stl_it(&randArray[0]);
        ft::vector<int>::iterator ft_it(&randArray[0]);

        std::vector<int> stl_vector(stl_it, stl_it + 5);
        ft::vector<int> ft_vector(ft_it, ft_it + 5);
        printContent("./srcs/vector/output/Capacity", "STL", stl_vector);
        printContent("./srcs/vector/output/Capacity", "FT", ft_vector);

        std::cout << "SIZE:                  " <<((stl_vector.size() == ft_vector.size()) ? OK : KO) << std::endl; 
        std::cout << "MAXSIZE:               " <<((stl_vector.max_size() == ft_vector.max_size()) ? OK : KO) << std::endl;     
        std::cout << "CAPACITY               " <<((stl_vector.capacity() == ft_vector.capacity()) ? OK : KO) << std::endl; 
        std::cout << "EMPTY:                 " <<((stl_vector.empty() == ft_vector.empty()) ? OK : KO) << std::endl; 

        /* RESIZE WITH N < SIZE() */
        stl_vector.resize(3);
        ft_vector.resize(3);
        printIterator("./srcs/vector/output/Capacity", "STL", stl_vector);
        printIterator("./srcs/vector/output/Capacity", "FT", ft_vector);

        ret = (*stl_vector.begin() == *ft_vector.begin() ? OK : KO);
        ret = (*(stl_vector.end() - 1) == *(ft_vector.end() - 1) ? OK : KO);
        std::cout << "RESIZE:                " << (!std::strcmp(ret, OK) ? OK : KO) << " ";
        
        /* RESIZE WITH N > SIZE() */
        stl_vector.resize(6, 42);
        ft_vector.resize(6, 42);
        printIterator("./srcs/vector/output/Capacity", "STL", stl_vector);
        printIterator("./srcs/vector/output/Capacity", "FT", ft_vector);

        ret = (*stl_vector.begin() == *ft_vector.begin() ? OK : KO);
        ret = (*(stl_vector.end() - 1) == *(ft_vector.end() - 1) ? OK : KO);
        std::cout << (!std::strcmp(ret, OK) ? OK : KO) << std::endl;


    }
}
