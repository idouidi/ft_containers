/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:17:11 by idouidi           #+#    #+#             */
/*   Updated: 2023/02/24 02:03:00 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __UTILS_HPP__
# define __UTILS_HPP__

# include <iostream>

namespace ft
{

/*     :      :      :   ENABLE_IF    :      :      :		:		:
:
: 📚 This is useful to hide signatures on compile time when a particular 
: condition is not met, since in this case, the member enable_if::type will 
: not be defined and attempting to compile using it should fail.
:      :      :      :      :      :      :      :      :		*/
	template < bool Cond, class T = void>
	struct enable_if {};

	template < class T > 
	struct enable_if< true , T > { typedef T type; };



/*     :      :      :   IS_INTEGRAL    :      :      :		:		:
:
: 📚 class that identifies whether T is an integral type.
:
:     :      :      :	:		:		:      :      :		:		*/

	template < class T, T v>
	struct integral_constant
	{
		static const T                      value = v;
		typedef T       					value_type;
		typedef integral_constant< T, v > 	type;
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
	struct integral_type< short int > : public true_type {} ;

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



/*     :      :      :   EQUAL   :      :      :		:		:		:
:
: 📚 Compares the elements in the range [first1,last1) with those in the range
: beginning at first2, and returns true if all of the elements in both ranges match.
:
:     :      :      :	:		:		:      :      :		:		*/
	template < class InputIterator1, class InputIterator2 >
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		for (; first1 != last1; ++first1, ++first2)
			    if (!(*first1 == *first2))
      				return false;
		return true;
	}

	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return (first2 == last2);
	}

/*     :      :      :   LEXICOGRAPHICAL_COMPARE   :      :      	:
:
: 📚 Returns true if the range [first1,last1) compares 
: lexicographically less than the range [first2,last2).
:     :      :      :   :	:      :      :		:		:			: */
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, 
								InputIterator2 first2, InputIterator2 last2)
	{
 		while (first1!=last1)
  		{
    		if (first2 == last2 || *first2 < *first1)
				return (false);
    		else if (*first1 < *first2)
				return (true);
    		++first1;
			++first2;
  		}
  		return (first2!=last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
            while (first1 != last1)
            {
                if (first2 == last2 || comp(*first2, *first1))
					return (false);
                else if (comp(*first1, *first2))
					return (true);
                ++first1;
                ++first2;
            }
            return (first2 != last2);		
	}

/*     :      :      :   PAIR   :      :      :		:		:		:
:
: 📚 This class couples together a pair of values, which may be of 
: different types (T1 and T2). The individual values can be accessed through 
: its public members first and second.
:
:     :      :      :	:		:		:      :      :		:		*/
	template < class T1, class T2>
	struct pair
	{
		public:
		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		pair(): first(), second() {};

		pair (const first_type& a, const second_type& b): first(a), second(b) {};
	
		template <class U, class V>
		pair(const pair<U, V>& pr): first(pr.first), second(pr.second) {};

		pair& operator=(const pair& pr) 
		{
			first = pr.first;
			second = pr.second;
			return *this;
		}

		~pair(){}

	};
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/
	template < class T1, class T2 >
	ft::pair< T1, T2 > make_pair(T1 x, T2 y) { return (ft::pair< T1, T2 >(x, y)); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

	template <class _T1, class _T2>
	bool operator==(const ft::pair<_T1,_T2>& x, const ft::pair<_T1,_T2>& y)
	{
		return x.first == y.first && x.second == y.second;
	}

	template <class _T1, class _T2>
	bool operator!=(const ft::pair<_T1,_T2>& x, const ft::pair<_T1,_T2>& y)
	{
		return !(x == y);
	}

	template <class _T1, class _T2>
	bool operator< (const ft::pair<_T1,_T2>& x, const ft::pair<_T1,_T2>& y)
	{
		return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
	}

	template <class _T1, class _T2>
	bool operator> (const ft::pair<_T1,_T2>& x, const ft::pair<_T1,_T2>& y)
	{
		return y < x;
	}

	template <class _T1, class _T2>
	bool operator>=(const ft::pair<_T1,_T2>& x, const ft::pair<_T1,_T2>& y)
	{
		return !(x < y);
	}

	template <class _T1, class _T2>
	bool operator<=(const ft::pair<_T1,_T2>& x, const ft::pair<_T1,_T2>& y)
	{
		return !(y < x);
	}

/*     :      :      :   UTILS FUNCTIONS    :      :       :
:
:		:		:		:		:		:		:		:		*/
   template < class InputIterator >
    typename ft::iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last)
    {
        typename ft::iterator_traits<InputIterator>::difference_type distIt = 0;
        for(; first != last; first++, distIt++)
			;
		return(distIt);
    }
}

#endif