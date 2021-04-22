/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_function7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 00:16:39 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/22 00:17:25 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_pushswap.h"

void		three_numbers(t_stack **current_st)
{
	size_t		len;
	int			*buffer;

	len = count_length(*current_st);
	buffer = malloc(sizeof(int) * len);
	copy2buffer(buffer, *current_st);
	if (buffer[0] < buffer[1] && buffer[1] < buffer[2])
	{
		free(buffer);
		return ;
	}
	else if (buffer[0] < buffer[1] && buffer[2] > buffer[0])
	{
		print("sa\nra\n");
		swap_first2(current_st);
		rotate_stack_up(current_st);
	}
	else if (buffer[0] > buffer[1] && buffer[0] < buffer[2])
	{
		print("sa\n");
		swap_first2(current_st);
	}
	else if (buffer[0] < buffer[1] && buffer[1] > buffer[2])
	{
		print("rra\n");
		rotate_stack_down(current_st);
	}
	else if (buffer[0] > buffer[1] && buffer[1] < buffer[2])
	{
		print("ra\n");
		rotate_stack_up(current_st);
	}
	else if (buffer[0] > buffer[1] && buffer[1] > buffer[2])
	{
		print("sa\nrra\n");
		swap_first2(current_st);
		rotate_stack_down(current_st);
	}
	free(buffer);
}