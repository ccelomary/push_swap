/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:36:18 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/06 18:31:52 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H
#include "../../ft_push_swap/include/pushswap.h"
#include "../../dt/hash_table/hash_map.h"
typedef enum e_operations
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}		t_operations;

t_map	*init_operations(void);
char	*get_operation(t_map *map, t_operations oper);
#endif
