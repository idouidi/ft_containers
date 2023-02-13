/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:03:39 by idouidi           #+#    #+#             */
/*   Updated: 2023/02/13 19:12:04 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __RED_BLACK_TREE_ITERATOR_HPP__
# define __RED_BLACK_TREE_ITERATOR_HPP__

# include "./ftnspace.hpp"


namespace ft
{
    template < class Iterator>
    struct Rb_tree_iterartor
    {
        public:
			typedef typename ft::iterator_traits<Iterator>::difference_type		differeence_type;
        	typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::value_type*			pointer;
			typedef typename ft::iterator_traits<Iterator>::value_type&			reference;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef Iterator*													iterator_type;

        /*	
		*	📌 CONSTRUCTOR / DESTRCUTOR
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/	

// 📚 default constructor
		Rb_tree_iterartor(): __node(0x0), __end(0x0)
		{}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 fill constructor
		Rb_tree_iterartor(iterator_type node, iterator_type end): __node(node), __end(end)
		{}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 copy constructor

		Rb_tree_iterartor(const Rb_tree_iterartor& rbt_it): __node(rbt_it.__node), __end(rbt_it.__end)
		{}

// operator assigning copy
		Rb_tree_iterartor& Rb_tree_iterartor(const Rb_tree_iterartor& rbt_it)
		{
			if (this != &rbt_it)
			{
				this->__node = rbt_it.__node;
				this->__end = rbt_it.__end;
			}
			return (*this);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Destructor
		~Rb_tree_iterartor() {}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

        /*
        *   📌 MEMBER FUNCTION 
        */

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 relational operator
		bool operator==(const Rb_tree_iterartor& rbt_it)
		{
			return (this->__node == rbt_it.__node);
		}

		bool operator!=(const Rb_tree_iterartor& rbt_it)
		{
			return (!(this->__node == rbt_it.__node));
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a const reference to the element pointed to by the Iterator;
        reference operator*() const
		{
			return (__node->__key)
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a const pointer to the element pointed to by the Iterator;
		pointer operator->() const
		{
			return (&this->__node->__key);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Increment the iterator to the next elem
		Rb_tree_iterartor&	operator++()
		{
			icrem_iterator();
			return (*this);
		}

// 📚 PostIncrement the iterator to the next elem
		Rb_tree_iterartor&	operator++(int)
		{
			Rb_tree_iterartor tmp;

			tmp = *this;
			icrem_iterator();
			return (tmp);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Decrement the iterator to the previous elem
		Rb_tree_iterartor&	operator--()
		{
			decrem_iterator();
			return (*this);
		}

// 📚 Postdecrement the iterator to the previous elem
		Rb_tree_iterartor&	operator--(int)
		{
			Rb_tree_iterartor tmp;

			tmp = *this;
			decrem_iterator();
			return (tmp);
		}


/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		private:
			iterator_type														__node;
			iterator_type														__end;
		

		void	icrem_iterator()
		{
			if (this->__node)
			{
				if (this->__node->__right) //if right child exist go to the smaller go to the smaller node of this subtree
				{
					this->__node = this->__node->__right;
					while (this->__node->__left)
						this->__node = this->__node->__left;
				}
				else // else go to the next left parent 
				{
					while (this->__node->__parent && this->__node == this->__node->__parent->__right)
						this->__node = this->__node->__parent;
					this->__node = this->__node->__parent;
				}
			}
		}

		void	decrem_iterator()
		{
			if (this->__node)
			{
				if (this->__node->left) // if left child exist, go to the biger node from this sub tree
					this->__node = this->__node->left;
				while (this->__node->right)
					this->__node = this->node->right;
			}
			else // go to the next right parent
			{
				while (this->__node->parent && this->__node == this->__node->__parent->-_left)
					this->__node = this->__node->parent;
				this->__node = this->__node->__parent;
			}
		}
    };

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		/*	
		*	📌 RED BLACK TREE CONST ITERATOR
		*/

    template < class Iterator>
    struct Rb_tree_const_iterartor
    {
        public:
			typedef typename ft::iterator_traits<Iterator>::difference_type		differeence_type;
        	typedef typename ft::iterator_traits<Iterator>::value_type			constvalue_type;
			typedef typename ft::iterator_traits<Iterator>::value_type*			pointer;
			typedef typename ft::iterator_traits<Iterator>::value_type&			reference;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef Iterator*													iterator_type;

        /*	
		*	📌 CONSTRUCTOR / DESTRCUTOR
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/	

// 📚 default constructor
		Rb_tree_const_iterartor(): __node(0x0), __end(0x0)
		{}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 fill constructor
		Rb_tree_const_iterartor(iterator_type node, iterator_type end): __node(node), __end(end)
		{}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 copy constructor

		Rb_tree_const_iterartor(const Rb_tree_const_iterartor& rbt_it): __node(rbt_it.__node), __end(rbt_it.__end)
		{}

// operator assigning copy
		Rb_tree_const_iterartor& Rb_tree_const_iterartor(const Rb_tree_const_iterartor& rbt_it)
		{
			if (this != &rbt_it)
			{
				this->__node = rbt_it.__node;
				this->__end = rbt_it.__end;
			}
			return (*this);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Destructor
		~Rb_tree_const_iterartor() {}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

        /*
        *   📌 MEMBER FUNCTION 
        */

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 relational operator
		bool operator==(const Rb_tree_const_iterartor& rbt_it)
		{
			return (this->__node == rbt_it.__node);
		}

		bool operator!=(const Rb_tree_const_iterartor& rbt_it)
		{
			return (!(this->__node == rbt_it.__node));
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a const reference to the element pointed to by the Iterator;
        reference operator*() const
		{
			return (__node->__key)
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a const pointer to the element pointed to by the Iterator;
		pointer operator->() const
		{
			return (&this->__node->__key);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Increment the iterator to the next elem
		Rb_tree_const_iterartor&	operator++()
		{
			icrem_iterator();
			return (*this);
		}

// 📚 PostIncrement the iterator to the next elem
		Rb_tree_const_iterartor&	operator++(int)
		{
			Rb_tree_const_iterartor tmp;

			tmp = *this;
			icrem_iterator();
			return (tmp);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Decrement the iterator to the previous elem
		Rb_tree_const_iterartor&	operator--()
		{
			decrem_iterator();
			return (*this);
		}

// 📚 Postdecrement the iterator to the previous elem
		Rb_tree_const_iterartor&	operator--(int)
		{
			Rb_tree_iterartor tmp;

			tmp = *this;
			decrem_iterator();
			return (tmp);
		}


/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		private:
			iterator_type														__node;
			iterator_type														__end;
		

		void	icrem_iterator()
		{
			if (this->__node)
			{
				if (this->__node->__right) //if right child exist go to the smaller go to the smaller node of this subtree
				{
					this->__node = this->__node->__right;
					while (this->__node->__left)
						this->__node = this->__node->__left;
				}
				else // else go to the next left parent 
				{
					while (this->__node->__parent && this->__node == this->__node->__parent->__right)
						this->__node = this->__node->__parent;
					this->__node = this->__node->__parent;
				}
			}
		}

		void	decrem_iterator()
		{
			if (this->__node)
			{
				if (this->__node->left) // if left child exist, go to the biger node from this sub tree
					this->__node = this->__node->left;
				while (this->__node->right)
					this->__node = this->node->right;
			}
			else // go to the next right parent
			{
				while (this->__node->parent && this->__node == this->__node->__parent->-_left)
					this->__node = this->__node->parent;
				this->__node = this->__node->__parent;
			}
		}
    };

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/	
}

#endif