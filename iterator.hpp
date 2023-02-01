/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:17:33 by amiski            #+#    #+#             */
/*   Updated: 2023/02/01 03:02:49 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <cstddef>


namespace ft
{
    template<typename T>
    class ft_iterator
    {
        public:
            //Member types
            typedef typename std::random_access_iterator_tag       iterator_category;
            typedef T                                   value_type;
            typedef T&                                  Reference;
            typedef T*                                  Pointer;
            typedef typename  std::ptrdiff_t                      difference_type;
            //consractor
            ft_iterator(){}
            ft_iterator(const ft_iterator& other)
            {
                *this = other;
            }         
            ft_iterator& operator=(const ft_iterator& other)
            {
                *this->current = other.current;
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
            bool operator==(const ft_iterator& other) const
            {
                return current == other.current;
            }
            bool operator!=(const ft_iterator& other) const
            {
                return current != other.current;
            }
            bool operator<(const ft_iterator& other) const
            {
                return(current < other.current);
            }
            bool operator>(const ft_iterator& other) const
            {
                return(current > other.current);
            }
            bool operator<=(const ft_iterator& other) const
            {
                return(current <= other.current);
            }
            bool operator>=(const ft_iterator& other) const
            {
                return(current >= other.current);
            }

            // Random access operators
            ft_iterator operator+(int n) 
            {
                return(ft_iterator(this->current + n));
            }
            ft_iterator operator-(int n) 
            {
                return(ft_iterator(this->current - n));
            }
            ft_iterator& operator+=(int n) 
            {
                this->current += n;
                return(*this);
            }
            ft_iterator& operator-=(int n) 
            {
                this->current -= n;
                return(*this);
            }
        private:
            Pointer current;
    };
}