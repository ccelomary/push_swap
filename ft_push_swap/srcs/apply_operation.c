/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_opperation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:55:30 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/06 14:57:50 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int		insert_numbers(t_stack **stack, int argc, char *numbers[])
{
	while (--argc > 0)
	{
		if (is_number(numbers[argc]))
			push_number(stack, string2number(numbers[argc]));
		else
		{
			print_error("ERROR\n");
			return (1);
		}
	}
	return (0);
}

void	execute_operation(const char *operation, t_stack **a, t_stack **b)
{
	if (isequal(operation, "sa"))
		swap_first2(a);
	else if (isequal(operation, "sb"))
		swap_first2(b);
	else if (isequal(operation, "ss"))
		swap_a_and_b(a, b);
	else if (isequal(operation, "pa"))
		from_a2b(b, a);
	else if (isequal(operation, "pb"))
		from_a2b(a, b);
	else if (isequal(operation, "ra"))
		rotate_stack_up(a);
	else if (isequal(operation, "rb"))
		rotate_stack_up(b);
	else if (isequal(operation, "rr"))
		rotate_up_ab(a, b);
	else if (isequal(operation, "rra"))
		rotate_stack_down(a);
	else if (isequal(operation, "rrb"))
		rotate_stack_down(b);
	else if (isequal(operation, "rrr"))
		rotate_down_ab(a, b);
	else
		print("undifined operation '%s'\n", operation);
}
