/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:56:13 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/13 17:44:01 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_pushswap.h"
#include <stdio.h>

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

size_t		count_length(t_stack *start, t_stack *end)
{
	size_t	len;

	len = 0;
	while (start != end)
	{
		start = start->next;
		len++;
	}
	return (len);
}

/*
int		pick_pivot(t_stack *start, t_stack *end)
{
	int	number;
}
*/

int		main(int argc, char *argv[])
{
	t_stack		*stack = init_stack();

	insert_numbers(&stack, argc, argv);
	printf("%lu\n", count_length(stack, stack->next->next->next));
	return (0);
}
