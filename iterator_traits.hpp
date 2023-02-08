/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:34:15 by amiski            #+#    #+#             */
/*   Updated: 2023/02/08 01:00:17 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP
#include <iostream>
#include <iterator>
#include <cstddef>
#include "iterator.hpp"

namespace ft
{

    template<typename T>
    class iterator_traits   //< iterator <T> >
    {
        public:
            typedef typename T::iterator_category      iterator_category;
            typedef  T                                   value_type;
            typedef typename T::reference                                reference;
            typedef  typename T::pointer                                  pointer;
            typedef typename  T::difference_type                      difference_type;  
    };
}
#endif