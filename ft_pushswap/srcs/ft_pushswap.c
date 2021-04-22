/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:56:13 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/22 00:19:07 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_pushswap.h"
#include <stdio.h>
#include <time.h>

int	*get_smallest(t_stack *stack)
{
	int	*peeked;
	int	*current;

	peeked = peek_stack(stack);
	current = NULL;
	stack = stack->next;
	while (stack)
	{
		current = stack->data;
		if (*current < *peeked)
			peeked = current;
		stack = stack->next;
	}
	return (peeked);
}

t_stack	*the_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	printchunks(t_stack *a, t_stack *b)
{
	t_data	*dt;

	printf("A\n");
	while (a)
	{
		dt = a->data;
		printf("number %d --> chunk %d\n", dt->number, dt->chunk);
		a = a->next;
	}
	printf("B\n");
	while (b)
	{
		dt = b->data;
		printf("number %d --> chunk %d\n", dt->number, dt->chunk);
		b = b->next;
	}
}

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
