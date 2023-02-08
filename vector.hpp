/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:41:43 by amiski            #+#    #+#             */
/*   Updated: 2023/02/08 05:25:30 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "reverse_iterator.hpp"
#include "utils.hpp"

namespace ft
{
  template <typename T, typename Alloc = std::allocator<T> >
  class vector
  {
  public:
    typedef T value_type;
    typedef Alloc allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef typename ft::iterator<value_type> iterator;
    typedef typename ft::iterator<const value_type> const_iterator;
    typedef typename ft::reverse_iterator<iterator> reverse_iterator;
    typedef typename ft::reverse_iterator<const iterator> const_reverse_iterator;
    typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
    typedef typename std::size_t size_type;

    // default constructor
    explicit vector(const allocator_type &alloc = allocator_type())
        : allocater(alloc), data(NULL), ft_size(0), ft_capacity(0)
    {
    }
    // fill constructor
    explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
        : allocater(alloc)
    {
      ft_capacity = (n > 0) ? n : 1;
      this->data = allocater.allocate(ft_capacity);
      this->ft_size = n;
      for (size_type i = 0; i < n; i++)
        this->allocater.construct(data + i, val);
    }
    // rang constructor
    template <class InputIterator>
    vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) : allocater(alloc)
    {
      this->ft_size = last - first;
      int i = 0;
      this->ft_capacity = last - first;
      this->data = this->allocater.allocate(this->ft_capacity);
      while (first != (last))
      {
        this->allocater.construct(this->data + i, *first);
        i++;
        first++;
      }
    }
    // copy constructor
    vector(const vector &x)
    {
      *this = x;
    }

    // destroctor
    ~vector(){};
    // operator =
    vector &operator=(const vector &x)
    {

      this->data = x.data;
      this->ft_size = x.ft_size;
      this->ft_capacity = x.ft_capacity;
      this->allocater = x.allocater;

      return (*this);
    };

    // iterator
    iterator begin()
    {
      return (this->data);
    }
    iterator end()
    {
      return (this->data + this->size());
    }
    reverse_iterator rbegin()
    {
      return reverse_iterator(this->end() - 1);
    }
    reverse_iterator rend()
    {
      return reverse_iterator(this->begin() - 1);
    }
    // Capacity
    size_type size() const
    {
      return (this->ft_size);
    }
    size_type maxsize() const
    {
      return (this->ft_size);
    }
    void resize(size_type n)
    {
      if (n >= ft_size)
        return;
      pointer newdata = allocater.allocate(this->ft_capacity);
      for (size_type i = 0; i < n; i++)
      {
        allocater.construct(newdata + i, data[i]);
      }
      allocater.deallocate(data, ft_size);
      data = newdata;
      ft_size = n;
    }
    size_type capacity() const
    {
      return (this->ft_capacity);
    }
    bool empty() const
    {
      return (this->ft_size == 0);
    }
    void reserve(size_type n)
    {
      if (n <= ft_capacity)
        return;
      pointer newdata = allocater.allocate(n);
      for (size_type i = 0; i < ft_size; i++)
      {
        allocater.construct(newdata + i, data[i]);
      }
      allocater.deallocate(data, ft_size);
      data = newdata;
      ft_capacity = n;
    }
    // fill assign
    void assign(size_type n, const value_type &val)
    {
      this->ft_size = n;
      allocater.deallocate(data, this->ft_capacity);
      if (n > this->ft_capacity)
        this->ft_capacity = n;
      pointer tmp = allocater.allocate(this->ft_capacity);
      for (size_type i = 0; i < n; i++)
      {
        allocater.construct(tmp + i, val);
      }
      this->data = tmp;
    }
    // range assign
    template <class InputIterator>
    void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
    {
      this->ft_size = last - first;
      int i = 0;
      allocater.deallocate(data, this->ft_capacity);
      if (this->ft_size > this->ft_capacity)
        this->ft_capacity = this->ft_size;
      pointer tmp = allocater.allocate(this->ft_capacity);
      while(first != last)
      {
        allocater.construct(tmp + i, *first);
        first++;
        i++;
      }
      this->data = tmp;
    }
    //push_back
    void push_back (const value_type& val)
    {
      if(ft_size == ft_capacity && ft_capacity == 0)
      {
        ft_capacity++;
        data = allocater.allocate(1);
        allocater.construct(data, val);
      }
      else if(ft_size == ft_capacity)
      {
        this->reserve(ft_capacity * 2);
        allocater.construct(data + ft_size, val);
      }
      else
        allocater.construct(data + ft_size, val);
      ft_size++;
    }

  private:
    Alloc allocater;
    pointer data;
    size_type ft_size;
    size_type ft_capacity;
  };
}

#endif