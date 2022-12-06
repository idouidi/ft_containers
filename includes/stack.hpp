/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 02:11:41 by idouidi           #+#    #+#             */
/*   Updated: 2022/12/06 18:00:24 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STACK_HPP__
#define __STACK_HPP__

#include "vector.hpp"

namespace ft
{
    template < class T, class Container = ft::vector<T> >
    class stack
    {

        public:
	        typedef Container                               container_type;
            typedef typename container_type::value_type     value_type;
	        typedef typename container_type::size_type      size_type;
        private:
            container_type ctr;

        //MEMBER FUNCTIONS
        explicit    stack( const Container& cont = Container() ) { ctr(cont); };
        bool        empty() const { return ctr.empty(); };
        size_type   size() const { return ctr.size(); };
        void        push( const value_type& value ) { ctr.push_back(value); };

    };
}

#endif