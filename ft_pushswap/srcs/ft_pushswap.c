/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:56:13 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/21 01:10:50 by mel-omar         ###   ########.fr       */
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

int			get_max_chunk(t_stack *st)
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

size_t		count_length(t_stack *st)
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

size_t		length_st(t_stack *st)
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

int		get_number_position(t_stack *st, int number)
{
	size_t 		pos;
	t_data		*dt;

	pos = 0;
	while (st)
	{
		dt = st->data;
		if (dt->number == number)
			return (pos);
		st = st->next;
	}
	return (-1);
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

int		is_followed(t_stack *st, int  chunk)
{
	t_data  *dt;

	dt = st->data;
	if (dt->chunk == ((t_data *)st->next->data)->chunk && dt->chunk == chunk)
		return (1);
	return (0);
}

int		is_sorted2(t_stack *st,  int (*compare)(int a, int b))
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

int			get_last_one(t_stack *st, int chunk)
{
	t_data	*data;
	int		last_number;

	while (st)
	{
		data = st->data;
		if (data->chunk == chunk)
			last_number = data->number;
		st = st->next;
	}
	return (last_number);
}

int			get_first_one(t_stack *st, int chunk)
{
	t_data	*data;

	while (st)
	{
		data = st->data;
		if (data->chunk == chunk)
			return (data->number);
		st = st->next;
	}
	return (0);
}

void		get_number2top(t_stack **st, int number, const char *oper, int *iterchunk)
{
	t_data *dt;

	dt = (*st)->data;
	while (dt->number != number)
	{
		if (isequal(oper, "ra") || isequal(oper, "rb"))
			rotate_stack_up(st);
		else
			rotate_stack_down(st);
		print("%s\n", oper);
		dt = (*st)->data;
	}
	dt->chunk = *iterchunk;
	(*st)->data = dt;
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

int			compare2pivot(t_stack *st, int pivot, int chunk, int (*compare)(int, int))
{
	t_data	*data;

	while (st)
	{
		data = st->data;
		if (data->chunk == chunk && compare(data->number, pivot))
			return (1);
		st = st->next;
	}
	return (0);
}

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
void		quicksort(t_stack **current_st, t_stack **reverse_st, int *iterchunk, int (*compare)(int a, int b));
void		quicksort2(t_stack **current_st, t_stack **reverse_st, int *iterchunk, int (*compare)(int a, int b))
{
	int		chunk;
	int		pivot;
	int		last_number;
	int		position;
	t_data	*dt;
	size_t	len_st;
	size_t	len_chunk;

	len_st = length_st(*current_st);
	if (!len_st)
		return ;
	chunk = get_max_chunk(*current_st);
	len_chunk = count_length(*current_st);
	if (len_chunk <= 2)
	{
		if (len_chunk == 2)
		{
			if (is_followed(*current_st, chunk))
			{
				if (!is_sorted2(*current_st, compare))
				{
					print("sb\n");
					swap_first2(current_st);
				}
				print("pa\npa\n");
				update_data(current_st, iterchunk);
				from_a2b(current_st, reverse_st);
				update_data(current_st, iterchunk);
				from_a2b(current_st, reverse_st);
			}
			else
			{
				if (!is_sorted2(*current_st, compare))
				{
					last_number = get_last_one(*current_st, chunk);
					position = get_number_position(*current_st, last_number);
					if (position > (len_st / 2))
						get_number2top(current_st, last_number, "rrb", iterchunk);
					else
						get_number2top(current_st, last_number, "rb", iterchunk);
					print("pa\n");
					from_a2b(current_st, reverse_st);
					last_number = get_last_one(*current_st, chunk);
					position = get_number_position(*current_st, last_number);
					if (position > (len_st / 2))
						get_number2top(current_st, last_number, "rrb", iterchunk);
					else
						get_number2top(current_st, last_number, "rb", iterchunk);
					print("pa\n");
					from_a2b(current_st, reverse_st);
				}
				else
				{
					last_number = get_first_one(*current_st, chunk);
					position = get_number_position(*current_st, last_number);
					if (position > (len_st / 2))
						get_number2top(current_st, last_number, "rrb", iterchunk);
					else
						get_number2top(current_st, last_number, "rb", iterchunk);
					print("pa\n");
					from_a2b(current_st, reverse_st);
					last_number = get_last_one(*current_st, chunk);
					position = get_number_position(*current_st, last_number);
					if (position > (len_st / 2))
						get_number2top(current_st, last_number, "rrb", iterchunk);
					else
						get_number2top(current_st, last_number, "rb", iterchunk);
					print("pa\n");
					from_a2b(current_st, reverse_st);
				}
			}
		}
		else
		{
			last_number = get_last_one(*current_st, chunk);
			position = get_number_position(*current_st, last_number);
			if (position > (len_st / 2))
				get_number2top(current_st, last_number, "rrb", iterchunk);
			else
				get_number2top(current_st, last_number, "rb", iterchunk);
			print("pa\n");
			from_a2b(current_st, reverse_st);
		}
	}
	else
	{
		pivot = pick_pivot(*current_st);
		while (compare2pivot(*current_st, pivot, chunk, compare))
		{
			last_number = number2pivot(*current_st, pivot, chunk, compare);
			position = get_number_position(*current_st, last_number);
			if (position > (len_st / 2))
				get_number2top(current_st, last_number, "rrb", iterchunk);
			else
				get_number2top(current_st, last_number, "rb", iterchunk);
			print("pa\n");
			from_a2b(current_st, reverse_st);
		}
	}
	*iterchunk += 1;
	quicksort(reverse_st, current_st, iterchunk, check1);
	quicksort2(current_st, reverse_st, iterchunk, check2);
}

void		quicksort(t_stack **current_st, t_stack **reverse_st, int *iterchunk, int (*compare)(int a, int b))
{
	int		chunk;
	int		pivot;
	int		last_number;
	int		position;
	t_data	*dt;
	size_t	len_st;
	size_t	len_chunk;

	len_st = length_st(*current_st);
	if (!len_st || is_sorted3(*current_st, compare))
		return ;
	if (len_st <= 2)
	{
		if (!is_sorted2(*current_st, compare))
		{
			print("sa\n");
			swap_first2(current_st);
		}
		return ;
	}
	chunk = get_max_chunk(*current_st);
	len_chunk = count_length(*current_st);
	if (len_chunk <= 2)
	{
		if (len_chunk == 2)
		{
			if (is_followed(*current_st, chunk))
			{
				if (!is_sorted2(*current_st, compare))
				{
					print("sa\n");
					swap_first2(current_st);
				}
				update_data(current_st, iterchunk);
				print("pb\n");
				from_a2b(current_st, reverse_st);
				update_data(current_st, iterchunk);
				print("pb\n");
				from_a2b(current_st, reverse_st);
			}
			else
			{
				if (!is_sorted2(*current_st, compare))
				{
					last_number = get_last_one(*current_st, chunk);
					position = get_number_position(*current_st, last_number);
					if (position > (len_st / 2))
						get_number2top(current_st, last_number, "rra", iterchunk);
					else
						get_number2top(current_st, last_number, "ra", iterchunk);
					print("pb\n");
					from_a2b(current_st, reverse_st);
					last_number = get_last_one(*current_st, chunk);
					position = get_number_position(*current_st, last_number);
					if (position > (len_st / 2))
						get_number2top(current_st, last_number, "rra", iterchunk);
					else
						get_number2top(current_st, last_number, "ra", iterchunk);
					print("pb\n");
					from_a2b(current_st, reverse_st);
				}
				else
				{
					last_number = get_first_one(*current_st, chunk);
					position = get_number_position(*current_st, last_number);
					if (position > (len_st / 2))
						get_number2top(current_st, last_number, "rra", iterchunk);
					else
						get_number2top(current_st, last_number, "ra", iterchunk);
					from_a2b(current_st, reverse_st);
					last_number = get_last_one(*current_st, chunk);
					position = get_number_position(*current_st, last_number);
					if (position > (len_st / 2))
						get_number2top(current_st, last_number, "rra", iterchunk);
					else
						get_number2top(current_st, last_number, "ra", iterchunk);
					print("pb\n");
					from_a2b(current_st, reverse_st);
				}
			}
		}
		else
		{
			last_number = get_last_one(*current_st, chunk);
			position = get_number_position(*current_st, last_number);
			if (position > (len_st / 2))
				get_number2top(current_st, last_number, "rra", iterchunk);
			else
				get_number2top(current_st, last_number, "ra", iterchunk);
			print("pb\n");
			from_a2b(current_st, reverse_st);
		}
	}
	else
	{
		pivot = pick_pivot(*current_st);
		while (compare2pivot(*current_st, pivot, chunk, compare))
		{
			last_number = number2pivot(*current_st, pivot, chunk, compare);
			position = get_number_position(*current_st, last_number);
			if (position > (len_st / 2))
				get_number2top(current_st, last_number, "rra", iterchunk);
			else
				get_number2top(current_st, last_number, "ra", iterchunk);
			print("pb\n");
			from_a2b(current_st, reverse_st);
		}
	}
	*iterchunk += 1;
	quicksort(current_st, reverse_st, iterchunk, check1);
	quicksort2(reverse_st, current_st, iterchunk, check2);
}

int		main(int argc, char *argv[])
{
	t_stack		*a = init_stack();
	t_stack		*b = init_stack();
	int			chun = 1;
	insert_numbers(&a, argc, argv);
	quicksort(&a, &b, &chun, check1);
	//print2_stack(a, b);
	return (0);
}
