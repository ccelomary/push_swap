/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_function7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:16:39 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/22 15:24:18 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_pushswap.h"

static void	swapandrotateup(t_stack **current_st)
{
	print("sa\nra\n");
	swap_first2(current_st);
	rotate_stack_up(current_st);
}

static void	swapandrotatedown(t_stack **current_st)
{
	print("sa\nrra\n");
	swap_first2(current_st);
	rotate_stack_down(current_st);
}

static void	swap(t_stack **st)
{
	print("sa\n");
	swap_first2(st);
}

static int	*intobuffer(t_stack *current_stack)
{
	int		*buffer;
	size_t	len;

	len = count_length(current_stack);
	buffer = malloc(sizeof(int) * len);
	copy2buffer(buffer, current_stack);
	return (buffer);
}

void	three_numbers(t_stack **current_st)
{
	int			*buf;

	buf = intobuffer(*current_st);
	if (buf[0] < buf[1] && buf[1] < buf[2])
	{
		free(buf);
		return ;
	}
	else if (buf[0] < buf[1] && buf[2] > buf[0])
		swapandrotateup(current_st);
	else if (buf[0] > buf[1] && buf[0] < buf[2])
		swap(current_st);
	else if (buf[0] < buf[1] && buf[1] > buf[2])
	{
		print("rra\n");
		rotate_stack_down(current_st);
	}
	else if (buf[0] > buf[1] && buf[1] < buf[2])
	{
		print("ra\n");
		rotate_stack_up(current_st);
	}
	else if (buf[0] > buf[1] && buf[1] > buf[2])
		swapandrotatedown(current_st);
	free(buf);
}
