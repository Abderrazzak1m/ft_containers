/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:41:43 by amiski            #+#    #+#             */
/*   Updated: 2023/02/14 02:49:39 by amiski           ###   ########.fr       */
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


    /************ Member functions *******/
    explicit vector(const allocator_type &alloc = allocator_type())
        : allocater(alloc), vdata(NULL), vsize(0), vcapacity(0)
    {
    }
    explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
        : allocater(alloc)
    {
      vcapacity = (n > 0) ? n : 1;
      this->vdata = allocater.allocate(vcapacity);
      this->vsize = n;
      for (size_type i = 0; i < n; i++)
        this->allocater.construct(vdata + i, val);
    }
    template <class InputIterator>
    vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) : allocater(alloc)
    {
      this->vsize = last - first;
      int i = 0;
      this->vcapacity = last - first;
      this->vdata = this->allocater.allocate(this->vcapacity);
      while (first != (last))
      {
        this->allocater.construct(this->vdata + i, *first);
        i++;
        first++;
      }
    }
    vector(const vector &x)
    {
      *this = x;
    }
    ~vector(){};
    vector &operator=(const vector &x)
    {

      this->vdata = x.vdata;
      this->vsize = x.vsize;
      this->vcapacity = x.vcapacity;
      this->allocater = x.allocater;

      return (*this);
    };

    /************ iterator **************/
    
    iterator begin()
    {
      return (this->vdata);
    }
    iterator end()
    {
      return (this->vdata + this->size());
    }
    reverse_iterator rbegin()
    {
      return reverse_iterator(this->end() - 1);
    }
    reverse_iterator rend()
    {
      return reverse_iterator(this->begin() - 1);
    }
    
    /************ Capacity **************/
    
    size_type size() const
    {
      return (this->vsize);
    }
    size_type maxsize() const
    {
      return (this->vsize);
    }
    void resize(size_type n)
    {
      if (n >= vsize)
        return;
      pointer newvdata = allocater.allocate(this->vcapacity);
      for (size_type i = 0; i < n; i++)
      {
        allocater.construct(newvdata + i, vdata[i]);
      }
      allocater.deallocate(vdata, vsize);
      vdata = newvdata;
      vsize = n;
    }
    size_type capacity() const
    {
      return (this->vcapacity);
    }
    bool empty() const
    {
      return (this->vsize == 0);
    }
    void reserve(size_type n)
    {
      if (n <= vcapacity)
        return;
      pointer newvdata = allocater.allocate(n);
      for (size_type i = 0; i < vsize; i++)
      {
        allocater.construct(newvdata + i, vdata[i]);
      }
      allocater.deallocate(vdata, vsize);
      vdata = newvdata;
      vcapacity = n;
    }

    /************ Modifiers *************/

    void assign(size_type n, const value_type &val)
    {
      this->vsize = n;
      allocater.deallocate(vdata, this->vcapacity);
      if (n > this->vcapacity)
        this->vcapacity = n;
      pointer tmp = allocater.allocate(this->vcapacity);
      for (size_type i = 0; i < n; i++)
      {
        allocater.construct(tmp + i, val);
      }
      this->vdata = tmp;
    }
    template <class InputIterator>
    void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
    {
      this->vsize = last - first;
      int i = 0;
      allocater.deallocate(vdata, this->vcapacity);
      if (this->vsize > this->vcapacity)
        this->vcapacity = this->vsize;
      pointer tmp = allocater.allocate(this->vcapacity);
      while (first != last)
      {
        allocater.construct(tmp + i, *first);
        first++;
        i++;
      }
      this->vdata = tmp;
    }
    void push_back(const value_type &val)
    {
      if (vsize == vcapacity && vcapacity == 0)
      {
        vcapacity++;
        vdata = allocater.allocate(1);
        allocater.construct(vdata, val);
      }
      else if (vsize == vcapacity)
      {
        this->reserve(vcapacity * 2);
        allocater.construct(vdata + vsize, val);
      }
      else
        allocater.construct(vdata + vsize, val);
      vsize++;
    }
    void pop_back()
    {
      allocater.destroy(vdata + vsize);
      vsize--;
    }
    iterator insert(iterator position, const value_type &val)
    {
      iterator it = this->begin();
      int i = 0;
      pointer tmp = allocater.allocate(this->vcapacity + 1);
      while (it != position)
      {
        allocater.construct(tmp + i, *it);
        it++;
        i++;
      }
      allocater.construct(tmp + i, val);
      i++;
      while (it != this->end())
      {
        allocater.construct(tmp + i, *it);
        i++;
        it++;
      }
      allocater.deallocate(vdata, this->vcapacity);
      vdata = tmp;
      this->vsize++;
      return (position);
    }
    void insert(iterator position, size_type n, const value_type &val)
    {
      size_type i = 0;
      iterator it = position;
      vector tmp(this->begin(), position);
      tmp.reserve(this->capacity() + n);
      while (i < n)
      {
        tmp.push_back(val);
        i++;
      }
      while (position != this->end())
      {
        tmp.push_back(*position);
        position++;
      }
      // tmp->vsize = this->vsize + n;
      *this = tmp;
    }
    template <class InputIterator>
    void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
    {
      iterator it = begin();
      difference_type n = this->vcapacity;
      size_type i = 0;
      if (this->capacity() < this->size() + (last - first))
        n += (last - first);
      vsize += (last - first);
      pointer tmp = allocater.allocate(n);
      while (it != position)
        allocater.construct(tmp + i++, *it++);
      while (first != last)
        allocater.construct(tmp + i++, *first++);
      while (position != end())
        allocater.construct(tmp + i++, *position++);
      allocater.deallocate(vdata, vcapacity);
      vdata = tmp;
      vcapacity = n;
    }
    iterator erase(iterator position)
    {
      iterator it = position;
      while (it != end())
      {
        *it = *(it + 1);
        it++;
      }
      allocater.destroy(vdata + vsize);
      vsize--;
      return (position);
    }
    iterator erase(iterator first, iterator last)
    {
      difference_type n = last - first;
      iterator tmp = first;
      while (last != end())
      {
        *(tmp) = *last;
        tmp++;
        last++;
      }
      for (size_type i = vsize - n; i != vsize; ++i)
      {
        allocater.destroy(vdata + i);
      }
      vsize -= n;
      return (first);
    }
    void swap(vector &x)
    {
      vector tmp(*this);
      *this = x;
      x = tmp;
    }
    void clear()
    {
      while (vsize)
      {
        pop_back();
        vsize--;
      }
    }

    /************ Element access ********/
    
    reference operator[] (size_type n)
    {
      return(*(begin()+ n));
    }
    const_reference operator[] (size_type n) const
    {
      return(*(begin() + n));
    }
    
  private:
    Alloc allocater;
    pointer vdata;
    size_type vsize;
    size_type vcapacity;
  };
}

#endif