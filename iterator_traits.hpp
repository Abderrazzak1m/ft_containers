/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:34:15 by amiski            #+#    #+#             */
/*   Updated: 2023/02/05 19:54:22 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
            typedef typename std::random_access_iterator_tag      iterator_category;
            typedef  T                                   value_type;
            typedef  T&                                  Reference;
            typedef  T*                                  Pointer;
            typedef typename  std::ptrdiff_t                      difference_type;  
    };
}