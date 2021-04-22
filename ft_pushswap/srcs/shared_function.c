/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 21:19:46 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/22 02:07:20 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_pushswap.h"

void		sn(t_stack **st, const char *oper)
{
	print("%s\n", oper);
	swap_first2(st);
}

void		pn(t_stack **a, t_stack **b, const char *oper, int *iterchunk)
{
	print("%s\n", oper);
	update_data(a, iterchunk);
	from_a2b(a, b);
}

void		push_selectednumber(t_stack **current_st, t_stack **reversed_st, int *iterchunk, t_args	args)
{
	int		number;
	int		position;

	number = args.f(*current_st, args.chunk);
	position = get_number_position(*current_st, number);
	if (position > (args.len_st / 2))
		get_number2top(current_st, number, args.upper, iterchunk);
	else
		get_number2top(current_st, number, args.lower, iterchunk);
	pn(current_st, reversed_st, args.push2, iterchunk);
}

void		initcase2(t_stack **current_st, t_stack **reverse_st, t_largs args, size_t len_chunk)
{
		if (len_chunk == 2)
		{
			if (is_followed(*current_st, args.args.chunk))
			{
				if (!is_sorted2(*current_st, args.comp))
					sn(current_st, args.args.swap);
				//print2_stack(*current_st, *reverse_st);
				pn(current_st, reverse_st, args.args.push2, args.iterchunk);
				pn(current_st, reverse_st, args.args.push2, args.iterchunk);
				return ;
			}
			else
			{
				if (!is_sorted2(*current_st, args.comp))
					push_selectednumber(current_st, reverse_st, args.iterchunk,
					init_args(args.args.chunk, get_last_one, args.args.len_st, args.s));
				else
					push_selectednumber(current_st, reverse_st, args.iterchunk,
					init_args(args.args.chunk, get_first_one, args.args.len_st, args.s));
			}
		}
		push_selectednumber(current_st, reverse_st, args.iterchunk,
		init_args(args.args.chunk, get_last_one, args.args.len_st, args.s));
}

void		pivot_part(t_stack **current_st, t_stack **reverse_st, t_largs args,
int (*get_numberpvt)(t_stack *st, int pivot, int chunk, int (*compare)(int , int)))
{
	int		pivot;
	int		number;
	int		position;

	pivot = pick_pivot(*current_st);
	while (compare2pivot(*current_st, pivot, args.args.chunk, args.comp))
	{
			number = get_numberpvt(*current_st, pivot, args.args.chunk, args.comp);
			position = get_number_position(*current_st, number);
			if (position > (args.args.len_st / 2))
				get_number2top(current_st, number, args.args.upper, args.iterchunk);
			else
				get_number2top(current_st, number, args.args.lower, args.iterchunk);
			pn(current_st, reverse_st, args.args.push2, args.iterchunk);
	}
}
