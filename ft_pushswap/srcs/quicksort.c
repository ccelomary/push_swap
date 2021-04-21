/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:34:52 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/21 17:30:52 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_pushswap.h"

typedef struct s_args
{
	int			chunk;
	int			(*f)(t_stack *st, int chunk);
	size_t		len_st;
	char		*lower;
	char		*upper;
	char		*push2;
}				t_args;

typedef struct s_largs
{
	t_args		*args;
	int			*iterchunk;
	int			chunk;
	int			(*comp)(int, int);
}				t_largs;

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

t_args		init_args(int chunk, int (*f)(t_stack *st, int chunk), size_t length_st, char which_st)
{
	t_args		args;

	args.chunk = chunk;
	args.f = f;
	args.len_st = length_st;
	if (which_st == 'a')
	{
		args.lower = "ra";
		args.upper = "rra";
		args.push2 = "pb";
	}
	else
	{
		args.lower = "rb";
		args.upper = "rrb";
		args.push2 = "pa"
	}
	return (args);
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
	pn(current_st, reverse_st, args.push2, iterchunk);
}


void		init_largs(t_args args, int iterchunk, int (*comp)(int, int))
void		initcase2(t_largs)
{
	t_largs	args;

	args.args = args;
	args.iterchunk = iterchunk;
	args.comp = comp;
}

void		quicksort(t_stack **current_st, t_stack **reverse_st, int *iterchunk, int (*compare)(int a, int b))
{
	int		chunk;
	int		pivot;
	int		last_number;
	int		position;
	t_data	*dt;
	size_t	len_st;
	size_t	len_chunk;

	len_st = length_st(*current_st);
	if (!len_st || is_sorted3(*current_st, compare))
		return ;
	if (len_st <= 2)
	{
		if (!is_sorted2(*current_st, compare))
			sn(current_st, "sa");
		return ;
	}
	if (len_st == 3)
	{
		three_numbers(current_st);
		return ;
	}
	chunk = get_max_chunk(*current_st);
	len_chunk = count_length(*current_st);
	if (len_chunk <= 2)
	{
		if (len_chunk == 2)
		{
			if (is_followed(*current_st, chunk))
			{
				if (!is_sorted2(*current_st, compare))
					sn(current_st, "sa");
				pn(current_st, reverse_st, "pb", iterchunk);
				pn(current_st, reverse_st, "pb", iterchunk);
			}
			else
			{
				if (!is_sorted2(*current_st, compare))
					push_selectednumber(current_st, reverse_st, iterchunk, init_args(chunk, get_last_one, len_st, 'a'));
				else
					push_selectednumber(current_st, reverse_st, iterchunk, init_args(chunk, get_first_one, len_st, 'a'));
			}
		}
		push_selectednumber(current_st, reverse_st, iterchunk, init_args(chunk, get_last_one, len_st, 'a'));
	}
	else
	{
		pivot = pick_pivot(*current_st);
		while (compare2pivot(*current_st, pivot, chunk, compare))
		{
			last_number = number2pivot(*current_st, pivot, chunk, compare);
			position = get_number_position(*current_st, last_number);
			if (position > (len_st / 2))
				get_number2top(current_st, last_number, "rra", iterchunk);
			else
				get_number2top(current_st, last_number, "ra", iterchunk);
			pn(current_st, reverse_st, "pb", iterchunk);
		}
	}
	*iterchunk += 1;
	quicksort(current_st, reverse_st, iterchunk, check1);
	quicksort2(reverse_st, current_st, iterchunk, check2);
}