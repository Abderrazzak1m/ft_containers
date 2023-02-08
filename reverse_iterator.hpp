/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:38:43 by amiski            #+#    #+#             */
/*   Updated: 2023/02/08 02:23:45 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include <iostream>
#include "iterator_traits.hpp"
#include "iterator.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
    public:
        // Memeber types
        typedef Iterator iterator_type;
        typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<Iterator>::value_type value_type;
        typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
        typedef typename ft::iterator_traits<Iterator>::pointer pointer;
        typedef typename ft::iterator_traits<Iterator>::reference reference;

        //Constructors
        
        /*default*/
        reverse_iterator(): _it(NULL){};
        /*initialization*/
        explicit reverse_iterator(iterator_type it): _it(it)
        {
        }
        /*copy*/
        template <class Iter>
        reverse_iterator(const reverse_iterator<Iter> &rev_it): _it(rev_it.base())
        {
        }
        // Memeber function
        iterator_type base() const
        {return (_it);}

       reference operator*() const
        {
            iterator_type tmp(_it);
            
            return (*tmp);
        }
        
        //operator ++it
        reverse_iterator& operator++()
        {
            --_it;
            return(*this);
        }
        //operator it++
        reverse_iterator operator++(int)
        {
             reverse_iterator tmp = *this;
             --_it;
             return(tmp);
        }
        //operator --it
        reverse_iterator& operator--()
        {
            ++_it;
            return(*this);
        }
        // operator it--
        reverse_iterator operator--(int)
        {
             reverse_iterator tmp = *this;
             ++_it;
             return(tmp);
        }
        
        reverse_iterator operator+ (difference_type n) const
        {
            return reverse_iterator(this->_it - n);
        }
        reverse_iterator operator- (difference_type n) const
        {
            return(reverse_iterator(this->_it + n));
        }
        reverse_iterator& operator+= (difference_type n)
        {
            this->_it -= n;
                return(*this);
        }
        reverse_iterator& operator-= (difference_type n)
        {
            this->_it += n;
                return(*this);
        }
        pointer operator->() const
        {
            return (&(operator*()));
        }
        reference operator[] (difference_type n) const
        {
             return (base()[-n-1]);
        }
    private:
        iterator_type _it;
    };
}

#endif