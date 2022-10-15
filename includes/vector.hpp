/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 03:17:33 by idouidi           #+#    #+#             */
/*   Updated: 2022/10/15 21:51:43 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <iostream>

namespace ft
{
	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
		/*
		*	*	*	*	*	*		MEMBER TYPE		*	*	*	*	*	*	*	*
		*/
		public:
			typedef T           										value_type;
			typedef Allocator											allocator_type;
			typedef typename std::size_t 								size_type;
			typedef typename std::ptrdiff_t 							difference_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef T *													iterator;
			typedef const T* 											const_iterator;
			// typedef typename reverse_iterator<iterator>            		reverse_iterator;
			// typedef typename reverse_iterator<const_iterator>           const_reverse_iterator;
		private:
			Allocator													__alloc;
			pointer														__start;
			pointer														__end;
		public:
		/*
		*	*	*	*	*	*		MEMBER FUNCTION		*	*	*	*	*	*	*	*
		*/

		/*	
		*	CONSTRUCTOR
		*/

		// ~ empty container constructor (default constructor)
		explicit vector (const allocator_type& alloc = allocator_type())
		: __alloc(alloc), __start(0), __end(0)
		{}


		// ~ fill constructor
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: __alloc(alloc), __start(0), __end(0)
		{
			__start = __alloc.allocate( n ); //Attempts to allocate a block of storage with a size large enough to contain n of member type value_type.
			__end =	__start;
			for (size_type i = 0; i < n; i++)
				__alloc.construct( __start + i , val ); //Constructs an element object on the location pointed by __start + i.
			__end = n;
		}

		// ~ range constructor
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

		vector (const vector& x);

		// DESTRUCTOR 
		~vector();

		// ITERATOR
		iterator				begin();
		const_iterator			begin() const;

		iterator				end();
		const_iterator			end() const;

		// reverse_iterator 		rbegin();
		// const_reverse_iterator 	rbegin() const;

		// reverse_iterator 		rend();
		// const_reverse_iterator	rend() const;

		// SIZE
		size_type 				size() const;

		size_type 				max_size() const;
		void 					resize (size_type n, value_type val = value_type());

		size_type 				capacity() const;

		bool				 	empty() const;

		void 					reserve (size_type n);

		//ELEMEMT ACCESS
		reference 				operator[] (size_type n);
		const_reference 		operator[] (size_type n) const;

		reference 				at (size_type n);
		const_reference 		at (size_type n) const;

		reference 				front();
		const_reference			front() const;
		
		reference 				back();
		const_reference			back() const;

		// value_type* 			data() noexcept;
		// const value_type* 		data() const noexcept;

		// MODIFIER
		template <class InputIterator>
		void 					assign (InputIterator first, InputIterator last);
		void 					assign (size_type n, const value_type& val);

		void					push_back (const value_type& val);
		void					pop_back();

		iterator 				insert (iterator position, const value_type& val);
		void 					insert (iterator position, size_type n, const value_type& val);
		template <class InputIterator>
		void 					insert (iterator position, InputIterator first, InputIterator last);

		iterator				erase (iterator position);
		iterator 				erase (iterator first, iterator last);

		void 					clear();

		//ALLOCATOR
		allocator_type 			get_allocator() const; 
	};

	// OPERATOR
		template <class T, class Alloc>  
		bool 					operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

		template <class T, class Alloc>  
		bool 					operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

		template <class T, class Alloc>
		bool 					operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

		template <class T, class Alloc>
		bool 					operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

		template <class T, class Alloc>
		bool 					operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

		template <class T, class Alloc>
		bool 					operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	
	//SWAP
		template <class T, class Alloc>
		void 					swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
}
#endif