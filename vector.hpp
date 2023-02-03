/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:41:43 by amiski            #+#    #+#             */
/*   Updated: 2023/02/03 05:18:19 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator_traits.hpp"
#include <type_traits>
#include "utils.hpp"

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
        std::cout << *(this->_data) << std::endl;
      std::cout << *(this->_data + 1) << std::endl;
      std::cout << *(this->_data  + 2) << std::endl;
      std::cout << *(this->_data + 3) << std::endl;
      std::cout << *(this->_data + 4) << std::endl;
    }
   //TODOO  // rang vector
    template <class InputIterator>
    ft_vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
    {
      (void)alloc;
      this->_size = last - first;
      int i = 0;
      this->_capacity = last - first;
      this->_data = this->_alloc.allocate(this->_capacity);
      while(first != (last))
      {
        this->_alloc.construct(this->_data + i, *first);
        i++;
        first++;
      }
      std::cout << *(this->_data) << std::endl;
      std::cout << *(this->_data + 1) << std::endl;
      std::cout << *(this->_data  + 2) << std::endl;
      std::cout << *(this->_data + 3) << std::endl;
      std::cout << *(this->_data + 4) << std::endl;
    }

    
  private:
    Alloc _alloc;
    pointer _data;
    size_type _size;
    size_type _capacity;
  };
}
