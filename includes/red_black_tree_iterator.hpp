/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:03:39 by idouidi           #+#    #+#             */
/*   Updated: 2023/02/10 15:23:37 by idouidi          ###   ########.fr       */
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



/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		private:
			iterator_type														__node;
			iterator_type														__end;
    };

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/	
}

#endif