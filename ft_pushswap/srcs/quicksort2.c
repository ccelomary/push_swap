/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:18:31 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/22 01:49:36 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_pushswap.h"

void		quicksort2(t_stack **current_st, t_stack **reverse_st, int *iterchunk, int (*compare)(int a, int b))
{
	int		chunk;
	size_t	len_st;
	size_t	len_chunk;

	len_st = length_st(*current_st);
	if (!len_st)
		return ;
	chunk = get_max_chunk(*current_st);
	len_chunk = count_length(*current_st);
	if (len_chunk <= 2)
	{
		initcase2(current_st, reverse_st,
		init_largs(init_args(chunk, NULL, len_st, 'b'),
		iterchunk, compare, 'b'), len_chunk);
	}
	else
	{
		pivot_part(current_st, reverse_st,
		init_largs(init_args(chunk, NULL, len_st, 'b'),
		iterchunk, compare, 'b'), number2pivot);
	}
	*iterchunk += 1;
	quicksort(reverse_st, current_st, iterchunk, check1);
	quicksort2(current_st, reverse_st, iterchunk, check2);
}