/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:34:52 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/22 15:09:00 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_pushswap.h"

static int	check_stack_a(t_stack **current_st,
size_t len_st, int (*comp)(int, int))
{
	if (!len_st || is_sorted3(*current_st, comp))
		return (1);
	if (len_st <= 2)
	{
		if (!is_sorted2(*current_st, comp))
			sn(current_st, "sa");
		return (1);
	}
	if (len_st == 3)
	{
		three_numbers(current_st);
		return (1);
	}
	return (0);
}

void	quicksort(t_stack **current_st, t_stack **reverse_st,
int *iterchunk, int (*compare)(int a, int b))
{
	int		chunk;
	size_t	len_st;
	size_t	len_chunk;

	len_st = length_st(*current_st);
	if (check_stack_a(current_st, len_st, compare))
		return ;
	chunk = get_max_chunk(*current_st);
	len_chunk = count_length(*current_st);
	if (len_chunk <= 2)
	{
		initcase2(current_st, reverse_st,
			init_largs(init_args(chunk, NULL, len_st, 'a'),
				iterchunk, compare, 'a'), len_chunk);
	}
	else
	{
		pivot_part(current_st, reverse_st,
			init_largs(init_args(chunk, NULL, len_st, 'a'),
				iterchunk, compare, 'a'), number2pivot);
	}
	*iterchunk += 1;
	quicksort(current_st, reverse_st, iterchunk, check1);
	quicksort2(reverse_st, current_st, iterchunk, check2);
}
