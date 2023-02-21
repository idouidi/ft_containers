/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:02:40 by idouidi           #+#    #+#             */
/*   Updated: 2023/02/21 21:00:53 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_HPP__
# define __MAP_HPP__

// # include "./ftnspace.hpp"			// my test

# include "red_black_tree.hpp"			// tester

namespace ft
{
template <  class Key,
			class T,
			class Compare = std::less<Key>,
			class Alloc = std::allocator<ft::pair<const Key, T> > >
		class map
		{

			public:
				typedef Key																			key_type;               // the type of the key in the key value pair;
				typedef T																			mapped_type;            // the type of the value in the key value pair
				typedef ft::pair<key_type, mapped_type>												value_type;             // the type of elements contained in the Node
				typedef std::size_t																	size_type;
				typedef std::ptrdiff_t																difference_type;
				typedef Compare																		key_compare;            // for compare key
				typedef Alloc																		allocator_type;         // the allocator used to allocate memory
				typedef typename allocator_type::reference											reference;
				typedef typename allocator_type::const_reference									const_reference;
				typedef typename allocator_type::pointer											pointer;
				typedef typename allocator_type::const_pointer										const_pointer;
				typedef typename ft::Rb_tree<Key, T, Compare, Alloc>								tree;
				typedef typename tree::iterator														iterator;
				typedef typename tree::const_iterator												const_iterator;
				typedef typename ft::reverse_iterator<iterator>										reverse_iterator;
				typedef typename ft::reverse_iterator<const_iterator>								const_reverse_iterator;
			
			private:
				key_compare																			__comp;
				allocator_type																		__alloc;
				tree																				__tree;
			
			public:
				class value_compare
				{
					friend class map;
					protected:
						key_compare																	comp;
						value_compare() : comp(key_compare()) {}  
						value_compare(key_compare c) : comp(c) {}
					public:
						typedef bool                                                				result_type;
						typedef value_type                                          				first_argument_type;
						typedef value_type                                          				second_argument_type;
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
		map& operator=(const map& x)
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
		reverse_iterator rbegin() { return (reverse_iterator(this->__tree.end())); }
		const_reverse_iterator crbegin() { return (const_reverse_iterator(this->__tree.end())); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reverse iterator to the last element of the reversed map. 
// It corresponds to the first element of the non-reversed map. 
		reverse_iterator rend() { return (reverse_iterator(this->__tree.begin())); }
		const_reverse_iterator crend() { return (const_reverse_iterator(this->t__tree.begin())); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		/*	
		*	📌 CAPACITY
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/
	
// 📚 Returns whether the map container is empty (i.e. whether its size is 0).
		bool empty() const { return (this->__tree.empty()); }

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

		mapped_type& operator[] (const key_type& k)
		{
			return	(*((insert(ft::make_pair(k, mapped_type()))).first)).second;
		}


/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/  
	
// 📚 Returns a reference to the mapped value of the element identified with key k.
// If k does not match the key of any element in the container, the function throws an out_of_range exception.

	mapped_type& at(const key_type& k)
	{
		iterator node = find(k);
	
		if (!node)
			throw (std::out_of_range("map::at"));
		return (node->__pair.second);
	}

	const mapped_type& at (const key_type& k) const
	{
		const_iterator node = find(k);

		if (!node)
			throw (std::out_of_range("map::at"));
		return (node->__pair.second);
	}


/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/    

		/*	
		*	📌 MODIFIERS
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Extends the container by inserting new elements,
// effectively increasing the container size by the number of elements inserted.

//📚 Value to be copied to (or moved as) the inserted element.
		pair<iterator, bool> insert (const value_type& val)
		{
			ft::pair<iterator, bool> ret_pair = this->__tree.insert(val);

			return (ret_pair);
		}
// 📚 Hint for the position where the element can be inserted.
		iterator insert(iterator position, const value_type& val)
		{
			ft::pair<iterator, bool> ret_pair = this->__tree.insert(val);
			position = ret_pair.first;
			return (position);
		}

// 📚 Iterators specifying a range of elements. Copies of the elements in the range [first,last) 
// are inserted in the container.
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, T>::type* = 0)
		{
			for(; first != last; first++)
				insert(*first);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Removes from the map container element

// 📚 Iterator pointing to a single element to be removed from the map.
		void erase (iterator position)
		{ 
			this->__tree.erase(position); 
		}

// 📚 Key of the element to be removed from the map.
		size_type erase (const key_type& k)
		{
			iterator node = this->__tree.find(k);

			if (node)
			{
				(this->__tree.erase(node));
				return (1);
			}
			return  (0);
		}

// 📚 Iterators specifying a range within the map container to be removed: [first,last).
		void erase (iterator first, iterator last)
		{
			iterator	tmp;

			while (first != last) 
			{
				tmp = first;
				first++;
				erase(tmp);
			}
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ.
		void swap(map& x){ this->__tree.swap(x.__tree); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.
		void clear() { this->__tree.clear(); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a copy of the comparison object used by the container to compare keys.
		key_compare key_comp() const { return (key_compare()); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a comparison object that can be used to compare two elements to get whether 
// the key of the first one goes before the second.
		value_compare value_comp() const { return (value_compare(key_comp())); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/
	
// 📚 Searches in the conatiner for an element with a key equivalent to k and returns 
// an iterator to it if found, otherwise it returns an iterator to end().
		iterator find(const key_type& k) { return (this->__tree.find(k)); }

		const_iterator find(const key_type& k) const { return (this->__tree.find(k)); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Searches the container for elements with a key equivalent to k and returns the number of matches.
		size_type count (const key_type& k) const { return (this->__tree.count(k)); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns an iterator pointing to the first element in the container whose key is 
// not considered to go before k (i.e., either it is equivalent or goes after).
		iterator lower_bound(const key_type& k) {return (this->__tree.lower_bound(k)); }

		const_iterator lower_bound(const key_type& k) const {return (this->__tree.lower_bound(k)); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns an iterator pointing to the first element in the container whose key 
// is considered to go after k.
		iterator upper_bound (const key_type& k) { return (this->__tree.upper_bound(k)); }

		const_iterator upper_bound(const key_type& k) const { return (this->__tree.upper_bound(k)); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns the bounds of a range that includes all the elements in the container
// which have a key equivalent to k. Because the elements in a map container have unique keys, 
// the range returned will contain a single element at most.
		pair<iterator,iterator> equal_range (const key_type& k) { return (this->__tree.equal_range(k)); }

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const { return (this->__tree.equal_range(k)); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		/*	
		*	📌 ALLOCATOR
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a copy of the allocator object associated with the map
		allocator_type	get_allocator() const { return (this->__tree.get_allocator()); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/
	};
}

#endif