/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_function5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:05:10 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/22 17:01:53 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/ft_pushswap.h"

int	get_number_position(t_stack *st, int number)
{
	size_t		pos;
	t_data		*dt;

	pos = 0;
	while (st)
	{
		dt = st->data;
		if (dt->number == number)
			return (pos);
		pos++;
		st = st->next;
	}
	return (-1);
}

int	get_last_one(t_stack *st, int chunk)
{
	t_data	*data;
	int		last_number;

	while (st)
	{
		data = st->data;
		if (data->chunk == chunk)
			last_number = data->number;
		st = st->next;
	}
	return (last_number);
}

int	get_first_one(t_stack *st, int chunk)
{
	t_data	*data;

	while (st)
	{
		data = st->data;
		if (data->chunk == chunk)
			return (data->number);
		st = st->next;
	}
	return (0);
}

void	get_number2top(t_stack **st, int number,
	const char *oper)
{
	t_data		*dt;

	dt = (*st)->data;
	while (dt->number != number)
	{
		if (isequal(oper, "ra") || isequal(oper, "rb"))
			rotate_stack_up(st);
		else
			rotate_stack_down(st);
		print("%s\n", oper);
		dt = (*st)->data;
	}
}

int	compare2pivot(t_stack *st, int pivot, int chunk, int (*compare)(int, int))
{
	t_data	*data;

	while (st)
	{
		data = st->data;
		if (data->chunk == chunk && compare(data->number, pivot))
			return (1);
		st = st->next;
	}
	return (0);
}
