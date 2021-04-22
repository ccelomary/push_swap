/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_function6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:11:33 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/22 00:13:22 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_pushswap.h"

int			number2pivot(t_stack *st, int pivot, int chunk, int (*compare)(int, int))
{
	t_data	*dt;

	while (st)
	{
		dt = st->data;
		if (dt->chunk == chunk && compare(dt->number, pivot))
			return (dt->number);
		st = st->next;
	}
	return (0);
}

void		update_data(t_stack **st, int *iterchunk)
{
	t_data	*data;

	data = (*st)->data;
	data->chunk = *iterchunk;
	(*st)->data = data;
}

static int get_number(t_data *dt)
{
	return (dt->number);
}

int		is_sorted3(t_stack *st, int (*compare)(int, int))
{
	int		data;

	if(!st)
		return (1);
	data = get_number(st->data);
	st = st->next;
	while (st)
	{
		if (!compare(data, get_number(st->data)))
			return (0);
		data = get_number(st->data);
		st = st->next;
	}
	return (1);
}
