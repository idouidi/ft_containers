/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:28:30 by idouidi           #+#    #+#             */
/*   Updated: 2023/02/24 01:06:26 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  __ITERATOR__HPP__
# define __ITERATOR__HPP__

# include <iostream>

namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};


    /*      *       *       *   Traits class        *       *       *
    *
    *   defining properties of iterators.
    *
    *   difference_type     ; Type to express the result of subtracting one iterator from another.
    *   value_type          : The type of the element the iterator can point to.
    *   pointer             : The type of a pointer to an element the iterator can point to.
    *   reference           : The type of a reference to an element the iterator can point to.
    *   iterator_category   : It can be imput_iterator/output_iterator/forward_iterator/bidirectional_iterator/random_acces_iterator
    *       *       *       *       *       *       *       *       */
	template <class Iterator> 
	class iterator_traits{
		public:
			typedef typename Iterator::difference_type      difference_type;
			typedef typename Iterator::value_type           value_type;
			typedef typename Iterator::pointer              pointer;
			typedef typename Iterator::reference            reference;
			typedef typename Iterator::iterator_category    iterator_category;
	};

    template < class T >
    struct iterator_traits< T * >
    {
        typedef std::ptrdiff_t                              difference_type;
        typedef T                                           value_type;
        typedef value_type*                                 pointer;
        typedef value_type&                                 reference;
        typedef random_access_iterator_tag                  iterator_category;  
    };

    template < class T >
    struct iterator_traits< const T * >
    {
        typedef std::ptrdiff_t                              difference_type;
        typedef T                                           value_type;
        typedef const value_type*                           pointer;
        typedef const value_type&                           reference;
        typedef random_access_iterator_tag                  iterator_category;     
    };



    /*      *       *       *   Reverse Iterator class     *       *        *
    *
    *   A copy of the original iterator class is kept 
    *   internally and used to reflect the operations performed on the reverse_iterator: 
    *   whenever the reverse_iterator is incremented, its base iterator is decreased, and vice versa. 
    *       *       *       *       *       *       *       *       *       */
    
    template < class Iterator >
    class reverse_iterator
    {
        public:
            typedef Iterator                                                   iterator_type;
            typedef typename ft::iterator_traits<Iterator>::iterator_category  iterator_category;
            typedef typename ft::iterator_traits<Iterator>::value_type         value_type;
            typedef typename ft::iterator_traits<Iterator>::difference_type    difference_type;
            typedef typename ft::iterator_traits<Iterator>::pointer            pointer;
            typedef typename ft::iterator_traits<Iterator>::reference          reference;
        protected:
            iterator_type   __elem;
        public:

		/*	
		*	📌 CONSTRUCTOR 
		*/

        // 📚 DEFAULT CONSTRUCTOR: Constructs a reverse iterator that points to no object.
        reverse_iterator(): __elem() {}

        // 📚 INITIALIZATION CONSTRUCTOR: Constructs a reverse iterator from some original iterator it.
        explicit reverse_iterator (iterator_type it): __elem(it) {}

        //📚 COPY CONSTRUCTOR
        template <class Iter>
        reverse_iterator (const reverse_iterator<Iter>& rev_it) : __elem(rev_it.base()) {};
        reverse_iterator (const reverse_iterator& rev_it) : __elem(rev_it.base()) {};

        // OPERATOR COPY AFFECTATION
        reverse_iterator& operator=(const reverse_iterator& other)
        {
            this->__elem = other.__elem;
            return (*this);
        }

        /*
        *   📌 MEMBER FUNCTION 
        */

	    template <class U>
	    bool	operator==(const reverse_iterator<U>& rhs) { return (this->base() == rhs.base()); }

	    template <class U>
	    bool	operator!=(const reverse_iterator<U>& rhs) { return (this->base() != rhs.base()); }
	
	    template <class U>
	    bool	operator<(const reverse_iterator<U>& rhs) { return (this->base() > rhs.base()); }
	
	    template <class U>
	    bool	operator>(const reverse_iterator<U>& rhs) { return (this->base() < rhs.base()); }
	
	    template <class U>
	    bool	operator<=(const reverse_iterator<U>& rhs) { return (this->base() >= rhs.base()); }
	
	    template <class U>
	    bool	operator>=(const reverse_iterator<U>& rhs) { return (this->base() <= rhs.base()); }

       // 📚 Returns a copy of the base iterator.
       iterator_type base() const { return this->__elem; }


       // 📚 Returns a reverse iterator pointing to the element located n 
       //   positions away from the element the iterator currently points to.
       reverse_iterator operator+(difference_type n) const { return (reverse_iterator(this->__elem - n)); }

       // 📚 Advances the reverse_iterator by one position.
       reverse_iterator& operator++()
       {
            this->__elem--;
            return (*this);
       }
       reverse_iterator operator++(int)
       {
            reverse_iterator tmp = (*this);
            --this->__elem;
            return (tmp);
       }

       // 📚 Advances the reverse_iterator by n element positions.
       reverse_iterator& operator+= (difference_type n)
       {
            this->__elem -= n;
            return (*this);
       }

       // 📚 Returns a reverse iterator pointing to the element located n 
       // positions before the element the iterator currently points to.
       reverse_iterator operator-(difference_type n) const { return (reverse_iterator(this->__elem + n)); }

       // 📚 Decreases the reverse_iterator by one position.
       reverse_iterator& operator--()
       {
            ++this->__elem;
            return (*this);
       }
       reverse_iterator operator--(int)
       {
            reverse_iterator tmp = (*this);
            --(*this);
            return (tmp);
       }

       // 📚 Descreases the reverse_iterator by n element positions.
       reverse_iterator& operator-= (difference_type n)
       {
            this->__elem += n;
            return (*this);
       }

       // 📚 Returns a reference to the element pointed to by the iterator.
        reference operator*() const
       {
            iterator_type tmp;

            tmp = (this->__elem);
            return *(--tmp);
       }
       // 📚 Returns a pointer to the element pointed to by the iterator (in order to access one of its members).
       pointer operator->() const { return &(operator*()); }

       // 📚 Accesses the element located n positions away from the element currently pointed to by the iterator.
       reference operator[](difference_type n) const { return *(this->operator+(n)); }
        
    };

    // 📚 Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.

    // ==
    template <class Iterator>
    bool operator== (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <class U, class X>
    bool operator== (const ft::reverse_iterator<U>& lhs, const ft::reverse_iterator<X>& rhs)
    {
        return (lhs.base() == rhs.base());
    }

    // !=
    template <class Iterator>
    bool operator!= (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <class U, class X>
    bool operator!= (const ft::reverse_iterator<U>& lhs, const ft::reverse_iterator<X>& rhs)
    {
        return (lhs.base() != rhs.base());
    }

    // <
    template <class Iterator>
    bool operator<  (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class U, class X>
    bool operator<  (const ft::reverse_iterator<U>& lhs, const ft::reverse_iterator<X>& rhs)
    {
        return (lhs.base() > rhs.base());
    }

    // <=
    template <class Iterator>
    bool operator<=  (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    template <class U, class X>
    bool operator<=  (const ft::reverse_iterator<U>& lhs, const ft::reverse_iterator<X>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    // >
    template <class Iterator>
    bool operator >  (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class U, class X>
    bool operator >  (const ft::reverse_iterator<U>& lhs, const ft::reverse_iterator<X>& rhs)
    {
        return (lhs.base() < rhs.base());
    }

    // >=
    template <class Iterator>
    bool operator >=  (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    template <class U, class X>
    bool operator >=  (const ft::reverse_iterator<U>& lhs, const ft::reverse_iterator<X>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    // +
    template<class Iterator>
    ft::reverse_iterator<Iterator> operator+(typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator>& rev_it)
    {
        return (ft::reverse_iterator<Iterator>(rev_it.base() - n));
    }

    // -
    template<class Iterator>
    typename ft::reverse_iterator<Iterator>::difference_type operator-(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
    {
        return (rhs.base() - lhs.base()) ;
    }
    template<class U, class X>
    typename ft::reverse_iterator<U>::difference_type operator-(const ft::reverse_iterator<U>& lhs, const ft::reverse_iterator<X>& rhs)
    {
        return (rhs.base() - lhs.base()) ;
    }
}

#endif