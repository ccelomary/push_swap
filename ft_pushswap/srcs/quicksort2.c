/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:18:31 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/22 00:19:12 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_pushswap.h"

void		quicksort2(t_stack **current_st, t_stack **reverse_st, int *iterchunk, int (*compare)(int a, int b))
{
	int		chunk;
	int		pivot;
	int		last_number;
	int		position;
	t_data	*dt;
	size_t	len_st;
	size_t	len_chunk;

	len_st = length_st(*current_st);
	if (!len_st)
		return ;
	chunk = get_max_chunk(*current_st);
	len_chunk = count_length(*current_st);
	if (len_chunk <= 2)
	{
		if (len_chunk == 2)
		{
			if (is_followed(*current_st, chunk))
			{
				if (!is_sorted2(*current_st, compare))
				{
					print("sb\n");
					swap_first2(current_st);
				}
				print("pa\npa\n");
				update_data(current_st, iterchunk);
				from_a2b(current_st, reverse_st);
				update_data(current_st, iterchunk);
				from_a2b(current_st, reverse_st);
			}
			else
			{
				if (!is_sorted2(*current_st, compare))
				{
					last_number = get_last_one(*current_st, chunk);
					position = get_number_position(*current_st, last_number);
					if (position > (len_st / 2))
						get_number2top(current_st, last_number, "rrb", iterchunk);
					else
						get_number2top(current_st, last_number, "rb", iterchunk);
					print("pa\n");
					from_a2b(current_st, reverse_st);
					last_number = get_last_one(*current_st, chunk);
					position = get_number_position(*current_st, last_number);
					if (position > (len_st / 2))
						get_number2top(current_st, last_number, "rrb", iterchunk);
					else
						get_number2top(current_st, last_number, "rb", iterchunk);
					print("pa\n");
					from_a2b(current_st, reverse_st);
				}
				else
				{
					last_number = get_first_one(*current_st, chunk);
					position = get_number_position(*current_st, last_number);
					if (position > (len_st / 2))
						get_number2top(current_st, last_number, "rrb", iterchunk);
					else
						get_number2top(current_st, last_number, "rb", iterchunk);
					print("pa\n");
					from_a2b(current_st, reverse_st);
					last_number = get_last_one(*current_st, chunk);
					position = get_number_position(*current_st, last_number);
					if (position > (len_st / 2))
						get_number2top(current_st, last_number, "rrb", iterchunk);
					else
						get_number2top(current_st, last_number, "rb", iterchunk);
					print("pa\n");
					from_a2b(current_st, reverse_st);
				}
			}
		}
		else
		{
			last_number = get_last_one(*current_st, chunk);
			position = get_number_position(*current_st, last_number);
			if (position > (len_st / 2))
				get_number2top(current_st, last_number, "rrb", iterchunk);
			else
				get_number2top(current_st, last_number, "rb", iterchunk);
			print("pa\n");
			from_a2b(current_st, reverse_st);
		}
	}
	else
	{
		pivot = pick_pivot(*current_st);
		while (compare2pivot(*current_st, pivot, chunk, compare))
		{
			last_number = number2pivot(*current_st, pivot, chunk, compare);
			position = get_number_position(*current_st, last_number);
			if (position > (len_st / 2))
				get_number2top(current_st, last_number, "rrb", iterchunk);
			else
				get_number2top(current_st, last_number, "rb", iterchunk);
			print("pa\n");
			from_a2b(current_st, reverse_st);
		}
	}
	*iterchunk += 1;
	quicksort(reverse_st, current_st, iterchunk, check1);
	quicksort2(current_st, reverse_st, iterchunk, check2);
}