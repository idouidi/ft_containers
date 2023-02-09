/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:06:45 by idouidi           #+#    #+#             */
/*   Updated: 2023/02/09 16:58:38 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __RED_BLACK_TREE_HPP__
# define __RED_BLACK_TREE_HPP__

# include "./ftnspace.hpp"

namespace ft
{
	template <typename Key, typename Value>
	struct Node
	{
		typedef typename ft::pair<Key, Value>   pair_type;
		typedef Key                             key_type;
		typedef Value                           value_type;
		typedef ft::Node<key_type, value_type>  node_type;

		node_type								*__parent;
		node_type								*__left;
		node_type								*__right;
		pair_type								__pair;
		bool									__isBlack;
		bool									__isLeftChlid;


		/*	
		*	📌 CONSTRUCTOR / DESTRCUTOR
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 default constructor
		Node(): __parent(0x0), __left(0x0), __right(0x0), __isBlack(false),
		__isLeftChlid(false)
		{
			pair_type	tmp;
			__pair = tmp;
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 fill constructor
		Node(Key k, Value v): __parent(0x0), __left(0x0), __right(0x0), __isBlack(false),
		__isLeftChlid(false)
		{
			pair_type	tmp(k, v);
			__pair = tmp;
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Copy constructor
		Node(const Node& n): __parent(n.__parent), __left(n.__left), __right(n.__right),
		__isBlack(n.__isBlack), __isLeftChlid(n.__isLeftChlid), __pair(n.pair)
		{}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Destructor
		~Node() {}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 relational operator
			bool		operator==(node_type const & n) const 
			{
				return (this->pair.first == n.pair.first && this->pair.second == n.pair.second);
			}
			
			bool		operator<(node_type const & n) const 
			{
				if (this->pair.first == n.pair.first)
					return (this->pair.second < n.pair.second);
				return (this->pair.first < n.pair.first);
			}

			bool		operator<=(node_type const & n) const 
			{
				return (this->pair.first <= n.pair.first);
			}

			bool		operator>(node_type const & n) const 
			{
				return (n < this);
			}
			
			bool		operator>=(node_type const & n) const 
			{
				return (n <= this);
			}

			bool		operator!=(node_type const & n) const 
			{
				return (!(this == n));
			}

	};
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/	

	template <typename Key, typename Value, typename Compare, class Allocator>
	class Rb_tree
	{
		public:
			typedef Key												key_type;
			typedef Value											value_type;
			typedef Compare											key_compare;
			typedef Allocator										allocator_type;
			typedef ft::Node<key_type, value_type>					node;
			typedef std::size_t										size_type;
			typedef typename ft::Rb_tree_iterator<Node>				iterator;
			typedef typename ft::Rb_tree_const_iterator<Node>		const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;

        /*	
		*	📌 CONSTRUCTOR / DESTRCUTOR
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/	

// 📚 default constructor
		Rb_tree(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		 :__comp(comp) , __alloc(alloc), __root(0x0), __size(0)
		{}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Destructor
		~Rb_tree()
		{
			clear_tree(__root);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns whether the tree is empty: i.e. whether its size is zero.
		bool		empty() const { return (this->__size == 0); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns the number of Nodes in the tree.
		size_type	size() const { return (this->__size); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns the maximum number of elements that the tree can hold.
// This is the maximum potential size the tree can reach due to known system.
		size_type	max_size const { return (this->__alloc.max_size()); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/


/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		private:
			key_compare												__comp;
			allocator_type											__alloc;
			node													*__root;
			size_type												__size;
	};

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/
}

#endif