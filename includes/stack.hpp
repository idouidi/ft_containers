/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 02:11:41 by idouidi           #+#    #+#             */
/*   Updated: 2023/01/26 16:26:00 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STACK_HPP__
#define __STACK_HPP__

# include "./ftnspace.hpp"

namespace ft
{
    template < class T, class Container = ft::vector<T> >
    class stack
    {

        public:
	        typedef Container                                   container_type;
            typedef typename container_type::value_type         value_type;
	        typedef typename container_type::size_type          size_type;
            typedef typename container_type::reference         reference;
            typedef typename container_type::const_reference   const_reference;
            

        /*	
		*	📌 CONSTRUCTOR / DESTRCUTOR
		*/

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Constructs a stack container adaptor object.
        explicit stack (const container_type& ctnr = container_type()): __ctnr(ctnr) {}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Replaces the contents of the container adaptor with those of other.
    stack& operator=( const stack& other )
    {
        if (this == &other)
            return (*this);
        this->__ctnr = other.__ctnr;
    }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Destructor
    ~stack() {}

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns whether the stack is empty: i.e. whether its size is zero.
bool   empty() const { return(this->__ctnr.empty()); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns the number of elements in the stack.
size_type   size() const { return(this->__ctnr.size()); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Returns a reference to the top element in the stack.
    reference    top() { return (this->__ctnr.back()); }
    const_reference top() const { return (this->__ctnr.back()); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Inserts a new element at the top of the stack, above its current top element.
// The content of this new element is initialized to a copy of val.
    void    push(const value_type& val) { this->__ctnr.push_back(val); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

// 📚 Removes the element on top of the stack, effectively reducing its size by one.
    void    pop() { this->__ctnr.pop_back(); }

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

        protected:
            container_type __ctnr;
    };

/*	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	:	*/

	template< class T, class Container >
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) 
    {
		return (lhs.container == rhs.container);
	}

	template< class T, class Container >
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) 
    {
		return (lhs.container != rhs.container);
	}

	template< class T, class Container >
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) 
    {
		return (lhs.container < rhs.container);
	}

	template< class T, class Container >
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) 
    {
		return (lhs.container <= rhs.container);
	}

	template< class T, class Container >
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) 
    {
		return (lhs.container > rhs.container);
	}

	template< class T, class Container >
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) 
    {
		return (lhs.container >= rhs.container);
	}
}

#endif