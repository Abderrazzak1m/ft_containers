/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:17:33 by amiski            #+#    #+#             */
/*   Updated: 2023/02/08 01:12:50 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>
#include <cstddef>

namespace ft
{
    template <typename T>
    class iterator
    {
    public:
        // Member types
        typedef typename std::random_access_iterator_tag iterator_category;
        typedef T value_type;
        typedef T &reference;
        typedef T *pointer;
        typedef typename std::ptrdiff_t difference_type;
        // consractor
        iterator() {}
        iterator(pointer ptr) : current(ptr)
        {
        }
        iterator(const iterator &other)
        {
            *this = other;
        }
        iterator &operator=(const iterator &other)
        {
            this->current = other.current;
            return (*this);
        }
        // operator
        reference operator*()
        {
            return *(this->current);
        }
        pointer operator->()
        {
            return this->current;
        }
        // Comparison operators
        bool operator==(const iterator &other) const
        {
            return current == other.current;
        }
        bool operator!=(const iterator &other) const
        {
            return current != other.current;
        }
        bool operator<(const iterator &other) const
        {
            return (current < other.current);
        }
        bool operator>(const iterator &other) const
        {
            return (current > other.current);
        }
        bool operator<=(const iterator &other) const
        {
            return (current <= other.current);
        }
        bool operator>=(const iterator &other) const
        {
            return (current >= other.current);
        }

        // Random access operators
        iterator operator+(int n) const
        {
            return (iterator(this->current + n));
        }
        iterator operator-(int n) const
        {
            return (iterator(this->current - n));
        }
        iterator &operator+=(int n)
        {
            this->current += n;
            return (*this);
        }
        iterator &operator-=(int n)
        {
            this->current -= n;
            return (*this);
        }
        iterator operator++()
        {
            ++current;
            return *this;
        }
        iterator operator++(int)
        {
            pointer tmp = this->current;
            ++current;
            return tmp;
        }
        iterator operator--()
        {
            --current;
            return *this;
        }
        iterator operator--(int)
        {
            pointer tmp = this->current;
            --current;
            return tmp;
        }
        reference operator[](std::size_t index)
        {
            return current[index];
        }

    private:
        pointer current;
    };
}
#endif