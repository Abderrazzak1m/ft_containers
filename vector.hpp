/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:41:43 by amiski            #+#    #+#             */
/*   Updated: 2023/02/01 16:14:48 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator_traits.hpp"

namespace ft
{
  template <typename T, typename Alloc = std::allocator<T> >
  class ft_vector
  {
  public:
    typedef T value_type;
    typedef Alloc allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef typename ft::ft_iterator<const value_type> iterator;
    // typedef typename const iterator const_iterator;
    // typedef typename ft::ft_iterator_traits<iterator>::difference_type difference_type;
    typedef typename std::size_t                                        size_type;

    // default constructor
    explicit ft_vector(const allocator_type &alloc = allocator_type())
      :_alloc(alloc)
    {
      return ;
    }
    // fill constructor
    explicit ft_vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
        : _alloc(alloc)
    {
      _capacity = (n > 0) ? n: 1;
      this->_data = _alloc.allocate(_capacity);
      this->_size = n;
      for(size_type i = 0; i < n; i++)
        this->_alloc.construct(_data + i, val);
    }
    template <class InputIterator>
    vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
    { 
    }

    
  private:
    Alloc _alloc;
    pointer _data;
    size_type _size;
    size_type _capacity;
  };
}
