/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:06:45 by idouidi           #+#    #+#             */
/*   Updated: 2023/02/25 23:15:52 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __RED_BLACK_TREE_HPP__
# define __RED_BLACK_TREE_HPP__

// # include "./ftnspace.hpp"					// my test

# include "red_black_tree_iterator.hpp"	// tester
# include "utils.hpp"					// tester

namespace ft
{
	
	template <typename Key, typename Value>
	struct Node
	{
		typedef ft::pair<Key, Value>			pair_type;
		typedef ft::Node<Key, Value>			node_type;

		pair_type								__pair;
		node_type*								__parent;
		node_type*								__left;
		node_type*								__right;
		bool									__isBlack;
		bool									__isLeftChild;


		/*	
		*	📌 CONSTRUCTOR / DESTRCUTOR
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 default constructor
		Node(const Key k, const Value v): __pair(k, v), __parent(0x0), __left(0x0), __right(0x0), __isBlack(false),
		__isLeftChild(false)
		{}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Copy constructor
		Node(const Node& n): __pair(n.__pair), __parent(n.__parent), __left(n.__left), __right(n.__right),
		__isBlack(n.__isBlack), __isLeftChild(n.__isLeftChild)
		{}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Destructor
		~Node() {}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 relational operator
			bool		operator==(const node_type& n) const 
			{
				return (this->__pair.first == n.__pair.first && this->__pair.second == n.__pair.second);
			}
			
			bool		operator<(const node_type& n) const 
			{
				if (this->__pair.first == n.__pair.first)
					return (this->__pair.second < n.__pair.second);
				return (this->__pair.first < n.__pair.first);
			}

			bool		operator<=(const node_type& n) const 
			{
				return (this->__pair.first <= n.__pair.first);
			}

			bool		operator>(const node_type& n) const 
			{
				return (n < this);
			}
			
			bool		operator>=(const node_type& n) const 
			{
				return (n <= this);
			}

			bool		operator!=(const node_type& n) const 
			{
   				 return (this->__pair.first != n->__pair.first || this->__pair.second != n.__pair.second);
			}
	};

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/	

	template <typename Key, typename T, typename Compare, class Allocator>
	class Rb_tree
	{
		public:
			typedef Key																key_type;
			typedef T																value_type;
			typedef Compare															key_compare;
			typedef Allocator														allocator_type;
			typedef std::size_t														size_type;
			typedef ft::Node<key_type, value_type>									node_type;
			typedef typename allocator_type::template rebind<node_type>::other 		node_alloc; //redifine type of the allocation
			typedef typename node_type::pair_type									pair_type;
			typedef typename ft::Rb_tree_iterator<node_type>						iterator;
			typedef typename ft::Rb_tree_const_iterator<node_type>					const_iterator;
			typedef typename ft::reverse_iterator<iterator>							reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>					const_reverse_iterator;

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		/*	
		*	📌 CONSTRUCTOR / DESTRCUTOR
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/	

// 📚 default constructor
		Rb_tree(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(), const node_alloc& Node_alloc = node_alloc() )
		 :__comp(comp) , __node_alloc(Node_alloc), __alloc(alloc),__root(0x0), __sentinel(0x0) ,__size(0)
		{
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Destructor
		~Rb_tree()
		{
			this->clear();
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		/*	
		*	📌 ITERATORS
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns an iterator (i.e a node) referring to the first element in the tree.
		iterator begin()
		{
			node_type *tmp = this->__root;
			if (tmp)
			{
				while (tmp->__left)
					tmp = tmp->__left;
				
			}
			return (iterator(tmp));
		}

		const_iterator begin() const
		{
			node_type *tmp = this->__root;
			if (tmp)
			{
				while (tmp->__left)
					tmp = tmp->__left;
			}
			return (const_iterator(tmp));
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns an iterator (i.e a node) referring to the last element in the tree.

		node_type *find_end()
		{
			node_type *tmp = this->__root;
			if (tmp)
			{
				while (tmp->__right)
					tmp = tmp->__right;
			}
			return (tmp);

		}
		iterator end()
		{
			return (iterator(this->__sentinel));
		}

		const_iterator end() const
		{
			node_type *tmp = this->__root;
			if (tmp)
			{
				while (tmp->__right)
					tmp = tmp->__right;
			}
			return (const_iterator(tmp));
		}
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		reverse_iterator	rbegin(void) { return (reverse_iterator(this->end())); }

		const_reverse_iterator	rbegin(void) const { return (const_reverse_iterator(this->end())); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		/*	
		*	📌 CAPACITY
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns whether the tree is empty: i.e. whether its size is zero.
		bool		empty() const { return (this->__size == 0); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/
// 📚 Returns the number of tree's node
		size_type	size() const { return (this->__size); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns the maximum number of elements that the tree can hold.
// This is the maximum potential size the tree can reach due to known system.
		size_type	max_size() const { return (this->__alloc.max_size()); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/	

		/*	
		*	📌 MODIFIERS
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 The purpose of this function is to find the appropriate location
// for the new node, by comparing the key with the keys of the current nodes.
// If a similar key is found, it returns an iterator to that existing node and a boolean false 
// indicating that the insertion did not occur. If the appropriate location is found, the function allocates a new node, 
// initializes its fields and inserts it into the tree. Finally, it calls a function called insert_fixup to ensure 
// that the properties of the red-black tree are maintained.

	void fix_insert(node_type* node)
	{
	    // tant que le parent du nœud nouvellement inséré est rouge
	    while (node->__parent && node->__parent->__isBlack == false)
	    {
	        // si le parent du nœud nouvellement inséré est le fils gauche du grand-parent
	        if (node->__parent == node->__parent->__parent->__left)
	        {
	            // pointeur vers l'oncle
	            node_type* uncle = node->__parent->__parent->__right;
	            // cas 1 : l'oncle est rouge
	            if (uncle && uncle->__isBlack == false)
	            {
	                node->__parent->__isBlack = true;
	                uncle->__isBlack = true;
	                node->__parent->__parent->__isBlack = false;
	                node = node->__parent->__parent;
	            }
	            else
	            {
	                // cas 2 : l'oncle est noir et le nœud nouvellement inséré est le fils droit de son parent
	                if (node == node->__parent->__right)
	                {
	                    node = node->__parent;
	                    left_rotate(node);
	                }
	                // cas 3 : l'oncle est noir et le nœud nouvellement inséré est le fils gauche de son parent
	                node->__parent->__isBlack = true;
	                node->__parent->__parent->__isBlack = false;
	                right_rotate(node->__parent->__parent);
	            }
	        }
	        else // le parent du nœud nouvellement inséré est le fils droit du grand-parent
	        {
	            // pointeur vers l'oncle
	            node_type* uncle = node->__parent->__parent->__left;
	            // cas 1 : l'oncle est rouge
	            if (uncle && uncle->__isBlack == false)
	            {
	                node->__parent->__isBlack = true;
	                uncle->__isBlack = true;
	                node->__parent->__parent->__isBlack = false;
	                node = node->__parent->__parent;
	            }
	            else
	            {
	                // cas 2 : l'oncle est noir et le nœud nouvellement inséré est le fils gauche de son parent
	                if (node == node->__parent->__left)
	                {
	                    node = node->__parent;
	                    right_rotate(node);
	                }
	                // cas 3 : l'oncle est noir et le nœud nouvellement inséré est le fils droit de son parent
	                node->__parent->__isBlack = true;
	                node->__parent->__parent->__isBlack = false;
	                left_rotate(node->__parent->__parent);
	            }
	        }
	    }
	    // la racine de l'arbre doit être noire
	    __root->__isBlack = true;
	}

	ft::pair<iterator, bool> insert(const pair_type& p)
	{
		node_type 	*parent = this->__root;
    	node_type 	*current = this->__root;
    	bool 		isLeft = false;


    		
    	while (current)
    	{
        	parent = current;
        	if (this->__comp(p.first, current->__pair.first))
        	{
        	    current = current->__left;
        	    isLeft = true;
        	}
        	else if (this->__comp(current->__pair.first, p.first))
        	{
        	    current = current->__right;
        	    isLeft = false;
        	}
        	else
        	    return ft::pair<iterator, bool>(iterator(current), false);
    	}

		if (this->__sentinel == 0x0)
			this->__sentinel =  this->__node_alloc.allocate(sizeof(node_type));

    	current = this->__node_alloc.allocate(sizeof(node_type));
    	this->__node_alloc.construct(current, node_type(p.first, p.second));
		current->__parent = parent;
    	
		if (parent == 0x0)
		{
    	    this->__root = current;
			this->__node_alloc.construct(this->__sentinel, node_type(current->__pair.first, current->__pair.second));
		}
    	else if (isLeft)
		{
    	    current->__parent->__left = current;
			current->__isLeftChild = true;
			current->__isBlack = false;
		}
    	else
		{
			current->__parent->__right = current;
			current->__isLeftChild = false;
			current->__isBlack = true;
		}
		if (current == find_end())
		{
			current->__right = this->__sentinel;
			this->__sentinel->__parent = current;
		}
    	// fix_insert(current);
    	this->__size += 1;
    	return (ft::pair<iterator, bool>(iterator(current), true));
	}
	
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

	void fix_erase(node_type* node, node_type* parent)
	{
	    while (node != __root && (node == 0x0 || node->__isBlack))
	    {
	        if (node == parent->__left)
	        {
	            node_type* sibling = parent->__right;
	            if (!sibling->__isBlack)
	            {
	                sibling->__isBlack = true;
	                parent->__isBlack = false;
	                left_rotate(parent);
	                sibling = parent->__right;
	            }
	            if ((sibling->__left == 0x0 || sibling->__left->__isBlack) &&
	                (sibling->__right == 0x0 || sibling->__right->__isBlack))
	            {
	                sibling->__isBlack = false;
	                node = parent;
	                parent = node->__parent;
	            }
	            else
	            {
	                if (sibling->__right == 0x0 || sibling->__right->__isBlack)
	                {
	                    sibling->__left->__isBlack = true;
	                    sibling->__isBlack = false;
	                    right_rotate(sibling);
	                    sibling = parent->__right;
	                }
	                sibling->__isBlack = parent->__isBlack;
	                parent->__isBlack = true;
	                sibling->__right->__isBlack = true;
	                left_rotate(parent);
	                node = __root;
	                break;
	            }
	        }
	        else
	        {
	            node_type* sibling = parent->__left;
	            if (!sibling->__isBlack)
	            {
	                sibling->__isBlack = true;
	                parent->__isBlack = false;
	                right_rotate(parent);
	                sibling = parent->__left;
	            }
	            if ((sibling->__left == 0x0 || sibling->__left->__isBlack) &&
	                (sibling->__right == 0x0 || sibling->__right->__isBlack))
	            {
	                sibling->__isBlack = false;
	                node = parent;
	                parent = node->__parent;
	            }
	            else
	            {
	                if (sibling->__left == 0x0 || sibling->__left->__isBlack)
	                {
	                    sibling->__right->__isBlack = true;
	                    sibling->__isBlack = false;
	                    left_rotate(sibling);
	                    sibling = parent->__left;
	                }
	                sibling->__isBlack = parent->__isBlack;
	                parent->__isBlack = true;
	                sibling->__left->__isBlack = true;
	                right_rotate(parent);
	                node = __root;
	                break;
	            }
	        }
	    }

	    if (node != 0x0)
	        node->__isBlack = true;
	}


	void erase(iterator position)
	{
	    if (position == end())
	        return;

	    node_type* node = position.base();
	    node_type* to_remove;
	    if (node->__left == 0x0 || node->__right == 0x0)
	        to_remove = node;
	    else
	        to_remove = successor(node);

	    node_type* child;
	    if (to_remove->__left != 0x0)
	        child = to_remove->__left;
	    else
	        child = to_remove->__right;

	    if (child != 0x0)
	        child->__parent = to_remove->__parent;

	    if (to_remove->__parent == 0x0)
	        __root = child;
	    else if (to_remove == to_remove->__parent->__left)
	        to_remove->__parent->__left = child;
	    else
	        to_remove->__parent->__right = child;

	    if (to_remove != node)
	        node->__pair = to_remove->__pair;

	    if (to_remove->__isBlack)
	        fix_erase(child, to_remove->__parent);

	    destroy_node(to_remove);
	    --__size;
	}


	size_type erase(const key_type& key)
	{
	    iterator it = find(key);
	    if (it == end())
	        return 0;
	
	    node_type* node = it.base();
	    node_type* to_remove;
	    if (node->__left == 0x0 || node->__right == 0x0)
	        to_remove = node;
	    else
	        to_remove = successor(node);
	
	    node_type* child;
	    if (to_remove->__left != 0x0)
	        child = to_remove->__left;
	    else
	        child = to_remove->__right;
	
	    if (child != 0x0)
	        child->__parent = to_remove->__parent;
	
	    if (to_remove->__parent == 0x0)
	        __root = child;
	    else if (to_remove == to_remove->__parent->__left)
	        to_remove->__parent->__left = child;
	    else
	        to_remove->__parent->__right = child;
	
	    if (to_remove != node)
	        node->__pair = to_remove->__pair;
	
	    if (to_remove->__isBlack)
	        fix_erase(child, to_remove->__parent);
	
	    destroy_node(to_remove);
	    --__size;
	
	    return 1;
	}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Exchanges the content of the tree by the tree of x, which is another tree of the same type. 
// Sizes may differ.
		void swap(Rb_tree& x)
		{
			key_compare		tmp_comp = this->__comp;
			allocator_type	tmp_alloc = this->__alloc;
			node_type		*tmp_root = this->__root;
			size_type		tmp_size = this->__size;

			this->__comp = x.__comp;
			this->__alloc = x.__alloc;
			this->__root = x.__root;
			this->__size = x.__size;

			x.__comp = tmp_comp;
			x.__alloc = tmp_alloc;
			x.__root = tmp_root;
			x.__size = tmp_size;
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Removes all elements from the tree (which are destroyed), leaving the tree with a size of 0.
		void clear()
		{
			to_clear(this->__root);
			this->__root = 0x0;
			this->__size = 0;
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		/*	
		*	📌 OPERATION
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Searches in tree  for an element with a key equivalent to k and returns 
// an iterator to it if found, otherwise it returns an iterator to end().
		iterator find(const key_type& k)
		{
			node_type *node = this->__root;
			while (node)
			{
				if (this->__comp(k, node->__pair.first))
					node = node->__left;
				else if (this->__comp(node->__pair.first, k))
					node = node->__right;
				else
					return iterator(node);
			}
			return (this->end());
		}
		
		const_iterator find(const key_type& k) const 
		{
			node_type *node = this->__root;
			while (node)
			{
				if (this->__comp(k, node->__pair.first))
					node = node->__left;
				else if (this->__comp(node->__pair.first, k))
					node = node->__right;
				else
					return const_iterator(node);
			}
			return (const_iterator(this->end()));
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Searches the container for elements with a key equivalent to k and 
// returns the number of matches.
		size_type count(const key_type& k) const
		{	
			size_type _count = find(k) != const_iterator(this->end()) ? 1 : 0; 
			return (_count);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns an iterator pointing to the first element in the container whose key is 
// not considered to go before k (i.e., either it is equivalent or goes after).
		iterator lower_bound(const key_type& k)
		{
			iterator	it  = this->begin();
			iterator	ite = this->end();

			
			while (it != ite)
			{
				if (this->__comp(k, it->first))
					it++;
				else
					return (it);
			}
			return (ite);
			
		}

		const_iterator lower_bound(const key_type& k) const
		{
			const_iterator	it  = this->begin();
			const_iterator	ite = this->end();

			
			while (it != ite)
			{
				if (this->__comp(k, it->first))
					it++;
				else
					return (it);
			}
			return (ite);
			
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns an iterator pointing to the first element in the container whose key 
// is considered to go after k.
		iterator upper_bound(const key_type& k)
		{
			iterator	it = this->begin();
			iterator	ite = this->end();

			
			while (it != ite)
			{
				if (this->__comp(it->first, k) 
				|| ((!this->__comp(it->first, k)) && (!this->__comp(k, it->first))))
					it++;
				else
					return (it);
			}
			return (ite);
		}

		const_iterator upper_bound(const key_type& k) const
		{
			const_iterator	it = this->cbegin();
			const_iterator	ite = this->cend();

			while (it != ite)
			{
				if (this->__comp(it->first, k) 
				|| ((!this->__comp(it->first, k)) && (!this->__comp(k, it->first))))
					it++;
				else
					return (it);
			}
			return (ite);	
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns the bounds of a range that includes all the elements in the container
// which have a key equivalent to k. Because the elements in a map container have unique keys, 
// the range returned will contain a single element at most.
		pair<iterator,iterator> equal_range (const key_type& k) 
		{
			return (ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
		}

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return (ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		/*	
		*	📌 ALLOCATOR
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a copy of the allocator object associated with the tree
		allocator_type	get_allocator() const { return (this->__alloc); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		private:
			key_compare												__comp;
			node_alloc												__node_alloc;
			allocator_type											__alloc;
			node_type												*__root;
			node_type												*__sentinel;	
			size_type												__size;

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		/*	
		*	📌 UTILS
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/
	
	void destroy_node(node_type* node)
    {
		this->__node_alloc.destroy(node);
		this->__node_alloc.deallocate(node, 1);
    }

	void to_clear(node_type *node)
	{
		if (node)
		{
			to_clear(node->__left);
			to_clear(node->__right);
			this->__node_alloc.destroy(node);
			this->__node_alloc.deallocate(node, 1);
			node = 0x0;
		}
	}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		void left_rotate(node_type *x)
		{
		    node_type *y = x->__right;

		    x->__right = y->__left;
		    if (y->__left != __null)
		        y->__left->__parent = x;
		    y->__parent = x->__parent;
		    if (x->__parent == __null)
		        __root = y;
			else if (x->__isLeftChild)
		        x->__parent->__left = y;
		    else
		        x->__parent->__right = y;
		    y->__left = x;
		    x->__parent = y;
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		void	right_rotate(node_type *x)
		{
		    node_type *y = x->__left;

		    x->__left = y->__right;
		    if (y->__right)
		        y->__right->__parent = x;
		    y->__parent = x->__parent;
		    if (!x->__parent)
		        __root = y;
		    else if (x->__isLeftChild)
		        x->__parent->__left = y;
		    else
		        x->__parent->__right = y;
		    y->__right = x;
		    x->__parent = y;
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/
node_type* successor(node_type* node) const
{
    if (node->__right != NULL)
    {
        node_type* n = node->__right;
        while (n->__left != NULL)
            n = n->__left;
        return n;
    }
    else
    {
        node_type* p = node->__parent;
        while (p != NULL && node == p->__right)
        {
            node = p;
            p = p->__parent;
        }
        return p;
    }
}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// // find the smallest elem from the tree
// 		iterator *min(const node_type* z) const
// 		{
// 			if (!z)
// 				return (0x0);
// 			while (z->__left)
// 				z = z->__left;
// 			return (iterator(z));
// 		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		// void printTree() 
		// {
		// 	node_type *node = this->__root;

		//     if (!node)
		//         return;
		//     if (node->__right)
		//         printTree(node->__right);
		//     std::cout << std::setw(6) << " ";
		//     if (node->__right)
		//         std::cout << " /\n" << std::setw(6) << " ";
		//     std::cout << node->__pair.seconde << std::endl;
		//     if (node->__left) {
		//         std::cout << std::setw(6) << " " << " \\\n";
		//         printTree(node->__left, 6);
		//     }
		// }
	};
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/
}
#endif