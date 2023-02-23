/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:03:39 by idouidi           #+#    #+#             */
/*   Updated: 2023/02/23 14:15:07 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef __RED_BLACK_TREE_ITERATOR_HPP__
# define __RED_BLACK_TREE_ITERATOR_HPP__

// # include "./ftnspace.hpp"		//my test

# include "iterator.hpp"		// tester


namespace ft
{

    template < class Iterator>
    class Rb_tree_iterator
    {
        public:
        	typedef std::ptrdiff_t              	difference_type;
        	typedef typename Iterator::pair_type	value_type;
        	typedef value_type*                 	pointer;
        	typedef value_type&                 	reference;
        	typedef random_access_iterator_tag  	iterator_category;  
			typedef Iterator*						iterator_type;

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/	
        /*	
		*	📌 CONSTRUCTOR / DESTRCUTOR
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/	

// 📚 default constructor
		Rb_tree_iterator(): __node(0x0)
		{}
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 fill constructor
		Rb_tree_iterator(iterator_type node): __node(node)
		{}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 copy constructor

		Rb_tree_iterator(const Rb_tree_iterator& rbt_it): __node(rbt_it.__node)
		{}

// operator assigning copy
		Rb_tree_iterator& operator=(const Rb_tree_iterator& rbt_it)
		{
			if (this != &rbt_it)
			{
				this->__node = rbt_it.__node;
			}
			return (*this);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Destructor
		~Rb_tree_iterator() {}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

        /*
        *   📌 MEMBER FUNCTION 
        */

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

	iterator_type base() const { return(this->__node); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 relational operator
		bool operator==(const Rb_tree_iterator& rbt_it)
		{
			return (this->__node == rbt_it.__node);
		}

		bool operator!=(const Rb_tree_iterator& rbt_it)
		{
			return (!(this->__node == rbt_it.__node));
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a const reference to the element pointed to by the Iterator;
        reference operator*() const
		{
			return (this->__node->__pair);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a const pointer to the element pointed to by the Iterator;
		pointer operator->() const
		{
			return (&(this->__node->__pair));
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Increment the iterator to the next elem
		Rb_tree_iterator&	operator++()
		{
			icrem_iterator();
			return (*this);
		}

// 📚 PostIncrement the iterator to the next elem
		Rb_tree_iterator	operator++(int)
		{
			Rb_tree_iterator tmp;

			tmp = *this;
			icrem_iterator();
			return (tmp);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Decrement the iterator to the previous elem
		Rb_tree_iterator&	operator--()
		{
			decrem_iterator();
			return (*this);
		}

// 📚 Postdecrement the iterator to the previous elem
		Rb_tree_iterator	operator--(int)
		{
			Rb_tree_iterator tmp;

			tmp = *this;
			decrem_iterator();
			return (tmp);
		}


/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		private:
			iterator_type														__node;
		

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
				if (this->__node->__left) // if left child exist, go to the biger node from this sub tree
					this->__node = this->__node->__left;
				while (this->__node->__right)
					this->__node = this->__node->__right;
			}
			else // go to the next right parent
			{
				while (this->__node->__parent && this->__node == this->__node->__parent->__left)
					this->__node = this->__node->__parent;
				this->__node = this->__node->__parent;
			}
		}
    };

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		/*	
		*	📌 RED BLACK TREE CONST_ITERATOR
		*/
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

    template < class Iterator>
    class Rb_tree_const_iterator 
    {
        public:
        public:
        	typedef std::ptrdiff_t              	difference_type;
        	typedef typename Iterator::pair_type	const value_type;
        	typedef value_type*                 	pointer;
        	typedef value_type&                 	reference;
        	typedef random_access_iterator_tag  	iterator_category;  
			typedef Iterator*						iterator_type;


        /*	
		*	📌 CONSTRUCTOR / DESTRCUTOR
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/	

// 📚 default constructor
		Rb_tree_const_iterator(): __node(0x0)
		{}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 fill constructor
		Rb_tree_const_iterator(iterator_type node): __node(node)
		{}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 copy constructor

		Rb_tree_const_iterator(const Rb_tree_const_iterator& rbt_it): __node(rbt_it.__node)
		{}

		Rb_tree_const_iterator(const Rb_tree_iterator<Iterator>& rbt_it): __node(rbt_it.base())
		{}

// operator assigning copy
		Rb_tree_const_iterator& operator=(const Rb_tree_const_iterator& rbt_it)
		{
			if (this != &rbt_it)
			{
				this->__node = rbt_it.__node;
			}
			return (*this);
		}
		Rb_tree_const_iterator& operator=(Rb_tree_iterator<Iterator>& rbt_it)
		{
			if (this != &rbt_it)
			{
				this->__node = rbt_it.__node;
			}
			return (*this);
		}
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Destructor
		~Rb_tree_const_iterator() {}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

        /*
        *   📌 MEMBER FUNCTION 
        */

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

	iterator_type base() const { return(this->__node); }

// 📚 relational operator
		bool operator==(const Rb_tree_const_iterator& rbt_it)
		{
			return (this->__node == rbt_it.__node);
		}

		bool operator!=(const Rb_tree_const_iterator& rbt_it)
		{
			return (!(this->__node == rbt_it.__node));
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a const pointer to the element pointed to by the Iterator;
		reference operator*() const
		{
			return (this->__node->__pair);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a const reference to the element pointed to by the Iterator;
       	pointer operator->() const
		{
			return (&(this->__node->__pair));
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Increment the iterator to the next elem
		Rb_tree_const_iterator&	operator++()
		{
			icrem_iterator();
			return (*this);
		}

// 📚 PostIncrement the iterator to the next elem
		Rb_tree_const_iterator	operator++(int)
		{
			Rb_tree_const_iterator tmp;

			tmp = *this;
			icrem_iterator();
			return (tmp);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Decrement the iterator to the previous elem
		Rb_tree_const_iterator&	operator--()
		{
			decrem_iterator();
			return (*this);
		}

// 📚 Postdecrement the iterator to the previous elem
		Rb_tree_const_iterator	operator--(int)
		{
			Rb_tree_const_iterator tmp;

			tmp = *this;
			decrem_iterator();
			return (tmp);
		}


/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		protected:
			iterator_type														__node;
		

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
				if (this->__node->__left) // if left child exist, go to the biger node from this sub tree
					this->__node = this->__node->__left;
				while (this->__node->__right)
					this->__node = this->__node->__right;
			}
			else // go to the next right parent
			{
				while (this->__node->__parent && this->__node == this->__node->__parent->__left)
					this->__node = this->__node->__parent;
				this->__node = this->__node->__parent;
			}
		}
    };

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		/*	
		*	📌 RED BLACK TREE REVERSE ITERATOR
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

	template < class Iterator>
	class Rb_tree_reverse_iterator
	{
		public:
        	typedef std::ptrdiff_t              	difference_type;
        	typedef typename Iterator::pair_type	value_type;
        	typedef value_type*                 	pointer;
        	typedef value_type&                 	reference;
        	typedef random_access_iterator_tag  	iterator_category;  
			typedef Iterator*						iterator_type;

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/	

// 📚 default constructor
		Rb_tree_reverse_iterator(): __node(0x0)
		{}
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 fill constructor
		Rb_tree_reverse_iterator(iterator_type node): __node(node)
		{}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 copy constructor

		Rb_tree_reverse_iterator(const Rb_tree_reverse_iterator& rbt_it): __node(rbt_it.__node)
		{}

// operator assigning copy
		Rb_tree_reverse_iterator& operator=(const Rb_tree_reverse_iterator& rbt_it)
		{
			if (this != &rbt_it)
			{
				this->__node = rbt_it.__node;
			}
			return (*this);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Destructor
		~Rb_tree_reverse_iterator() {}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

        /*
        *   📌 MEMBER FUNCTION 
        */

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a copy of the base iterator.
	iterator_type base() const { return(this->__node); }
		
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 relational operator
		bool operator==(const Rb_tree_reverse_iterator& rbt_it)
		{
			return (this->__node == rbt_it.__node);
		}

		bool operator!=(const Rb_tree_reverse_iterator& rbt_it)
		{
			return (!(this->__node == rbt_it.__node));
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reference to the element pointed to by the iterator.
        reference operator*() const { return *(this->__node); }
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

//  📚 Returns a pointer to the element pointed to by the iterator (in order to access one of its members).
		pointer		operator->() const { return (&(operator*())); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Accesses the element located n positions away from the element currently pointed to by the iterator.
       reference operator[](difference_type n) const { return *(this->operator+(n)); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Increase the iterator by one position.

// 📚 pre
		Rb_tree_reverse_iterator&	operator--() 
		{
			++(this->__node);
			return (*this);
			
		}
// 📚 post
		Rb_tree_reverse_iterator	operator--(int) 
		{
			Rb_tree_reverse_iterator		tmp(*this);
			++(*this);
			return (tmp);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reverse iterator pointing to the element located n 
// positions before the element the iterator currently points to.
		Rb_tree_reverse_iterator operator-(difference_type n) const { return (Rb_tree_reverse_iterator(this->__elem + n)); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Descreases the reverse_iterator by n element positions.
	Rb_tree_reverse_iterator& operator-= (difference_type n)
	{
	     this->__elem += n;
	     return (*this);
	}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Decreases the iterator by one position.

// 📚 pre
		Rb_tree_reverse_iterator&	operator++() 
		{
			--(this->__node);
			return (*this);
		}

// 📚 post
		Rb_tree_reverse_iterator	operator++(int) 
		{
			Rb_tree_reverse_iterator	tmp(*this);
			--(*this);
			return (tmp);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reverse iterator pointing to the element located n 
// positions away from the element the iterator currently points to.
       Rb_tree_reverse_iterator operator+(difference_type n) const { return (Rb_tree_reverse_iterator(this->__node - n)); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/
       
// 📚 Advances the reverse_iterator by n element positions.
       Rb_tree_reverse_iterator& operator+= (difference_type n)
       {
            this->__elem -= n;
            return (*this);
       }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		protected:
			iterator_type								__node;

	};
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/
    // ==
    template <class Iterator>
    bool operator== (const ft::Rb_tree_reverse_iterator<Iterator>& lhs, const ft::Rb_tree_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <class U, class X>
    bool operator== (const ft::Rb_tree_reverse_iterator<U>& lhs, const ft::Rb_tree_reverse_iterator<X>& rhs)
    {
        return (lhs.base() == rhs.base());
    }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

    // !=
    template <class Iterator>
    bool operator!= (const ft::Rb_tree_reverse_iterator<Iterator>& lhs, const ft::Rb_tree_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <class U, class X>
    bool operator!= (const ft::Rb_tree_reverse_iterator<U>& lhs, const ft::Rb_tree_reverse_iterator<X>& rhs)
    {
        return (lhs.base() != rhs.base());
    }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

    // <
    template <class Iterator>
    bool operator<  (const ft::Rb_tree_reverse_iterator<Iterator>& lhs, const ft::Rb_tree_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class U, class X>
    bool operator<  (const ft::Rb_tree_reverse_iterator<U>& lhs, const ft::Rb_tree_reverse_iterator<X>& rhs)
    {
        return (lhs.base() > rhs.base());
    }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

	// <=
    template <class Iterator>
    bool operator<=  (const ft::Rb_tree_reverse_iterator<Iterator>& lhs, const ft::Rb_tree_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    template <class U, class X>
    bool operator<=  (const ft::Rb_tree_reverse_iterator<U>& lhs, const ft::Rb_tree_reverse_iterator<X>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

    // >
    template <class Iterator>
    bool operator >  (const ft::Rb_tree_reverse_iterator<Iterator>& lhs, const ft::Rb_tree_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class U, class X>
    bool operator >  (const ft::Rb_tree_reverse_iterator<U>& lhs, const ft::Rb_tree_reverse_iterator<X>& rhs)
    {
        return (lhs.base() < rhs.base());
    }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

    // >=
    template <class Iterator>
    bool operator >=  (const ft::Rb_tree_reverse_iterator<Iterator>& lhs, const ft::Rb_tree_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    template <class U, class X>
    bool operator >=  (const ft::Rb_tree_reverse_iterator<U>& lhs, const ft::Rb_tree_reverse_iterator<X>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

    // +
    template<class Iterator>
    ft::Rb_tree_reverse_iterator<Iterator> operator+(typename ft::Rb_tree_reverse_iterator<Iterator>::difference_type n, const ft::Rb_tree_reverse_iterator<Iterator>& rev_it)
    {
        return (ft::Rb_tree_reverse_iterator<Iterator>(rev_it.base() - n));
    }

    // -
    template<class Iterator>
    typename ft::Rb_tree_reverse_iterator<Iterator>::difference_type operator-(const ft::Rb_tree_reverse_iterator<Iterator>& lhs, const ft::Rb_tree_reverse_iterator<Iterator>& rhs)
    {
        return (rhs.base() - lhs.base()) ;
    }
    template<class U, class X>
    typename ft::Rb_tree_reverse_iterator<U>::difference_type operator-(const ft::Rb_tree_reverse_iterator<U>& lhs, const ft::Rb_tree_reverse_iterator<X>& rhs)
    {
        return (rhs.base() - lhs.base()) ;
    }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		/*	
		*	📌 RED BLACK TREE CONST REVERSE ITERATOR
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

	template < class Iterator>
	class Rb_tree_const_reverse_iterator
	{
		public:
        	typedef std::ptrdiff_t              	difference_type;
        	typedef typename Iterator::pair_type	const value_type;
        	typedef value_type*                 	pointer;
        	typedef value_type&                 	reference;
        	typedef random_access_iterator_tag  	iterator_category;  
			typedef Iterator*						iterator_type;

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/	

// 📚 default constructor
		Rb_tree_const_reverse_iterator(): __node(0x0)
		{}
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 fill constructor
		Rb_tree_const_reverse_iterator(iterator_type node): __node(node)
		{}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 copy constructor

		Rb_tree_const_reverse_iterator(const Rb_tree_const_reverse_iterator& rbt_it): __node(rbt_it.__node)
		{}
		
		Rb_tree_const_reverse_iterator(const Rb_tree_iterator<Iterator>& rbt_it): __node(rbt_it.base())
		{}

// operator assigning copy
		Rb_tree_const_reverse_iterator& operator=(const Rb_tree_const_reverse_iterator& rbt_it)
		{
			if (this != &rbt_it)
			{
				this->__node = rbt_it.__node;
			}
			return (*this);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Destructor
		~Rb_tree_const_reverse_iterator() {}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

        /*
        *   📌 MEMBER FUNCTION 
        */

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a copy of the base iterator.
	iterator_type base() const { return(this->__node); }
		
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 relational operator
		bool operator==(const Rb_tree_const_reverse_iterator& rbt_it)
		{
			return (this->__node == rbt_it.__node);
		}

		bool operator!=(const Rb_tree_const_reverse_iterator& rbt_it)
		{
			return (!(this->__node == rbt_it.__node));
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reference to the element pointed to by the iterator.
        reference operator*() const { return *(this->__node); }
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

//  📚 Returns a pointer to the element pointed to by the iterator (in order to access one of its members).
		pointer		operator->() const { return (&(operator*())); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Accesses the element located n positions away from the element currently pointed to by the iterator.
       reference operator[](difference_type n) const { return *(this->operator+(n)); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Increase the iterator by one position.

// 📚 pre
		Rb_tree_const_reverse_iterator&	operator--() 
		{
			++(this->__node);
			return (*this);
			
		}
// 📚 post
		Rb_tree_const_reverse_iterator	operator--(int) 
		{
			Rb_tree_const_reverse_iterator		tmp(*this);
			++(*this);
			return (tmp);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reverse iterator pointing to the element located n 
// positions before the element the iterator currently points to.
		Rb_tree_const_reverse_iterator operator-(difference_type n) const { return (Rb_tree_const_reverse_iterator(this->__elem + n)); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Descreases the reverse_iterator by n element positions.
	Rb_tree_const_reverse_iterator& operator-= (difference_type n)
	{
	     this->__elem += n;
	     return (*this);
	}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Decreases the iterator by one position.

// 📚 pre
		Rb_tree_const_reverse_iterator&	operator++() 
		{
			--(this->__node);
			return (*this);
		}

// 📚 post
		Rb_tree_const_reverse_iterator	operator++(int) 
		{
			Rb_tree_const_reverse_iterator	tmp(*this);
			--(*this);
			return (tmp);
		}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reverse iterator pointing to the element located n 
// positions away from the element the iterator currently points to.
       Rb_tree_const_reverse_iterator operator+(difference_type n) const { return (Rb_tree_const_reverse_iterator(this->__node - n)); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/
       
// 📚 Advances the reverse_iterator by n element positions.
       Rb_tree_const_reverse_iterator& operator+= (difference_type n)
       {
            this->__elem -= n;
            return (*this);
       }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

		protected:
			iterator_type								__node;

	};
/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/
    // ==
    template <class Iterator>
    bool operator== (const ft::Rb_tree_const_reverse_iterator<Iterator>& lhs, const ft::Rb_tree_const_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <class U, class X>
    bool operator== (const ft::Rb_tree_const_reverse_iterator<U>& lhs, const ft::Rb_tree_const_reverse_iterator<X>& rhs)
    {
        return (lhs.base() == rhs.base());
    }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

    // !=
    template <class Iterator>
    bool operator!= (const ft::Rb_tree_const_reverse_iterator<Iterator>& lhs, const ft::Rb_tree_const_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <class U, class X>
    bool operator!= (const ft::Rb_tree_const_reverse_iterator<U>& lhs, const ft::Rb_tree_const_reverse_iterator<X>& rhs)
    {
        return (lhs.base() != rhs.base());
    }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

    // <
    template <class Iterator>
    bool operator<  (const ft::Rb_tree_const_reverse_iterator<Iterator>& lhs, const ft::Rb_tree_const_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class U, class X>
    bool operator<  (const ft::Rb_tree_const_reverse_iterator<U>& lhs, const ft::Rb_tree_const_reverse_iterator<X>& rhs)
    {
        return (lhs.base() > rhs.base());
    }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

	// <=
    template <class Iterator>
    bool operator<=  (const ft::Rb_tree_const_reverse_iterator<Iterator>& lhs, const ft::Rb_tree_const_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    template <class U, class X>
    bool operator<=  (const ft::Rb_tree_const_reverse_iterator<U>& lhs, const ft::Rb_tree_const_reverse_iterator<X>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

    // >
    template <class Iterator>
    bool operator >  (const ft::Rb_tree_const_reverse_iterator<Iterator>& lhs, const ft::Rb_tree_const_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class U, class X>
    bool operator >  (const ft::Rb_tree_const_reverse_iterator<U>& lhs, const ft::Rb_tree_const_reverse_iterator<X>& rhs)
    {
        return (lhs.base() < rhs.base());
    }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

    // >=
    template <class Iterator>
    bool operator >=  (const ft::Rb_tree_const_reverse_iterator<Iterator>& lhs, const ft::Rb_tree_const_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    template <class U, class X>
    bool operator >=  (const ft::Rb_tree_const_reverse_iterator<U>& lhs, const ft::Rb_tree_const_reverse_iterator<X>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

    // +
    template<class Iterator>
    ft::Rb_tree_const_reverse_iterator<Iterator> operator+(typename ft::Rb_tree_const_reverse_iterator<Iterator>::difference_type n, const ft::Rb_tree_const_reverse_iterator<Iterator>& rev_it)
    {
        return (ft::Rb_tree_const_reverse_iterator<Iterator>(rev_it.base() - n));
    }

    // -
    template<class Iterator>
    typename ft::Rb_tree_const_reverse_iterator<Iterator>::difference_type operator-(const ft::Rb_tree_const_reverse_iterator<Iterator>& lhs, const ft::Rb_tree_const_reverse_iterator<Iterator>& rhs)
    {
        return (rhs.base() - lhs.base()) ;
    }
    template<class U, class X>
    typename ft::Rb_tree_const_reverse_iterator<U>::difference_type operator-(const ft::Rb_tree_const_reverse_iterator<U>& lhs, const ft::Rb_tree_const_reverse_iterator<X>& rhs)
    {
        return (rhs.base() - lhs.base()) ;
    }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

}

#endif