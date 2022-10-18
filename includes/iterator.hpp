/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:28:30 by idouidi           #+#    #+#             */
/*   Updated: 2022/10/18 14:59:38 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __ITERATOR__HPP__
# define __ITERATOR__HPP__


namespace ft
{
    template <class Iterator>
    class iterator_traits
    {

    }

    template <class T>
    class iterator_traits<T*>
    {

    }

    template <class T>
    class iterator_traits<const T*>
    {
        
    }
}

en