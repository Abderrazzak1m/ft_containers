/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:16:24 by amiski            #+#    #+#             */
/*   Updated: 2023/02/01 16:10:10 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
    //enable if
    template <bool B, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if<true, T> { typedef T type; };
    

    //is integral type

    template <class T> 
    struct is_integral
    {
        
    };
    
}