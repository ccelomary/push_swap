/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:09:09 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/06 18:32:01 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_pushswap.h"


void	set_operation(t_map *map, t_operations oper, const char *value)
{
	set_value(map, &oper, value, sizeof(t_operations));
}

t_map	*init_operations(void)
{
	t_map	*operations;

	operations = init_map();
	set_operation(operations, SA, "sa");
	set_operation(operations, SB, 'sb');
	set_operation(operations, SS, "ss");
	set_operation(operations, PA, "pa");
	set_operation(operations, PB, "pb");
	set_operation(operations, RA, "ra");
	set_operation(operations, RB, "rb");
	set_operation(operations, RR, "rr");
	set_operation(operations, RRA, "rra");
	set_operation(operations, RRB, "rrb");
	set_operation(operations, RRR, "RRR");
	return (operations);
}

char	*get_operation(t_map *map, t_operations oper)
{
	return get_value(map, &oper, sizeof(t_operations));
}