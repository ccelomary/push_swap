/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_stack2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:47:30 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/05 15:55:22 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"


void		swap_a_and_b(t_stack **a, t_stack **b)
{
	swap_first2(a);
	swap_first2(b);
}

void		rotate_up_ab(t_stack **a, t_stack **b)
{
	rotate_stack_up(a);
	rotate_stack_up(b);
}

void		rotate_down_ab(t_stack **a, t_stack **b)
{
	rotate_stack_down(a);
	rotate_stack_down(b);
}
