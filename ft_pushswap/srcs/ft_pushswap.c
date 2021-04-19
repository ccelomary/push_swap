/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:56:13 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/19 16:45:36 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_pushswap.h"
#include <stdio.h>
#include <time.h>

void	quicksort(t_stack **stack, t_stack **reverse_stack, int (*check_pivot)(int a, int b), int *chun);
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

size_t		count_length(t_stack *st)
{
	size_t	len;
	t_data	*data;
	int		current_chunk;
	int		chunk;

	len = 0;
	if (!st)
		return (0);
	data = st->data;
	current_chunk = data->chunk;
	chunk = current_chunk;
	while (current_chunk == chunk)
	{
		len++;
		st = st->next;
		if (!st)
			break ;
		data = st->data;
		chunk = data->chunk;
	}
	return (len);
}


void	copy2buffer(int *buffer, t_stack *st)
{
	unsigned int	iter;
	t_data			*dt;
	int				current_chunk;
	int				chunk;

	iter = 0;
	dt = st->data;
	current_chunk =  dt->chunk;
	chunk = dt->chunk;
	while (current_chunk == chunk)
	{
		buffer[iter] = dt->number;
		st = st->next;
		if (!st)
			break ;
		dt = st->data;
		chunk = dt->chunk;
		iter++;
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

int		pick_pivot(t_stack *st)
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

t_stack	*the_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int		check_greater(t_stack *stack, int pivot, int (*check)(int , int))
{
	t_data	*dt;

	while (stack)
	{
		dt = stack->data;
		if (check(dt->number, pivot))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int		check1(int a, int b)
{
	return (a < b);
}

int		check2(int a, int b)
{
	return (b < a);
}

static	int get_number(t_data *dt)
{
	return (dt->number);
}

int		is_sorted2(t_stack *st,  int (*compare)(int a, int b))
{
	int		data;
	t_data	*dt;
	int		current_chunk;
	int 	chunk;

	data = get_number(st->data);
	dt = st->data;
	current_chunk = dt->chunk;
	st = st->next;
	while (st)
	{
		dt = st->data;
		chunk = dt->chunk;
		if (chunk != current_chunk)
			break ;
		if (!compare(data, get_number(st->data)))
			return (0);
		data =  get_number(st->data);
		st = st->next;
	}
	return (1);
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

void	quicksort2(t_stack **stack, t_stack **reverse_stack, int (*check_pivot)(int a, int b), int *chun)
{
	int		pivot;
	t_data	*data;
	size_t	len;
	int		current_chunk;
	int		chunk;

	if (!*stack)
		return ;
	if (is_sorted2(*stack, check_pivot))
	{
		data = (*stack)->data;
		current_chunk = data->chunk;
		chunk = current_chunk;
		while (chunk == current_chunk)
		{
			data->chunk = *chun;
			(*stack)->data = data;
			from_a2b(stack, reverse_stack);
			if (!*stack)
				break;
			data = (*stack)->data;
			chunk = data->chunk;
		}
		(*chun)++;
		print2_stack(*reverse_stack, *stack);
		printchunks(*reverse_stack, *stack);
		//quicksort2(stack, reverse_stack, check_pivot, chun);
		return ;
	}
	len = count_length(*stack);
	if (len == 2)
		swap_first2(stack);
	if (len <= 2)
	{
		data = (*stack)->data;
		current_chunk = data->chunk;
		chunk = current_chunk;
		while (chunk == current_chunk)
		{
			data->chunk = *chun;
			(*stack)->data = data;
			from_a2b(stack, reverse_stack);
			if (!*stack)
				break;
			data = (*stack)->data;
			chunk = data->chunk;
		}
		(*chun)++;
		//quicksort2(stack, reverse_stack, check_pivot, chun);
		return ;
	}
	pivot = pick_pivot(*stack);
	printf("2pivot --> %d\n", pivot);
	data = (*stack)->data;
	current_chunk = data->chunk;
	chunk = current_chunk;
	while (current_chunk == chunk && !check_greater(*stack, pivot, check2))
	{
		if (check_pivot(data->number, pivot))
		{
			data = (*stack)->data;
			data->chunk = *chun;
			(*stack)->data = data;
			from_a2b(stack, reverse_stack);
		}
		else
			rotate_stack_up(stack);
		data = (*stack)->data;
		chunk = data->chunk;
	}
	(*chun)++;
	print2_stack(*stack, *reverse_stack);
	quicksort(reverse_stack, stack, check1,  chun);
	quicksort2(stack, reverse_stack, check2,  chun);
}

void	quicksort(t_stack **stack, t_stack **reverse_stack, int (*check_pivot)(int a, int b), int *chun)
{
	int		pivot;
	t_data	*data;
	size_t	len;
	int		current_chunk;
	int		chunk;

	if (is_sorted3(*stack, check_pivot))
		return ;
	len = count_length(*stack);
	if (len == 2 && !is_sorted2(*stack, check_pivot))
		swap_first2(stack);
	if (len <= 2)
		return ;
	pivot = pick_pivot(*stack);
	printf("pivot --> %d\n", pivot);
	data = (*stack)->data;
	current_chunk = data->chunk;
	chunk = current_chunk;
	while (current_chunk == chunk && !check_greater(*stack, pivot, check1))
	{
		if (check_pivot(data->number, pivot))
		{
			data = (*stack)->data;
			data->chunk = *chun;
			(*stack)->data = data;
			from_a2b(stack, reverse_stack);
		}
		else
			rotate_stack_up(stack);
		data = (*stack)->data;
		chunk = data->chunk;
	}
	(*chun)++;
	print2_stack(*stack, *reverse_stack);
	printchunks(*stack, *reverse_stack);
	quicksort(stack, reverse_stack, check1, chun);
	quicksort2(reverse_stack, stack, check2, chun);
}

int		main(int argc, char *argv[])
{
	t_stack		*a = init_stack();
	t_stack		*b = init_stack();
	int			chun = 1;
	insert_numbers(&a, argc, argv);
	print2_stack(a, b);
	quicksort(&a, &b, check1, &chun);
	
	printf("last\n");
	print2_stack(a, b);
	printf("%d\n", chun);
	return (0);
}
