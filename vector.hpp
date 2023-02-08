/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:41:43 by amiski            #+#    #+#             */
/*   Updated: 2023/02/08 01:28:14 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include"reverse_iterator.hpp"
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
        : _alloc(alloc)
    {
    }
    // fill constructor
    explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
        : _alloc(alloc)
    {
      _capacity = (n > 0) ? n : 1;
      this->_data = _alloc.allocate(_capacity);
      this->_size = n;
      for (size_type i = 0; i < n; i++)
        this->_alloc.construct(_data + i, val);
    }
    // rang constructor
    template <class InputIterator>

    vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
    {
      (void)alloc;
      this->_size = last - first;
      int i = 0;
      this->_capacity = last - first;
      this->_data = this->_alloc.allocate(this->_capacity);
      while (first != (last))
      {
        this->_alloc.construct(this->_data + i, *first);
        i++;
        first++;
      }
    }
    // destructor
    
    ~vector(){};
    
    // operator =
    
    vector& operator= (const vector& x)
    {
     
        this->_data = x._data;
        this->_size = x._size; 
        this->_capacity = x._capacity;
        this->_alloc = x._alloc;
      
      return(*this);
    };

    //iterator
    iterator begin()
    {
      return(this->_data);
    }
    iterator end()
    {
      return(this->_data + this->size());
    }
    reverse_iterator rbegin()
    {
      return reverse_iterator(this->end() - 1);
    }
    reverse_iterator rend()
    {
      return reverse_iterator(this->begin() - 1);
    }
    //Capacity
    size_type size() const
    {
      return(this->_size);
    }
    size_type max_size() const
    {
      return(this->_size);
    }
    void resize(size_type n)
    {
      if(n >= _size)
        return ;
      pointer new_data = _alloc.allocate(this->_capacity);
      for(size_type i = 0; i < n; i++)
      {
        _alloc.construct(new_data + i, _data[i]);
      }
      _alloc.deallocate(_data, _size);
      _data = new_data;
      _size = n;
      
    }
     size_type capacity() const
    {
      return(this->_capacity);
    } 
    bool empty() const
    {
      return(this->_size == 0);
    }
    void reserve (size_type n)
    {
       if(n <= _capacity)
        return ;
      pointer new_data = _alloc.allocate(n);
      for(size_type i = 0; i < _size; i++)
      {
        _alloc.construct(new_data + i, _data[i]);
      }
      _alloc.deallocate(_data, _size);
      _data = new_data;
      _capacity = n;

    }
  private:
    Alloc _alloc;
    pointer _data;
    size_type _size;
    size_type _capacity;
  };
}

#endif