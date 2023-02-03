/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:16:24 by amiski            #+#    #+#             */
/*   Updated: 2023/02/03 07:34:05 by amiski           ###   ########.fr       */
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
        static const bool value = false;
    };

    template <>
    struct is_integral<bool>
    {
        static const bool value = true;
    };
    