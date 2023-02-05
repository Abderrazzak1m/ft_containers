/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:17:33 by amiski            #+#    #+#             */
/*   Updated: 2023/02/05 20:02:15 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <cstddef>


namespace ft
{
    template<typename T>
    class iterator
    {
        public:
            //Member types
            typedef typename std::random_access_iterator_tag       iterator_category;
            typedef T                                   value_type;
            typedef T&                                  Reference;
            typedef T*                                  Pointer;
            typedef typename  std::ptrdiff_t                      difference_type;
            //consractor
            iterator(){}
            iterator(Pointer ptr):current(ptr)
            {
            }
            iterator(const iterator& other)
            {
                *this = other;
            }         
            iterator& operator=(const iterator& other)
            {
                this->current = other.current;
                return (*this);   
            }
            //operator
            Reference operator*()
            {
                return *this->current;
            }
            Pointer operator->()
            {
                return this->current;
            } 
            // Comparison operators
            bool operator==(const iterator& other) const
            {
                return current == other.current;
            }
            bool operator!=(const iterator& other) const
            {
                return current != other.current;
            }
            bool operator<(const iterator& other) const
            {
                return(current < other.current);
            }
            bool operator>(const iterator& other) const
            {
                return(current > other.current);
            }
            bool operator<=(const iterator& other) const
            {
                return(current <= other.current);
            }
            bool operator>=(const iterator& other) const
            {
                return(current >= other.current);
            }

            // Random access operators
            iterator operator+(int n) 
            {
                return(iterator(this->current + n));
            }
            iterator operator-(int n) 
            {
                return(iterator(this->current - n));
            }
            iterator& operator+=(int n) 
            {
                this->current += n;
                return(*this);
            }
            iterator& operator-=(int n) 
            {
                this->current -= n;
                return(*this);
            }
        private:
            Pointer current;
    };
}