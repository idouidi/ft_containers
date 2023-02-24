/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:06:45 by idouidi           #+#    #+#             */
/*   Updated: 2023/02/24 00:03:42 by idouidi          ###   ########.fr       */
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
			typedef ft::Node<key_type, value_type>									node_type;
			typedef typename allocator_type::template rebind<node_type>::other 		node_alloc; //redifine type of the allocation
			typedef std::size_t														size_type;
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
		 :__comp(comp) , __node_alloc(Node_alloc), __alloc(alloc),__root(0x0), __size(0)
		{}

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
		iterator end()
		{
			node_type *tmp = this->__root;
			if (tmp)
			{
				while (tmp->__right)
					tmp = tmp->__right;
			}
			return (iterator(tmp));
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
    		current = this->__node_alloc.allocate(sizeof(node_type));
    		this->__node_alloc.construct(current, node_type(p.first, p.second));
    		if (parent == 0x0)
    		    this->__root = current;
    		else if (isLeft)
    		    parent->__left = current;
    		else
    		    parent->__right = current;

    		insert_fixup(current);
    		this->__size += 1;
    		return (ft::pair<iterator, bool>(iterator(current), true));
		}
	
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

void erase(iterator position)
{
    // On trouve le noeud à supprimer
    node_type* node_to_delete = position.base();

    // On déclare les variables nécessaires pour la suppression
    node_type* successor = 0x0;
    node_type* successor_child = 0x0;
    bool original_color = node_to_delete->__isBlack;

    if (node_to_delete->__left == 0x0)
    {
        // Si le noeud à supprimer n'a pas de fils gauche, on peut simplement
        // remplacer le noeud à supprimer par son fils droit
        successor_child = node_to_delete->__right;
        replace_subtree(node_to_delete, node_to_delete->__right);
    }
    else if (node_to_delete->__right == 0x0)
    {
        // Si le noeud à supprimer n'a pas de fils droit, on peut simplement
        // remplacer le noeud à supprimer par son fils gauche
        successor_child = node_to_delete->__left;
        replace_subtree(node_to_delete, node_to_delete->__left);
    }
    else
    {
        // Si le noeud à supprimer a deux fils, on doit trouver son successeur
        successor = node_to_delete->__right;
        while (successor->__left != 0x0)
            successor = successor->__left;

        // On sauvegarde la couleur originale du successeur
        original_color = successor->__isBlack;

        // On met le successeur à la place du noeud à supprimer
        successor_child = successor->__right;
        if (successor->__parent == node_to_delete)
            successor_child->__parent = successor;
        else
        {
            replace_subtree(successor, successor->__right);
            successor->__right = node_to_delete->__right;
            successor->__right->__parent = successor;
        }
        replace_subtree(node_to_delete, successor);
        successor->__left = node_to_delete->__left;
        successor->__left->__parent = successor;
        successor->__isBlack = node_to_delete->__isBlack;
    }

    // Si on a supprimé un noeud noir, il peut y avoir une violation de la
    // propriété 5 de l'arbre rouge-noir. On appelle donc la fonction
    // erase_fixup pour la rétablir.
    if (original_color == true)
        erase_fixup(successor_child);

    // On libère la mémoire allouée pour le noeud supprimé
    this->__node_alloc.destroy(node_to_delete);
    this->__node_alloc.deallocate(node_to_delete, 1);

    // On met à jour la taille de l'arbre
    this->__size -= 1;
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
			size_type												__size;

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		/*	
		*	📌 UTILS
		*/

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


		void	insert_fixup(node_type *z)
		{
		    node_type *y = 0x0;

		    while (z != this->__root && z->__parent->__isBlack == false)
		    {
		        if (z->__parent == z->__parent->__parent->__left)
		        {
		            y = z->__parent->__parent->__right;
		            if (y && y->__isBlack == false)
		            {
		                z->__parent->__isBlack = true;
		                y->__isBlack = true;
		                z->__parent->__parent->__isBlack = false;
		                z = z->__parent->__parent;
		            }
		            else
		            {
		                if (z == z->__parent->__right)
		                {
		                    z = z->__parent;
		                    left_rotate(z);
		                }
		                z->__parent->__isBlack = true;
		                z->__parent->__parent->__isBlack = false;
		                right_rotate(z->__parent->__parent);
		            }
		        }
		        else
		        {
		            y = z->__parent->__parent->__left;
		            if (y && y->__isBlack == false)
		            {
		                z->__parent->__isBlack = true;
		                y->__isBlack = true;
		                z->__parent->__parent->__isBlack = false;
		                z = z->__parent->__parent;
		            }
		            else
		            {
		                if (z == z->__parent->__left)
		                {
		                    z = z->__parent;
		                    right_rotate(z);
		                }
		                z->__parent->__isBlack = true;
		                z->__parent->__parent->__isBlack = false;
		                left_rotate(z->__parent->__parent);
		            }
		        }
		    }
		   this->__root->__isBlack = true;
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/
		
void replace_subtree(node_type *node_to_replace, node_type *replacement_node) 
{
    if (node_to_replace == this->__root)
        this->__root = replacement_node;
    else if (node_to_replace == node_to_replace->__parent->__left)
	{
        node_to_replace->__parent->__left = replacement_node;
    }
	else 
	{
        node_to_replace->__parent->__right = replacement_node;
    }
    replacement_node->__parent = node_to_replace->__parent;
}


/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// find the smallest elem from the tree
		iterator *min(const node_type* z) const
		{
			if (!z)
				return (0x0);
			while (z->__left)
				z = z->__left;
			return (iterator(z));
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		void	erase_fixup(node_type *x)
		{
			while (x != this->__root && x->__isBlack)
			{
			    if (x == x->__parent->__left)
			    {
			        node_type *w = x->__parent->__right;
			        if (!w->__isBlack)
			        {
			            w->__isBlack = true;
			            x->__parent->__isBlack = false;
			            left_rotate(x->__parent);
			            w = x->__parent->__right;
			        }
			        if (w->__left->__isBlack && w->__right->__isBlack)
			        {
			            w->__isBlack = false;
			            x = x->__parent;
			        }
			        else
			        {
			            if (w->__right->__isBlack)
			            {
			                w->__left->__isBlack = true;
			                w->__isBlack = false;
			                right_rotate(w);
			                w = x->__parent->__right;
			            }
			            w->__isBlack = x->__parent->__isBlack;
			            x->__parent->__isBlack = true;
			            w->__right->__isBlack = true;
			            left_rotate(x->__parent);
			            x = this->__root;
			        }
			    }
			    else
			    {
			        node_type *w = x->__parent->__left;
			        if (!w->__isBlack)
			        {
			            w->__isBlack = true;
			            x->__parent->__isBlack = false;
			            right_rotate(x->__parent);
			            w = x->__parent->__left;
			        }
			        if (w->__right->__isBlack && w->__left->__isBlack)
			        {
			            w->__isBlack = false;
			            x = x->__parent;
			        }
			        else
			        {
			            if (w->__left->__isBlack)
			            {
			                w->__right->__isBlack = true;
			                w->__isBlack = false;
			                left_rotate(w);
			                w = x->__parent->__left;
			            }
			            w->__isBlack = x->__parent->__isBlack;
			            x->__parent->__isBlack = true;
			            w->__left->__isBlack = true;
			            right_rotate(x->__parent);
			            x = __root;
			        }
			    }
			}
			    x->__isBlack = true;
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