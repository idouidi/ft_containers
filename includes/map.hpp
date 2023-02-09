/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:02:40 by idouidi           #+#    #+#             */
/*   Updated: 2023/02/09 16:44:29 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_HPP__
#define __MAP_HPP_

# include "./ftnspace.hpp"

namespace ft
{
template <  class Key,
			class T,
			class Compare = std::less<Key>,
			class Alloc = std::allocator<ft::pair<const Key, T> > >
		class map
		{

			public:
				typedef Key															key_type;               // the type of the key in the key value pair;
				typedef T															mapped_type;            // the type of the value in the key value pair
				typedef ft::pair<key_type, mapped_type>								value_type;             // the type of elements contained in the Node
				typedef std::size_t													size_type;
				typedef std::ptrdiff_t												difference_type;
				typedef Compare														key_compare;            // for compare key
				typedef Alloc														allocator_type;         // the allocator used to allocate memory
				typedef typename allocator_type::reference							reference;
				typedef typename allocator_type::const_reference					const_reference;
				typedef typename allocator_type::pointer							pointer;
				typedef typename allocator_type::const_pointer						const_pointer;
				typedef typename ft::reverse_iterator<iterator>						reverse_iterator;
				typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;
				typedef typename ft::Rb_tree<Key, T, Compare, Alloc>				tree;
				typedef typename ft::Rb_tree_iterator<Key, T, Compare, Alloc>		iterator;
				typedef typename ft::Rb_tree_const_iterator<Key, T, Compare, Alloc>	const_iterator;
			
			private:
				key_compare															__comp;
				allocator_type														__alloc;
				tree																__tree;
			
			public:
				class value_compare
				{
					friend class map;
					protected:
						key_compare													comp;
						value_compare() : comp(key_compare()) {}  
						value_compare(key_compare c) : comp(c) {}
					public:
						typedef bool                                                result_type;
						typedef value_type                                          first_argument_type;
						typedef value_type                                          second_argument_type;
						bool operator()(const value_type& x, const value_type& y) const
						{
							return comp(x.first, y.first);
						}
				};
		
				/*	
			*	📌 CONSTRUCTOR / DESTRCUTOR
			*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 default constructor empty container constructor
		explicit map (const key_compare& comp = key_compare(),
		 const allocator_type& alloc = allocator_type())
		 :__comp(comp) , __alloc(alloc)
		 {}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 range constructor
		template <class InputIterator>
		map(InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
		:__comp(comp) , __alloc(alloc)
		{
			this->insert(first, last);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Copy constructor
		map(const map& x) : __comp(x.__comp), __alloc(x.__alloc)
		{
			this->insert(x.begin(), x.end());
		}

// 📚 operator assigning copy
		operator=(const map& x)
		{
			if (this ==&x)
				return (*this);
			this->clear();
			this->insert(x.begin(), x.end());
			return (*this);       
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Destructor
		~map() { this->clear(); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		/*	
		*	📌 ITERATOR
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns an iterator referring to the first element in the map container.
		iterator begin() { return(this->__tree.begin()); }
		const_iterator cbegin() { return (this->__tree.cbegin()); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns an iterator referring to the last element in the map container.
		iterator end() { return(this->__tree.end()); }
		const_iterator cend() { return (this->__tree.cend()); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reverse iterator to the first element of the reversed map. 
// It corresponds to the last element of the non-reversed map. 
		reverse_iterator rbegin() { return (reverse_iterator(this->end())); }
		const_reverse_iterator crbegin() { return (const_reverse_iterator(this->end())); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reverse iterator to the last element of the reversed map. 
// It corresponds to the first element of the non-reversed map. 
		reverse_iterator rend() { return (reverse_iterator(this->begin())); }
		const_reverse_iterator crend() { return (const_reverse_iterator(this->begin())); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		/*	
		*	📌 CAPACITY
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/
	
// 📚 Returns whether the map container is empty (i.e. whether its size is 0).
		bool empty() const { (return (this->__tree.empty())); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns the number of elements in the map container.
		size_type size() const { return (this->__tree.size()); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns the maximum number of elements that the map container can hold.
		size_type max_size() const { return (this->__tree.max_size()); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		/*	
		*	📌 ELEMENT ACCESS
		*/
	
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/
	
 // 📚 If k matches the key of an element in the container, 
 // the function returns a reference to its mapped value.
// If k does not match the key of any element in the container,
// the function inserts a new element with that key and returns a reference to its mapped value.

		// mapped_type& operator[] (const key_type& k)
		// {
		// }


/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/  
	
// 📚 Returns a reference to the mapped value of the element identified with key k.
// If k does not match the key of any element in the container, the function throws an out_of_range exception.

	// mapped_type& at (const key_type& k)
	// {
	// }
	// const mapped_type& at (const key_type& k) const
	// {
	// }


/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/    

		/*	
		*	📌 MODIFIERS
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Extends the container by inserting new elements,
// effectively increasing the container size by the number of elements inserted.

		//
		// pair<iterator,bool> insert (const value_type& val)
		// {
		// }
	
	
	};
}

#endif