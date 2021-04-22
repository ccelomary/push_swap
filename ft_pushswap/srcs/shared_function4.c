/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_function4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:01:48 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/22 15:20:51 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_pushswap.h"

int	check1(int a, int b)
{
	return (a < b);
}

int	check2(int a, int b)
{
	return (b < a);
}

int	is_followed(t_stack *st, int chunk)
{
	t_data	*dt;

	dt = st->data;
	if (dt->chunk == ((t_data *)st->next->data)->chunk && dt->chunk == chunk)
		return (1);
	return (0);
}

int	is_sorted2(t_stack *st, int (*compare)(int a, int b))
{
	int		previous_number;
	t_data	*data;
	int		chunk;
	int		found_first;

	chunk = get_max_chunk(st);
	found_first = 0;
	while (st)
	{
		data = st->data;
		if (data->chunk == chunk)
		{
			if (found_first && !compare(previous_number, data->number))
				return (0);
			found_first = 1;
			previous_number = data->number;
		}
		st = st->next;
	}
	return (1);
}

size_t	length_st(t_stack *st)
{
	size_t	len;

	len = 0;
	while (st)
	{
		st = st->next;
		len++;
	}
	return (len);
}
