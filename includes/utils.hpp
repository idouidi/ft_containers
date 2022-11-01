/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:33:06 by idouidi           #+#    #+#             */
/*   Updated: 2022/11/01 13:14:10 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILS_HPP__
# define __UTILS_HPP__

namespace ft
{

   /*      *       *       *   ENABLE_IF     *       *       *		*		*
	*
   	* This is useful to hide signatures on compile time when a particular 
	* condition is not met, since in this case, the member enable_if::type will 
	* not be defined and attempting to compile using it should fail.
    *       *       *       *       *       *       *       *       *		*/
	template < bool Cond, class T = void>
	struct enable_if {};

	template < class T > 
	struct enable_if< true , T > { typedef T type; };

   /*      *       *       *   IS_INTEGRAL     *       *       *		*		*
	*
	* class that identifies whether T is an integral type.
	*      *       *       *   IS_INTEGRAL     *       *       *		*		*/

	template < class T, T v>
	struct integral_constant
	{
		static const T                      value = v;
		typedef T       					value_type;
		typedef integral_constant< T, v > 	type;
		const operator T() { return v; }
	};

	typedef integral_constant< bool, true > true_type;
	typedef integral_constant< bool, false > false_type;

	template < class >
	struct integral_type : public false_type {} ;

	template <>
	struct integral_type< bool > : public true_type {} ;

	template <>
	struct integral_type< char > : public true_type {} ;

	template <>
	struct integral_type< signed char > : public true_type {} ;

	template <>
	struct integral_type<short int > : public true_type {} ;

	template <>
	struct integral_type< int > : public true_type {} ;

	template <>
	struct integral_type< long int > : public true_type {} ;

	template <>
	struct integral_type< long long int > : public true_type {} ;

	template <>
	struct integral_type< unsigned char > : public true_type {} ;

	template <>
	struct integral_type< unsigned short int > : public true_type {} ;

	template <>
	struct integral_type< unsigned int > : public true_type {} ;

	template <>
	struct integral_type< unsigned long int > : public true_type {} ;

	template <>
	struct integral_type< unsigned long long int > : public true_type {} ;

	template < class T>
	struct is_integral : public integral_type<T> {};

}

#endif