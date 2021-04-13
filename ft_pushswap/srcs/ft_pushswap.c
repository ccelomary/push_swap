/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:56:13 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/13 13:45:27 by mel-omar         ###   ########.fr       */
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

int		main(int argc, char *argv[])
{
	t_stack		*stack = init_stack();

	if (!insert_numbers(&stack, argc, argv))
		get_smallest(stack);
	return (0);
}
