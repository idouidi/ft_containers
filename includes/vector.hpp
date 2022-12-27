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


# include "iterator.hpp"
# include "utils.hpp"
# include <iostream>
# include <vector>
# include <cstddef>

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
			size_type													__size;
			size_type													__capacity;
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
		{
			__alloc = alloc;
			(n % 2 != 0) ? __capacity = n + 1 : __capacity = n; 
			__start = __alloc.allocate( __capacity ); //Attempts to allocate a block of storage with a size large enough to contain n of member type value_type.
			__size = n;
			for (size_type i = 0; i < n; i++)
				__alloc.construct( __start + i , val ); //Constructs an element object on the location pointed by __start + i.
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 range constructor
		template < class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, T>::type * = 0): __alloc(alloc)
		{
			difference_type n = ft::distance( first, last );
			__start = __alloc.allocate( n );
			__size = n;
			__capacity = n;
			for (difference_type i = 0; i < n; i++)
			{
				__alloc.construct(__start + i, *first);
				first++;
			}
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// Copy constructor
		vector (const vector& x)
		{
			this->__alloc = x.__alloc;
			// this->__start = this->__alloc.allocate(x.__capacity);
			this->__size = x.__size;
			this->__capacity = x.__capacity;

			pointer vec_tmp = this->__alloc.allocate(x.__capacity);

			for (size_type i = 0; i < x.__size; i ++)
				__alloc.construct(vec_tmp + i, *(x.__start + i));
			this->__start = vec_tmp;
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// Destructor
		~vector()
		{
			this->clear();
			__alloc.deallocate(this->begin(), this->capacity());
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
		iterator				end() { return (__start + __size); }
		const_iterator			end() const { return (__start + __size); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reverse iterator pointing to the last element in the vector (i.e., its reverse beginning).
		reverse_iterator 		rbegin() { return (reverse_iterator(end())); }
		const_reverse_iterator 	rbegin() const { return (const_reverse_iterator(end())); } 

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reverse iterator pointing to the theoretical element preceding the first element 
// in the vector (which is considered its reverse end).
		reverse_iterator 		rend() { return (reverse_iterator(begin())); }
		const_reverse_iterator	rend() const { return (const_reverse_iterator(begin())); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns the number of elements in the vector.
		size_type 				size() const { return (this->__size); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns the maximum number of elements that the vector can hold.
// This is the maximum potential size the container can reach due to known system.
		size_type 				max_size() const { return (__alloc.max_size()); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Resizes the container so that it contains n elements.
		void 					resize (size_type n, value_type val = value_type())
		{
			if (n > this->size())
			{
				(this->capacity() * 2 >= n) ? 
					this->reserve(this->capacity() * 2) : this->reserve(n);

				for (size_type i = this->size(); i < n; i++)
					push_back(val);
			}
			else
			{
				for (size_type tmp_size = this->size(); tmp_size > n; tmp_size--)
					pop_back();
			}
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns the total number of elements that the vector can hold before needing to allocate more memory.
		size_type 				capacity() const { return (this->__capacity); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns true if the vector is empty.
		bool				 	empty() const { return (this->size() == 0); };

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Requests that the vector capacity be at least enough to contain n elements.
		void 					reserve (size_type n)
		{
			if (n > this->max_size())
				throw (std::length_error("the parameter is greater than max_size()"));
			else if (n > this->capacity())
			{
				pointer		tmp_start = __alloc.allocate(n);
				size_type	tmp_capacity = this->capacity();

				for (size_type i = 0; i < n && i < this->size(); i++)
					__alloc.construct(tmp_start + i, __start[i]);
				
				for (size_type i = 0; i < n && i < this->size(); i++)
					__alloc.destroy(__start + i);
				
				__alloc.deallocate(__start, tmp_capacity);
				__capacity = n;
				__start = tmp_start;
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
		reference 				front() { return *(__start); }
		const_reference			front() const { return *(__start); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reference to the last element in the vector.
		reference 				back() { return  ((__size) ?_  *(__start + __size - 1) : *(__start + __size)) ; }
		const_reference			back() const { return ((__size) ?  *(__start + __size - 1) : *(__start + __size)) ; }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.

//In the range version, the new contents are elements constructed from each of the elements in the range 
// between first and last, in the same order.
		template < class InputIterator>
		void 					assign (InputIterator first, InputIterator last,
								typename ft::enable_if<!ft::is_integral<InputIterator>::value, T>::type * = 0)
		{
			this->clear();
			for (;first != last; first++)
				push_back(*first);

		}

//In the fill version, the new contents are n elements, each initialized to a copy of val.
		void 					assign (size_type n, const value_type& val)
		{
			this->clear();
			for (size_type i = 0; i < n; i++)
				push_back(val);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Adds a new element at the end of the vector, after its current last element. 
// The content of val is copied (or moved) to the new element.
		void					push_back (const value_type& val)
		{
			if (this->size() + 1 > this->capacity())
				this->reserve(this->capacity() * 2);
			__alloc.construct(__start + __size, val);
			__size += 1;
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Removes the last element in the vector, effectively reducing the container size by one.
		void					pop_back() 
		{ 
			__alloc.destroy(__start[__size - 1]);
			this->__size--;
		
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 The vector is extended by inserting new elements before the element at the specified position, 
// effectively increasing the container size by the number of elements inserted.

// Insert an elem val at the position 
		iterator 				insert (iterator position, const value_type& val)
		{
			if (n > this->max_size())
				throw (std::length_error("the parameter is greater than max_size()"));

			size_type anchor = position - __start;
	
			ft::vector<T> tmp_vec(*this);

			this->clear();
			if (postion == this->end())
			{
				push_back(val);
				return (position);
			}	
				
			for (size_type i = 0; i < tmp_vec.size(); i++)
			{
				if (i == anchor)
					push_back(val);
				push_back(tmp_vec[i]);
			}
			return (__start + anchor);
		}

// Insert n elem val at the position
		void 					insert (iterator position, size_type n, const value_type& val)
		{

			for (size_type i = 0; i < n; i++)
				this->insert(position, val);
		}

// Insert the elem in the range [first, last) at the position
		template <class InputIterator>
		void 					insert (iterator position, InputIterator first, InputIterator last,
								typename ft::enable_if<!ft::is_integral<InputIterator>::value, T>::type * = 0)
		{
			for (; first != last; first++, position++)
				this->insert(position, *first);
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
			__end -= 1;
			return (position);
		}

// remove elem in the range [first, last) at the position
		iterator 				erase (iterator first, iterator last)
		{
			difference_type dist = ft::distance(first, last);

			for (difference_type i = 0; i < dist; i++)
				this->erase(first);
			return (first);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Exchanges the content of the container by the content of x, which is another vector object of the same type. 
// Sizes may differ.
		void swap (vector& x)
		{
			if ( x != *this)
			{
				pointer tmp_start = __start;
				pointer tmp_end = __end;
				pointer tmp_capacity = __capacity;
				Allocator tmp_alloc = __alloc;

				__start = x.__start; 
				__end = x.__end;
				__capacity = x.__capacity; 
				__alloc = x.__alloc;

				x.__start = tmp_start;
				x.__end = tmp_end;
				x.__capacity = tmp_capacity;
				x.__alloc =  tmp_alloc;
			}
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
		void 					clear()
		{
			while(this->size())
				pop_back();
			
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	: 	:	:	:	*/

// 📚 Returns a copy of the allocator object associated with the vector.
		allocator_type 			get_allocator() const { return (__alloc); } 
	};

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	: 	:	:	:	*/

// 📚 Performs the appropriate comparison operation between the vector containers lhs and rhs.
		template <class T, class Alloc>  
		bool 					operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			if (lhs.size() != rhs.size())
				return (false);
			for (size_t i = 0; i < rhs.size(); i++)
				if (rhs[i] != lhs[i])
					return (false);
			return (true);
		}

		template <class T, class Alloc>  
		bool 					operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(rhs == lhs)); }

		template <class T, class Alloc>
		bool 					operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		template <class T, class Alloc>
		bool 					operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(rhs < lhs)); }

		template <class T, class Alloc>
		bool 					operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (rhs < lhs); }

		template <class T, class Alloc>
		bool 					operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs < rhs)); }
	
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	: 	:	:	:	*/

// 📚 Exchanges the content of the container by the content of x, which is another vector object of the same type. 
// Sizes may differ.

		template <class T, class Alloc>
		void 					swap (vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	: 	:	:	:	*/

}
#endif


