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
# define __VECTOR_HPP__

# include <iostream>
# include <cstddef>
# include "iterator.hpp"
# include "utils.hpp"

namespace ft
{
	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
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
			typedef ft::reverse_iterator<iterator>            			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>           		const_reverse_iterator;
		private:
			Allocator													__alloc;
			pointer														__start;
			pointer														__end;
			pointer														__capacity;
		public:

		/*	
		*	📌 CONSTRUCTOR / DESTRCUTOR
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 empty container constructor (default constructor)
		explicit vector (const allocator_type& alloc = allocator_type())
		: __alloc(alloc), __start(0), __end(0), __capacity(0)
		{}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 fill constructor
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: __alloc(alloc), __start(0), __end(0), __capacity(0)
		{
			__start = __alloc.allocate( n ); //Attempts to allocate a block of storage with a size large enough to contain n of member type value_type.
			__end =	__start;
			for (size_type i = 0; i < n; i++)
			{
				__alloc.construct( __start + i , val ); //Constructs an element object on the location pointed by __start + i.
				__end++;
			}
			__capacity = __start + n;
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 range constructor
		template < class InputIterator, typename ft::enable_if<ft::is_integral<InputIterator>::value, T>::type = true>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): __alloc(alloc)
		{
			difference_type n = ft::distance( first, last );
			__start = __alloc.allocate( n );
			__end =	__start;
			for (difference_type i = 0; i < n; i++)
			{
				__alloc.construct(__start + i, *first);
				__end++;
				first++;
			}
			__capacity = __start + n;
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// Copy constructor
		vector (const vector& x): __alloc(x.__alloc), __start(0), __end(0), __capacity(0)
		{
			this->assign(x.begin(), x.end());
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// Destructor
		~vector()
		{
			this->clear();
			__alloc.deallocate(__start, this->capacity());
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

        /*
        *   📌 MEMBER FUNCTION 
        */

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns an iterator pointing to the first element in the vector.
		iterator				begin() { return (__start); }
		const_iterator			begin() const { return (__start); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns an iterator pointing to the last element in the vector.
		iterator				end() { return (__end); }
		const_iterator			end() const { return (__end); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reverse iterator pointing to the last element in the vector (i.e., its reverse beginning).
		reverse_iterator 		rbegin() { return (reverse_iterator( end() )); }
		const_reverse_iterator 	rbegin() const { return (const_reverse_iterator( end() )); } 

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reverse iterator pointing to the theoretical element preceding the first element 
// in the vector (which is considered its reverse end).
		reverse_iterator 		rend() { return (reverse_iterator( begin())); }
		const_reverse_iterator	rend() const { return (const_reverse_iterator( begin() )); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns the number of elements in the vector.
		size_type 				size() const { return (__end - __start); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns the maximum number of elements that the vector can hold.
// This is the maximum potential size the container can reach due to known system.
		size_type 				max_size() const { return (allocator_type().max_size()); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Resizes the container so that it contains n elements.
		void 					resize (size_type n, value_type val = value_type())
		{
			if (n > this->size())
				insert(end(), n - this->size(), val);
			else
			{
				for (; this->size() > n; __end--)
					__alloc.destroy(__end);
			}
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns the total number of elements that the vector can hold before needing to allocate more memory.
		size_type 				capacity() const { return (__capacity - __start); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns true if the vector is empty.
		bool				 	empty() const { return (size() == 0) };

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Requests that the vector capacity be at least enough to contain n elements.
		void 					reserve (size_type n)
		{
			if (n > this->max_size())
				throw (std::length_error("the parameter is greater than max_size()"));
			else if (n > this->__capacity())
			{
				pointer		tmp_start = __start;
				size_type	tmp_capacity = this->capacity();
				size_type	tnp_size = this->size(); 

				__start = __alloc.construct(n);
				__end = start;
				__capacity = __start + n;

				for (size_type i = 0; i < n; i++)
				{
					__alloc.construct(__start + i, *tmp_start);
					__end++;
					tmp_start++;
				}
				__alloc.deallocate(tmp_start - tmp_size, tmp_capacity);
			}
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reference to the element at position n in the vector container.
		reference 				operator[] (size_type n) { return (*(__start + n)); }
		const_reference 		operator[] (size_type n) const { return (*(__start + n)); } 

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reference to the element at position n in the vector container.
// except that vector::at is bound-checked and signals if the requested position 
// is out of range by throwing an out_of_range exception.
		reference 				at (size_type n)
		{
			if (n >= this->size())
				throw (std::out_of_range("the parameter is greater than size()"));
			return (*(__start + n));
		}
		const_reference 		at (size_type n) const
		{
			if (n >= this->size())
				throw (std::out_of_range("the parameter is greater than size()"));
			return (*(__start + n));	
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reference to the first element in the vector.
		reference 				front() { return *(__start) };
		const_reference			front() const { return *(__start) };

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reference to the last element in the vector.
		reference 				back() { return (*(_end - 1)); }
		const_reference			back() const { return (*(_end - 1)); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.

//In the range version, the new contents are elements constructed from each of the elements in the range 
// between first and last, in the same order.
		template < class InputIterator, typename ft::enable_if<ft::is_integral<InputIterator>::value, T>::type = true>
		void 					assign (InputIterator first, InputIterator last)
		{
			this->clear();
			size_type __dist = (size_type)ft::distance(first, last);
			if (this->capacity() >= dist)
			{
				for (first != last; first++)
					push_back(first);
			}
			else
			{
				__alloc.deallocate(__start, __capacity);
				__start = __alloc.allocate(__dist);
				__end = start;
				__capacity = __start + __dist;
				for (first != last; first++)
					push_back(first);
			}
		}

//In the fill version, the new contents are n elements, each initialized to a copy of val.
		void 					assign (size_type n, const value_type& val)
		{
			this->clear();
			if (this->capacity() >= n)
			{
				for (size_type i = 0; i < n; i++)
				{
					__alloc.construct(__start + i, val);
					__end++;
				}
			}
			else
			{
				__alloc.deallocate(__start, __capacity);
				__start = __alloc.allocate(n);
				__end = start;
				__capacity = __start + n;
				for (size_type i = 0; i < n; i++)
				{
					__alloc.construct(__start + i, val);
					__end++;
				}
			}
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Adds a new element at the end of the vector, after its current last element. 
// The content of val is copied (or moved) to the new element.
		void					push_back (const value_type& val)
		{
			if (__end == __capacity)
				this->reserve(this->size() + 1);
			__alloc.construct(__start + this->size(), val)
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Removes the last element in the vector, effectively reducing the container size by one.
		void					pop_back() { this->resize((this->size() - 1)); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 The vector is extended by inserting new elements before the element at the specified position, 
// effectively increasing the container size by the number of elements inserted.

// Insert an elem val at the position 
		iterator 				insert (iterator position, const value_type& val)
		{
			size_type anchor = position - __start;
			this->insert(position, 1, val);
			return (__start + anchor);
		}

// Insert n elem val at the position
		void 					insert (iterator position, size_type n, const value_type& val)
		{
				if (n > this->max_size())
					throw (std::length_error("the parameter is greater than max_size()"));

			vector<T> vec_tmp(*this);
			this->reserve(this->size() + n);
			size_type anchor = position - __start;

			for (size_type i = anchor ; i < anchor + n; i++)
				__alloc.constructor(__start + i, val);

			for (size_type i = anchor + n; i < this->size() + n; i++)
				__alloc.construct(__start + i, vec_tmp[i - n]);
			if (position == __start)
			__start -= n;
			__end += n;
		}

// Insert the elem in the range [first, last) at the position
		template <class InputIterator, typename ft::enable_if<ft::is_integral<InputIterator>::value, T>::type = true>
		void 					insert (iterator position, InputIterator first, InputIterator last)
		{
			vector<T> vec_tmp(*this);
			size_type dist = (size_type)ft::distance(first, last);
			this->reserve(this->size() + dist);
			size_type anchor = position - __start;

			for (size_type i = anchor ; i < anchor + dist; i++)
			{
				__alloc.constructor(__start + i, first);
				first++;
			}
			for (size_type i = anchor + dist; i < this->size() + dist; i++)
				__alloc.construct(__start + i, vec_tmp[i - n]);
			if (position == __start)
			__start -= n;
			__end += n;
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Removes from the vector either a single element (position) or a range of elements ([first,last)).

// remove a elem at position
		iterator				erase (iterator position)
		{
			size_type anchor = position - __start;

			for (size_type i = anchor; i < this->size(); i++)
			{
				__alloc.destroy(__start + i);
				if (i + 1 < this->size())
					__alloc.construct(__start + i, __start[i + 1]);
			}
			return (position);
		}

// remove elem in the range [first, last) at the position
		iterator 				erase (iterator first, iterator last)
		{
			vector<T> vec_tmp(*this);
			size_type anchor = first - __start;
			size_type  nb_elem = last - first;

			for (size_type i = anchor; i < this->size(); i++)
				__alloc.destroy(__start + i);
			
			for (size_type i = anchor + nb_elem; i < this->size(); i++)
				__alloc.construct(__start + i - nb_elem, vec_tmp[i]);
			__end -= nb_elem;
			return (first);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		void 					clear()
		{
			size_type tmp_size = this->size();
			for (size_type i = 0; i < tmp_size; i++)
			{
				__end--;
				__alloc.destroy(__end);
			}
			
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	: 	:	:	:	*/

		allocator_type 			get_allocator() const { return (__alloc) }; 

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/
	};


/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	: 	:	:	:	*/

// 📚 Performs the appropriate comparison operation between the vector containers lhs and rhs.
		template <class T, class Alloc>  
		bool 					operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		{
			if (lhs.size() != rhs.size())
				return (false);
			for (size_t i = 0; i < rhs.(size); i++)
				if (rhs[i] != lhs[i])
					return (false);
			return (true);
		}

		template <class T, class Alloc>  
		bool 					operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(rhs == lhs)); }


		template <class T, class Alloc>
		bool 					operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			// 🚧 ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

		template <class T, class Alloc>
		bool 					operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(rhs < lhs)); }

		template <class T, class Alloc>
		bool 					operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (rhs < lhs); }

		template <class T, class Alloc>
		bool 					operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs < rhs)); }
	
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	: 	:	:	:	*/

		template <class T, class Alloc>
		void 					swap (vector<T,Alloc>& x, vector<T,Alloc>& y) 
		{
			if ( x != y)
			{
				pointer tmp_start = x.__start;
				pointer tmp_end = x.__end;
				pointer tmp_capacity = x.__capacity;
				Allocator tmp_alloc = x.__alloc;

				x.__start = y.__start; 
				x.__end = y.__end;
				x.__capacity = y.__capacity; 
				x.__alloc = y.__alloc;

				y.__start = tmp_start;
				y.__end = tmp_end;
				y.__capacity = tmp_capacity;
				y.__alloc =  tmp_alloc;
			}
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	: 	:	:	:	*/

}
#endif
