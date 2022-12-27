/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftnspace.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 00:33:50 by asimon            #+#    #+#             */
/*   Updated: 2022/12/27 18:57:11 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_NAMESPACE__
# define __FT_NAMESPACE__

// # include "header.hpp"

// #include "./vector.hpp"
# include <memory>
# include <cmath>
# include <stdlib.h>

/* lib for exception */
# include <stdexcept>

/* stream lib, std::cout / cin  */
# include <iostream>

/* vector for std */
# include <vector>

/* lib for system fctn */
# include <cstdlib>

/* structur ft::pair */
// # include <pair.hpp>


# if STD == 1 
#	define NAMESPACE std
# else
#	define NAMESPACE ft
# endif 

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

namespace ft{
	
	void		print(NAMESPACE::vector<int> &tab, std::string msg){
		for (size_t i = 0; i < tab.size(); i++){
			std:: cout <<  GREEN << "| " << RESET;
			std::cout << msg << "[" << GREEN << tab[i] << RESET << "]" << std::endl;
		}
		std::cout << std::endl << "capacity: [" << GREEN << tab.capacity() << RESET << "]"<< std::endl;
		std::cout << std::endl << "size: [" << GREEN << tab.size() << RESET << "]" << std::endl;
		std::cout << std::endl << "max size: [" << GREEN << tab.max_size() << RESET << "]" << std::endl;
		std::cout << GREEN << std::string(42, '-') << RESET << std::endl;
	}
	
	void		print( NAMESPACE::vector< NAMESPACE::vector<int> > &tab, std::string msg){
		for (size_t i = 0; i < tab.size(); i++){
			for (size_t j = 0; j < tab.at(i).size(); j++){
				std:: cout <<  GREEN << "| " << RESET;
				std::cout << msg << "[" << GREEN << tab.at(i).at(j) << RESET << "]" << std::endl;
			}
		}
		std::cout << std::endl << "capacity: [" <<  GREEN << tab.capacity() << RESET << "]"<< std::endl;
		std::cout << std::endl << "size: [" << GREEN << tab.size() << RESET << "]" << std::endl;
		std::cout << std::endl << "max size: [" << GREEN << tab.max_size() << RESET << "]" << std::endl;
		std::cout << GREEN << std::string(42, '-') << RESET << std::endl;
	}
	

}

#endif