/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:06:45 by idouidi           #+#    #+#             */
/*   Updated: 2023/02/28 21:33:13 by idouidi          ###   ########.fr       */
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
			// create the node sentinel
			this->__sentinel =  this->__node_alloc.allocate(1);
			this->__node_alloc.construct(this->__sentinel, node_type(key_type(), value_type()));
			this->__sentinel->__parent = 0x0;
			this->__sentinel->__left = 0x0;	
			this->__sentinel->__right = 0x0;	
			this->__sentinel->__isLeftChild = false;
			this->__sentinel->__isBlack = true;
		}

		Rb_tree& operator=(const Rb_tree& other)
		{
			if (this != &other)
			{
				if (!this->__size)
					this->clear();
				this->__comp = other.__comp;
				this->__node_alloc = other.__node_alloc;
				this->__alloc = other.__alloc;
				this->__root = other.__root;
				this->__sentinel = other.__sentinel;
				this->__size = other.__size;
			}
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Destructor
		~Rb_tree()
		{}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		/*	
		*	📌 ITERATORS
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns an iterator (i.e a node) referring to the first element in the tree.
		iterator begin()
		{
			if (this->__size == 0)
				return (this->end());
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
			if (this->__size == 0)
				return (this->end());
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
				while (tmp->__right && tmp->__right != this->__sentinel)
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
			return (const_iterator(this->__sentinel));
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



	void uncle_is_black(node_type *node)
	{
		node_type *save_parent;

		if (node->__parent->__isLeftChild)
		{
			if (node->__isLeftChild)
				save_parent = right_rotate(node->__parent->__parent);
			else
				save_parent = left_right_rotate(node->__parent->__parent);
		}
		else
		{
			if (node->__isLeftChild == false)
				save_parent = left_rotate(node->__parent->__parent);
			else
				save_parent = right_left_rotate(node->__parent->__parent);
		}
		save_parent->__left->__isBlack = false;
		save_parent->__right->__isBlack = false;
		save_parent->__isBlack  = true;
	}

	void uncle_is_red(node_type * node, node_type *uncle)
	{
		node->__parent->__isBlack = true;
		uncle->__isBlack = true;
		uncle->__parent->__isBlack = false;

	}

	void check_node(node_type *node)
	{
		node_type *uncle;

		if (node->__parent->__isLeftChild)
			uncle = node->__parent->__parent->__right;
		else
			uncle = node->__parent->__parent->__left;

		if (!uncle || uncle->__isBlack)
			uncle_is_black(node);
		else
			uncle_is_red(node, uncle);

		this->__root->__isBlack = true;
	}

	void fix_insert(node_type *node)
	{
		if (node == this->__root)
			return ;
		if (node->__isBlack == false && node->__parent->__isBlack == false)
			check_node(node);
		fix_insert(node->__parent);
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
				if (current->__right && current->__right == this->__sentinel)
					current->__right = 0x0;
				else 
        	    	current = current->__right;
        	    isLeft = false;
        	}
        	else
        	    return ft::pair<iterator, bool>(iterator(current), false);
    	}

		// create the node at a valid position
    	current = this->__node_alloc.allocate(1);
    	this->__node_alloc.construct(current, node_type(p.first, p.second));
    	
		if (!parent)
			current->__parent = 0x0;
		else
			current->__parent = parent;
		current->__right = 0x0;
		current->__left = 0x0;
		current->__isBlack = false;
		current->__isLeftChild = isLeft;
		if (parent == 0x0)
		{
    	    this->__root = current;
			this->__root->__isBlack = true;
		}
    	else if (isLeft)
    	    current->__parent->__left = current;
    	else
			current->__parent->__right = current;
	
		// update sentinel
		if (current == find_end())
		{
			current->__right = this->__sentinel;
			this->__sentinel->__parent = current;
		}
		if (current != this->__root && current->__isBlack == false && current->__parent->__isBlack == false)
    		fix_insert(current);
    	this->__size += 1;
    	return (ft::pair<iterator, bool>(iterator(current), true));
	}
	
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

	void erase_node(node_type *position)
	{
		node_type *save_left_child = position->__left; 
		node_type *save_right_child = position->__right;

		if (position == this->__root)
			this->__root = 0x0; 
		if (position->__isLeftChild)
		{
			if (save_left_child && save_left_child->__right != this->__sentinel)
			{
				if (position->__parent)
					position->__parent->__left =  position->__left;
				save_left_child->__parent = position->__parent;
				position->__left->__isLeftChild = true;
			}
			else if (save_right_child && save_right_child->__right != this->__sentinel)
			{
				if (position->__parent)
					position->__parent->__right = position->__right;
				save_right_child->__parent = position->__parent;
				position->__right->__isLeftChild = true;
			}
			else
			{
				if (position->__parent)
					position->__parent->__right = this->__sentinel;
			}
		}

		else
		{
			if (save_left_child && save_left_child->__right != this->__sentinel)
			{
				if (position->__parent)
					position->__parent->__left =  position->__left;
				save_left_child->__parent = position->__parent;
				position->__left->__isLeftChild = false;
			}
			else if (save_right_child && save_right_child->__right != this->__sentinel)
			{
				if (position->__parent)
					position->__parent->__right = position->__right;
				save_right_child->__parent = position->__parent;
				position->__right->__isLeftChild = false;
			}
			else
			{
				if (position->__parent)
					position->__parent->__right = this->__sentinel;
			}
		}
		this->__node_alloc.destroy(position);
		this->__node_alloc.deallocate(position, 1);
		this->__size -= 1;
	}
/*********************************************************************/

// brother part
	void brother_become_red(node_type *node, bool isLeft)
	{
		bool	swapColor;
		if (isLeft)
		{
			swapColor = node->__right->__isBlack;
			node->__right->__isBlack = node->__isBlack;
			node->__isBlack = swapColor;
			left_rotate(node);
			fix_erase(node, isLeft);
		}
		else
		{
			swapColor = node->__left->__isBlack;
			node->__left->__isBlack = node->__isBlack;
			node->__isBlack = swapColor;
			right_rotate(node);
			fix_erase(node, isLeft);
		}
	}

	bool brother_are_red(node_type *node, bool isLeft)
	{
		return (((isLeft == true && node->__right->__isBlack == false)
			|| (isLeft == false && node->__left->__isBlack == false)));
	}

/***********************************************************************/

//child of the brother part
	bool black_brothers_child_are_red(node_type *node, bool isLeft)
	{
		return ((isLeft && node->__right && node->__right != this->__sentinel && node->__right->__left 
		&& node->__right->__left->__isBlack && node->__right->__right && node->__right->__right->__isBlack) 
		|| (isLeft == false && node->__left  && node->__left->__left
		&& node->__left->__left->__isBlack && node->__left->__right && node->__left->__right->__isBlack)); 
		
		// return ( ((	node->__right->__right && node->__right->__left && 
		// 			isLeft && node->__right->__right && node->__right->__right != this->__sentinel)
		// 	&& (!node->__right->__left->__isBlack || !node->__right->__right->__isBlack))
		// 	|| (!isLeft && node->__left->__left && node->__left->__right != this->__sentinel
		// 	&& (!node->__left->__left->__isBlack || !node->__left->__right->__isBlack)));
	}


	void black_brother_child_become_red(node_type *node, bool isLeft)
	{
		bool  swapColor;

		if (isLeft && node->__right && node->__right->__right != this->__sentinel
			&& node->__right->__right->__isBlack == false)
		{
			node->__right->__isBlack = node->__isBlack;
			node->__isBlack = true;
			node->__right->__right->__isBlack = true;
			left_rotate(node);
		}

		else if (isLeft == false && node->__left && node->__left->__right != this->__sentinel && 
			node->__left->__left->__isBlack == false)
		{
			node->__left->__isBlack = node->__isBlack;
			node->__isBlack = true;
			node->__left->__left->__isBlack = true;
			right_rotate(node);
		}

		else if (isLeft == false && node->__right && node->__right->__right != this->__sentinel &&
			node->__right->__left->__isBlack == false)
		{
			swapColor = node->__right->__left->__isBlack;
			node->__right->__left->__isBlack = node->__right->__isBlack;
			node->__right->__isBlack = swapColor;
			right_rotate(node->__right);
			black_brother_child_become_red(node, isLeft);
		}

		else if (isLeft == false && node->__left && node->__left->__right != this->__sentinel &&
			node->__left->__right->__isBlack == false)
		{
			swapColor = node->__left->__right->__isBlack;
			node->__left->__right->__isBlack = node->__left->__isBlack;
			node->__left->__isBlack = swapColor;
			left_rotate(node->__left);
			black_brother_child_become_red(node, isLeft);
		}
	}

	void black_brother_child_become_black(node_type *node, bool isLeft)
	{
		if (isLeft)
		{
			node->__right->__isBlack = false;
			if (node->__isBlack == false)
				node->__isBlack = true;
			else
				fix_erase(node->__parent, node->__isLeftChild);
		}
		else
		{
			node->__left->__isBlack = false;
			if (node->__isBlack == false)
				node->__isBlack = true;
			else
				fix_erase(node->__parent, node->__isLeftChild);
		}
	}

/***********************************************************************/

		void		swapLeaf(node_type* swap_node, node_type* pos) 
		{
			node_type*							parent_tmp = pos->__parent;
			node_type*							Lchild_tmp = pos->__left;
			node_type*							Rchild_tmp = pos->__right;
			bool								is_left = pos->__isLeftChild;
			bool								black_tmp = pos->__isBlack;

			if (pos == this->__root)
				this->__root = swap_node;

			pos->__left = swap_node->__left; 
			if (swap_node->__left)
				pos->__left->__parent = pos;
			pos->__right = swap_node->__right;
			if (swap_node->__right && swap_node->__right != this->__sentinel)
				pos->__right->__parent = pos;
			if (pos != swap_node->__parent) 
			{
				pos->__parent = swap_node->__parent;
				if (swap_node->__isLeftChild && parent_tmp)
					pos->__parent->__left = pos;
				else if (parent_tmp)
					pos->__parent->__right = pos;
				swap_node->__left = Lchild_tmp;
				if (swap_node->__left)
					swap_node->__left->__parent = swap_node;
				swap_node->__right = Rchild_tmp;
				if (swap_node->__right)
					swap_node->__right->__parent = swap_node;
			}
			else {
				pos->__parent = swap_node;
				if (swap_node->__isLeftChild) {
					swap_node->__left = pos;
					swap_node->__right = Rchild_tmp;
					if (swap_node->__right)
						swap_node->__right->__parent = swap_node;
				}
				else {
					swap_node->__right = pos;
					swap_node->__left = Lchild_tmp;
					if (swap_node->__left)
						swap_node->__left->__parent = swap_node;
				}
			}
			swap_node->__parent = parent_tmp;
			if (pos->__isLeftChild && parent_tmp)
				parent_tmp->__left = swap_node;
			else if (parent_tmp)
				parent_tmp->__right = swap_node;
			pos->__isBlack = swap_node->__isBlack;
			pos->__isLeftChild = swap_node->__isLeftChild;
			swap_node->__isBlack = black_tmp;
			swap_node->__isLeftChild = is_left;
		}

/***********************************************************************/

		void		deleteLeaf(node_type *pos) 
		{
			if (pos == this->__root)
				this->__root = 0x0;
			if (pos->__isLeftChild) 
			{
				if (pos->__left)
				{
					pos->__parent->__left = pos->__left;
					pos->__left->__parent = pos->__parent;
					pos->__left->__isLeftChild = true;
				}
				else if (pos->__right)
				{
					pos->__parent->__left = pos->__right;
					pos->__right->__parent = pos->__parent;
					pos->__right->__isLeftChild = true;
				}
				else
				{
					if (pos->__parent)
						pos->__parent->__left = 0x0;
				}
			}
			else if (!pos->__isLeftChild) 
			{
				if (pos->__left)
				{
					pos->__parent->__right = pos->__left;
					pos->__left->__parent = pos->__parent;
					pos->__left->__isLeftChild = false;
				}
				else if (pos->__right)
				{
					pos->__parent->__right = pos->__right;
					pos->__right->__parent = pos->__parent;
					pos->__right->__isLeftChild = false;
				}
				else
				{
					if (pos->__parent)
						pos->__parent->__right = 0x0;
				}
			}
			this->__node_alloc.destroy(pos);
			this->__node_alloc.deallocate(pos, 1);
			this->__size -= 1;
		}


/***********************************************************************/
	// void fix_erase(node_type *node, bool isLeft, bool position_was_black = true)
	// {
	// 	if (position_was_black == false || (node == 0x0 || node == this->__sentinel)
	// 		return ;
	// 	if (isLeft == true && node->__left && node->__left->__isBlack == false)
	// 		node->__left->__isBlack = true;
	// 	else if (isLeft == false && node->__right && node->__right->__isBlack == false)
	// 		node->__right->__isBlack = true;
	// 	else if (brother_are_red(node, isLeft))
	// 		brother_become_red(node, isLeft);

	// 	else if (black_brothers_child_are_red(node, isLeft))
	// 		black_brother_child_become_red(node, isLeft);
	
	// 	else if (black_brothers_child_are_red(node, isLeft) == false)
	// 		black_brother_child_become_black(node, isLeft);
	// }



	void		erase(node_type* pos) 
	{
		bool								need_to_fix = pos->__isBlack;
		bool								is_left = pos->__isLeftChild;
		node_type							*fixNode = pos->__parent;
		node_type							*swap_node;
		node_type							*update_sentinel;
		
		if ((!pos->__right && !pos->__left ) || (!pos->__left && pos->__right == this->__sentinel))
		{
			if (pos->__isLeftChild && pos != this->__root)
				pos->__parent->__left = 0x0;
			else if (pos->__isLeftChild == false && pos != this->__root )
				pos->__parent->__right = 0x0;
			deleteLeaf(pos);
			// if (fixNode)
			// 	fixDelete(fixNode, is_left, need_to_fix);
			update_sentinel = find_end();
			update_sentinel->__right = this->__sentinel;
			this->__sentinel->__parent = update_sentinel;
			return ;
		}
		swap_node = successor(pos);
		if (swap_node == 0x0)
			swap_node = predecessor(pos);
		is_left = swap_node->__isLeftChild;
		need_to_fix = swap_node->__isBlack;
		swapLeaf(swap_node, pos);
		fixNode = pos->__parent;
		deleteLeaf(pos);
		// fixDelete(fixNode, is_left, need_to_fix);
		update_sentinel = find_end();
		update_sentinel->__right = this->__sentinel;
		this->__sentinel->__parent = update_sentinel;
		return ;
	}
	// void erase(node_type *pos)
	// {

	// 	node_type *save_parent = pos->__parent;
	// 	node_type * update_sentinel;
	// 	bool position_was_black = position->__isBlack;
	// 	bool isLeft = position->__isLeftChild;

	// 	//update sentinel
	// 	if (position->__right && position->__left && position->__right != this->__sentinel)
	// 	{
	// 	std::cout << "in erase the value is =" << position->__pair.first << std::endl;
	// 		if (save_parent)
	// 		{
	// 			save_parent->__right = this->__sentinel;
	// 			this->__sentinel->__parent = save_parent;
	// 		}
	// 		else if (save_parent->__left)
	// 		{
	// 			save_parent->__left->__right = this->__sentinel;
	// 			this->__sentinel->__parent = save_parent->__left;
	// 		}
	// 		erase_node(position);
	// 		if (save_parent && save_parent->__right != this->__sentinel)
	// 			fix_erase(save_parent, isLeft, position_was_black);
	// 		update_sentinel = find_end();
	// 		update_sentinel->__right = this->__sentinel;
	// 		this->__sentinel->__parent = update_sentinel;
	// 		return ;
	// 	}
	// 	node_type *swap_node = successor(position);
	// 	if (swap_node)
	// 	{
	// 		if (swap_node->__right == this->__sentinel)
	// 			swap_node = predecessor(position);
	// 		isLeft = swap_node->__isLeftChild;
	// 		position_was_black = swap_node->__isBlack;
	// 		swapLeaf(swap_node, position);
	// 		save_parent = position->__parent;
	// 		deleteLeaf(position);
	// 		fix_erase(save_parent, isLeft, position_was_black);
	// 		update_sentinel = find_end();

	// 		update_sentinel->__right = this->__sentinel;
	// 		this->__sentinel->__parent = update_sentinel;
	// 	}
	// }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Exchanges the content of the tree by the tree of x, which is another tree of the same type. 
// Sizes may differ.
		void swap(Rb_tree& x)
		{
			if (this == &x)
				return ;
			key_compare		tmp_comp = this->__comp;
			allocator_type	tmp_alloc = this->__alloc;
			allocator_type	tmp_node_alloc = this->__node_alloc;
			node_type		*tmp_root = this->__root;
			node_type		*tmp_sentinel = this->__sentinel;
			size_type		tmp_size = this->__size;

			this->__comp = x.__comp;
			this->__alloc = x.__alloc;
			this->__node_alloc = x.__node_alloc;
			this->__root = x.__root;
			this->__sentinel = x.__sentinel;
			this->__size = x.__size;

			x.__comp = tmp_comp;
			x.__alloc = tmp_alloc;
			x.__node_alloc = tmp_node_alloc;
			x.__root = tmp_root;
			x.__sentinel = tmp_sentinel;
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
				{
					node = node->__right;
				}
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
		iterator	lower_bound (const key_type& k)
		{
			iterator it = begin();
			iterator ite = end();

			while (it != ite)
			{
				if (this->__comp(it->first, k))
					it++;
				else
					return (it);
			}
			return (ite);
		}

		const_iterator	lower_bound (const key_type& k) const 
		{
			const_iterator it = begin();
			const_iterator ite = end();

			while (it != ite)
			{
				if (this->__comp(it->first, k))
					it++;
				else
					return (it);
			}
			return (const_iterator(ite));
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
			const_iterator	it = this->begin();
			const_iterator	ite = this->end();

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

		/*	
		*	📌 MY UTILS
		*/


# define M_RESET	        "\033[0m"
# define M_BLACK	        "\033[1;30m"
# define M_RED	        "\033[1;31m"
# define M_GREEN	        "\033[1;32m"
# define M_YELLOW         "\033[1;33m"
# define M_MAGENTA        "\033[1;35m"
# define M_CYAN	        "\033[1;36m"



			size_t		returnHeight() const {
				if (__root == 0x0)
					return (0);
				return (returnHeight(__root));
			}

			size_t		returnHeight(node_type *pos) const {
				if (!pos || pos == this->__sentinel || this->__root == 0x0)
					return 0;
				int		leftHeight = returnHeight(pos->__left) + 1;
				int		rightHeight = returnHeight(pos->__right) + 1;
				if (leftHeight > rightHeight)
					return (leftHeight);
				return (rightHeight);
			}

			void printRb_treeFormat(int level, int k, node_type *pos) const {
				if (!pos || pos == this->__sentinel || this->__root == 0x0)
					return ;
				printRb_treeFormat(level + 1, k, pos->__left);
				printRb_treeFormat(level + 1, k, pos->__right);

				if (k == level) {
					std::cout << ((pos->__isLeftChild) ? M_CYAN : M_YELLOW) << " |" << M_RESET 
					<< ((pos->__isBlack) ? M_BLACK : M_RED) << "value : [" << pos->__pair.first  
					<< "] | p: [" << (pos->__parent  ? pos->__parent->__pair.first : 0x0) << "]" << M_RESET << ((pos->__isLeftChild) ? M_CYAN : M_YELLOW) << "| " << M_RESET;
				}
				return ;
			}


			void		printAllRb_tree() const {
				size_t		size = this->returnHeight();
				std::cout << "size : " << size << std::endl;
				
				std::cout << 
				M_CYAN << "left child" << M_RESET << " | " <<
				M_YELLOW << "right child" << M_RESET << std::endl  << std::endl;
				for (size_t i = 0; i < size; i++) {
					printRb_treeFormat(0, i, this->__root);
					std::cout << std::endl << M_GREEN << "\t++++++++++++++++" << M_RESET << std::endl;
				}
				std::cout  << std::endl << M_YELLOW << "-------------END OF Rb_tree PRINT-------------" << M_RESET << std::endl << std::endl;
			}

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


	void	to_clear(node_type *node)
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


		node_type* left_rotate(node_type *grand_parent) // the grand parent->parent
		{
		    node_type *save_parent = grand_parent->__right; //the parent, i.e the child of the grand parent
			node_type *save_great_grand_parent = grand_parent->__parent; // the parent of the grand parent

			// rotate
			grand_parent->__right = save_parent->__left;
			save_parent->__left = grand_parent;


			/*
			* the parent (save_parent) become the new grand parent . 
			* And grand parent become the parent.
			* i.e grand_parent is the left child of save parent 
			*/
			save_parent->__isLeftChild = grand_parent->__isLeftChild;
			grand_parent->__isLeftChild = true;
	
			// now the parent of the grand parent is the parent
			// now the parent of the of the parent is the great grand parent
			grand_parent->__parent = save_parent;
			save_parent->__parent = save_great_grand_parent;
			
			if (grand_parent->__right)
			{
				grand_parent->__right->__parent = grand_parent;
				grand_parent->__right->__isLeftChild = false;

			}
			// update the child of the great grant parent
			
			if (save_great_grand_parent)
			{
				if (save_parent->__isLeftChild)
					save_great_grand_parent->__left = save_parent;
				else
					save_great_grand_parent->__right = save_parent;
			}
	
			// we check if the grand parent was the root to change it.
			// if it's true the parent become the root 
			if (this->__root == grand_parent)
				this->__root = save_parent;

			return (save_parent);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		node_type * right_rotate(node_type *grand_parent) // node is the parent->parent
		{
		    node_type *save_parent = grand_parent->__left; //the parent, i.e the child of the grand parent
			node_type *save_great_grand_parent = grand_parent->__parent; // the parent of the grand parent


			// rotate
			grand_parent->__left = save_parent->__right;
			save_parent->__right = grand_parent;

			/*
			* the parent (save_parent) become the new grand parent . 
			* And grand parent become the parent.
			* i.e grand_parent is the right child of save parent 
			*/
			save_parent->__isLeftChild = grand_parent->__isLeftChild;
			grand_parent->__isLeftChild = false;
	
			// now the parent of the grand parent is the parent
			// now the parent of the of the parent is the great grand parent
			grand_parent->__parent = save_parent;
			save_parent->__parent = save_great_grand_parent;
			
			if (grand_parent->__left)
			{
				grand_parent->__left->__parent = grand_parent;
				grand_parent->__left->__isLeftChild = true;
			}
			
			if (save_great_grand_parent)
			{
				// update the child of the great grant parent
				if (save_parent->__isLeftChild)
					save_great_grand_parent->__left = save_parent;
				else
					save_great_grand_parent->__right = save_parent;
			}
				
			
			// we check if the grand parent was the root to change it.
			// if it's true the parent become the root 
			if (this->__root == grand_parent)
				this->__root = save_parent;
			return (save_parent);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/


		node_type * left_right_rotate(node_type *grand_parent)
		{
			left_rotate(grand_parent->__left);
			return (right_rotate(grand_parent));
		}

		node_type *right_left_rotate(node_type *grand_parent)
		{
			right_rotate(grand_parent->__right);
			return (left_rotate(grand_parent));
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

	node_type* successor(node_type* node)
	{
		node_type *ret;

		if (!node)
			return (0x0);
		else if (node->__left == 0x0)
			return (0x0);
		else
		{
			ret = node->__left;
			while(ret->__right)
				ret = ret->__right; ////// ?
			return (ret);
		}
		return (0x0);
	}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

	node_type* predecessor(node_type *node)
	{
		node_type *ret;
		if (!node )
			return (0x0);
		else if (node->__right == 0x0)
			return (0x0);
		else
		{
			ret = node->__right;
			while  (ret->__left)
				ret = ret->__left;
			return (ret);
		}
		return (0x0);
	}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

	};



/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/
}
#endif