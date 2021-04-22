/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:56:13 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/22 02:06:59 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_pushswap.h"

int			check_chunk_existance(t_stack *st, int chunk)
{
	t_data 	*dt;

	while (st)
	{
		dt = st->data;
		if (dt->chunk == chunk)
			return (1);
		st = st->next;
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	t_stack		*a = init_stack();
	t_stack		*b = init_stack();
	int			chun = 1;
	insert_numbers(&a, argc, argv);
	quicksort(&a, &b, &chun, check1);
	//print2_stack(a, b);
	//printchunks(a, b);
	//printf("is sorted %d\n", is_sorted(a));
	return (0);
}
