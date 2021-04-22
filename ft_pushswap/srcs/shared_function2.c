/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_function2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 23:51:06 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/22 15:17:50 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_pushswap.h"

t_args	init_args(int chunk, int (*f)(t_stack *st, int chunk),
size_t length_st, char which_st)
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
		args.swap = "sa";
	}
	else
	{
		args.lower = "rb";
		args.upper = "rrb";
		args.push2 = "pa";
		args.swap = "sb";
	}
	return (args);
}

t_largs	init_largs(t_args rargs, int *iterchunk,
int (*comp)(int, int), char s)
{
	t_largs	args;

	args.args = rargs;
	args.iterchunk = iterchunk;
	args.comp = comp;
	args.s = s;
	return (args);
}
