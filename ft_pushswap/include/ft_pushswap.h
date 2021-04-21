/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:36:18 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/21 15:39:12 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H
#include "../../ft_push_swap/include/pushswap.h"
#include "../../dt/hash_table/hash_map.h"

void		quicksort(t_stack **current_st, t_stack **reverse_st, int *iterchunk, int (*compare)(int a, int b));
#endif
