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

# include "./iterator.hpp"
# include "./utils.hpp"
# include "./ftnspace.hpp"


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
			typedef T*													iterator;
			typedef const T* 											const_iterator;
			typedef ft::reverse_iterator<iterator>            			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>           		const_reverse_iterator;

		/*	
		*	📌 CONSTRUCTOR / DESTRCUTOR
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 default constructor empty container constructor
		explicit vector (const allocator_type& alloc = allocator_type())
		: __alloc(alloc), __start(0), __size(0), __capacity(0)
		{}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 fill constructor
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): __alloc(alloc)
		{
			this->__capacity = n;
			this->__start = __alloc.allocate( this->__capacity ); //Attempts to allocate a block of storage with a size large enough to contain n of member type value_type.
			for (size_type i = 0; i < n; i++)
				__alloc.construct(this->__start + i , val); //Constructs an element object on the location pointed by __start + i.
			this->__size = n;
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 range constructor
		template < class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, T>::type * = 0): __alloc(alloc)
		{
			difference_type n = ft::distance(first, last);
			this->__start = __alloc.allocate(n);
			this->__size = n;
			this->__capacity = n;
			for (difference_type i = 0; i < n; i++)
			{
				__alloc.construct(this->__start + i, *first);
				first++;
			}
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// Copy constructor
		vector (const ft::vector<T> &x): __alloc(x.__alloc), __size(x.__size), __capacity(x.__capacity)
		{

			pointer vec_tmp = this->__alloc.allocate(x.__capacity);

			for (size_type i = 0; i < x.__size; i++)
				__alloc.construct(vec_tmp + i, *(x.__start + i));
			this->__start = vec_tmp;
		}

		vector<T>& operator=(const ft::vector<T> &other)
		{
			if (this->__capacity == other.__capacity && this->__start == other.__start)
				return (*this);
			if (this->__capacity)
				this->__alloc.deallocate(this->__start, this->__capacity);
			vector<T> tmp_vec(other);
			*this = tmp_vec;
			return(*this);
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
		iterator				begin() { return (this->__start); }
		const_iterator			begin() const { return (this->__start); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns an iterator pointing to the last element in the vector.
		iterator				end() { return (this->__start + this->__size); }
		const_iterator			end() const { return (this->__start + this->__size); }

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
		size_type 				max_size() const { return (this->__alloc.max_size()); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Resizes the container so that it contains n elements.
		void 					resize (size_type n, value_type val = value_type())
		{
			if (n + this->size()> this->capacity())
			{
				(this->size() * 2 >= n) ? this->reserve(this->size() * 2) : this->reserve(n);
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
				pointer		tmp_start = this->__alloc.allocate(n);
				size_type	tmp_capacity = this->capacity();

				for (size_type i = 0; i < n && i < this->size(); i++)
					__alloc.construct(tmp_start + i, __start[i]);
				
				for (size_type i = 0; i < n && i < this->size(); i++)
					this->__alloc.destroy(this->__start + i);
				
				this->__alloc.deallocate(this->__start, tmp_capacity);
				this->__capacity = n;
				this->__start = tmp_start;
			}
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reference to the element at position n in the vector container.
		reference 				operator[] (size_type n) { return (*(this->__start + n)); }
		const_reference 		operator[] (size_type n) const { return (*(this->__start + n)); } 

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reference to the element at position n in the vector container.
// except that vector::at is bound-checked and signals if the requested position 
// is out of range by throwing an out_of_range exception.
		reference 				at (size_type n)
		{
			if (n >= this->size())
				throw (std::out_of_range("the parameter is greater than size()"));
			return (*(this->__start + n));
		}
		const_reference 		at (size_type n) const
		{
			if (n >= this->size())
				throw (std::out_of_range("the parameter is greater than size()"));
			return (*(this->__start + n));	
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reference to the first element in the vector.
		reference 				front() { return *(this->__start); }
		const_reference			front() const { return *(this->__start); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reference to the last element in the vector.
		reference 				back() { return  ((this->__size) ?  *(this->__start + this->__size - 1) : *(this->__start + this->__size)) ; }
		const_reference			back() const { return ((this->__size) ?  *(this->__start + this->__size - 1) : *(this->__start + this->__size)) ; }

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
				(!this->__size) ? this->reserve(1) : this->reserve(this->size() * 2);
			this->__alloc.construct(this->__start + this->__size, val);
			this->__size += 1;
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Removes the last element in the vector, effectively reducing the container size by one.
		void					pop_back() 
		{ 
			this->__alloc.destroy(this->__start + this->__size - 1);
			this->__size--;
		
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 The vector is extended by inserting new elements before the element at the specified position, 
// effectively increasing the container size by the number of elements inserted.

// Insert an elem val at the position 
		iterator 				insert (iterator position, const value_type& val)
		{
			size_type anchor = position - this->__start;
	
			ft::vector<T> tmp_vec(*this);

			if (anchor == tmp_vec.size())
			{
				push_back(val);
				return (position);
			}
			this->clear();
			for (size_type i = 0; i < tmp_vec.size(); i++)
			{
				if (i == anchor)
					push_back(val);
				push_back(tmp_vec[i]);
			}
			return (this->__start + anchor);
		}

// Insert n elem val at the position
		void 					insert (iterator position, size_type n, const value_type& val)
		{
			if (n > this->max_size())
				throw (std::length_error("the parameter is greater than max_size()"));

			size_type dist = ft::distance(this->__start, position);
			if (n + this->size() > this->capacity())
				(this->size() * 2 >= this->size() + n) ? this->reserve(this->size() * 2) : this->reserve(this->size() + n);
	
			for (size_type i = 0; i < n; i++)
				this->insert(this->__start + dist, val);
		}

// Insert the elem in the range [first, last) at the position
		template <class InputIterator>
		void 					insert (iterator position, InputIterator first, InputIterator last,
								typename ft::enable_if<!ft::is_integral<InputIterator>::value, T>::type * = 0)
		{
			if (ft::distance(first, last) + this->size() > this->max_size())
				throw (std::length_error("the parameter is greater than max_size()"));

			size_type dist_position = ft::distance(this->__start, position);
			size_type dist_elem = ft::distance(first, last);

			if (this->size() + dist_elem > this->capacity())
				(this->size() * 2 >= this->size() + dist_elem) ? this->reserve(this->size() * 2) : this->reserve(this->size() + dist_elem);

			for (; first != last; first++, dist_position++)
				this->insert(this->__start + dist_position, *first);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Removes from the vector either a single element (position) or a range of elements ([first,last)).

// remove a elem at position
		iterator				erase (iterator position)
		{
			size_type anchor = position - this->__start;

			for (size_type i = anchor; i < this->size(); i++)
			{
				this->__alloc.destroy(this->__start + i);
				if (i + 1 < this->size())
					this->__alloc.construct(this->__start + i, this->__start[i + 1]);
			}
			this->__size--;
			return (position);
		}

// remove elem in the range [first, last) at the position
		iterator 				erase (iterator first, iterator last)
		{
			difference_type dist = ft::distance(first, last);

			for (difference_type i = 0; i < dist; i++)
			{
				this->erase(first);
				first++;
			}
			return (first);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Exchanges the content of the container by the content of x, which is another vector object of the same type. 
// Sizes may differ.
		void swap (vector& x)
		{
			if ( x != *this)
			{
				pointer		tmp_start = this->__start;
				size_type	tmp_size = this->__size;
				size_type	tmp_capacity = this->__capacity;
				Allocator	tmp_alloc = this->__alloc;

				this->__start = x.__start; 
				this->__size = x.__size;
				this->__capacity = x.__capacity; 
				this->__alloc = x.__alloc;

				x.__start = tmp_start;
				x.__size = tmp_size;
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
		allocator_type 			get_allocator() const { return (this->__alloc); } 

		private:
			Allocator													__alloc;
			pointer														__start;
			size_type													__size;
			size_type													__capacity;
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


