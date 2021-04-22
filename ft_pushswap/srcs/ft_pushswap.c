/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:56:13 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/22 15:28:36 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_pushswap.h"

int	check_chunk_existance(t_stack *st, int chunk)
{
	t_data	*dt;

	while (st)
	{
		dt = st->data;
		if (dt->chunk == chunk)
			return (1);
		st = st->next;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	int			chunk;

	a = init_stack();
	b = init_stack();
	chunk = 1;
	insert_numbers(&a, argc, argv);
	quicksort(&a, &b, &chunk, check1);
	return (0);
}
