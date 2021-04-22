/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_function3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 23:55:30 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/22 15:18:39 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_pushswap.h"

int	get_max_chunk(t_stack *st)
{
	t_data		*dt;
	int			max_;

	if (!st)
		return (-1);
	dt = st->data;
	max_ = dt->chunk;
	while (st)
	{
		dt = st->data;
		if (dt->chunk > max_)
			max_ = dt->chunk;
		st = st->next;
	}
	return (max_);
}

size_t	count_length(t_stack *st)
{
	size_t	len;
	t_data	*data;
	int		chunk;

	chunk = get_max_chunk(st);
	if (chunk == -1)
		return (0);
	len = 0;
	while (st)
	{
		data = st->data;
		if (data->chunk == chunk)
			len++;
		st = st->next;
	}
	return (len);
}

void	copy2buffer(int *buffer, t_stack *st)
{
	unsigned int	iter;
	t_data			*dt;
	int				chunk;

	iter = 0;
	chunk = get_max_chunk(st);
	while (st)
	{
		dt = st->data;
		if (dt->chunk == chunk)
		{
			buffer[iter] = dt->number;
			iter++;
		}
		st = st->next;
	}
}

void	sort_buffer(int *buffer, size_t len)
{
	int				tmp;
	unsigned int	iter1;
	unsigned int	iter2;

	if (!len)
		return ;
	iter1 = 0;
	while (iter1 < len - 1)
	{
		iter2 = iter1 + 1;
		while (iter2 < len)
		{
			if (buffer[iter1] < buffer[iter2])
			{
				tmp = buffer[iter1];
				buffer[iter1] = buffer[iter2];
				buffer[iter2] = tmp;
			}
			iter2++;
		}
		iter1++;
	}
}

int	pick_pivot(t_stack *st)
{
	size_t	len;
	int		*buffer;
	int		pivot;

	len = count_length(st);
	buffer = malloc(sizeof(int) * len);
	copy2buffer(buffer, st);
	sort_buffer(buffer, len);
	pivot = buffer[len / 2];
	free(buffer);
	return (pivot);
}
