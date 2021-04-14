/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:56:13 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/14 16:35:07 by mel-omar         ###   ########.fr       */
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

size_t		count_length(t_stack *start, t_stack *end)
{
	size_t	len;

	len = 0;
	if (!start)
		return (0);
	while (start != end)
	{
		start = start->next;
		len++;
	}
	return (len);
}


void	copy2buffer(int *buffer, t_stack *start, t_stack *end)
{
	unsigned int	iter;

	iter = 0;
	while (start != end)
	{
		buffer[iter] = *((int *)start->data);
		start = start->next;
		iter++;
	}
}

void	sort_buffer(int *buffer, size_t len)
{
	int	tmp;
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

int		pick_pivot(t_stack *start, t_stack *end)
{
	size_t	len;
	int		*buffer;
	int		pivot;

	len = count_length(start, end);
	buffer = malloc(sizeof(int) * len);
	copy2buffer(buffer, start, end);
	sort_buffer(buffer, len);
	pivot = buffer[len / 2];
	free(buffer);
	return (pivot);
}

t_stack	*the_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	quicksort(t_stack **stack, t_stack *start, t_stack *end, t_stack **reverse_stack, char st)
{
	int		pivot;
	void	*data;
	void	*sd;
	void	*ed;
	size_t	len;

	data = start->data;
	pivot = pick_pivot(start, end);
	while ((*stack)->data != data)
		rotate_stack_up(stack);
	data = end->data;
	while ((*stack)->data != data)
	{
		printf("%p %p\n", (*stack)->data, data);
		if (*((int *)(*stack)->data) < pivot)
		{
			start = (*stack)->data;
			from_a2b(stack, reverse_stack);
		}
		else
			rotate_stack_up(stack);
		sleep(1);
	}
	end = (*stack)->data;
	if (*((int *)data) < pivot)
		from_a2b(stack, reverse_stack);
}

int		main(int argc, char *argv[])
{
	t_stack		*a = init_stack();
	t_stack		*b = init_stack();	
	insert_numbers(&a, argc, argv);
	quicksort(&a, a, the_last(a), &b);
	return (0);
}
