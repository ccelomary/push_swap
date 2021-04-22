/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:55:30 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/22 16:28:22 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

static void	free_dt(void *kv)
{
	t_key_value		*key_value;

	key_value = (t_key_value *)kv;
	free(key_value->key);
	free(key_value);
}

void	error_printer(t_map **map, void (*free_dt)(void *dt))
{
	clear_map(map, free_dt);
	print_error("ERROR\n");
}

int	verify_numbers(t_map **map, char *strnumber, t_stack **stack)
{
	long	number;

	set_value(*map, strnumber, "", ft_cstrlen(strnumber));
	number = string2number(strnumber);
	if (ft_cstrlen(strnumber) > 11 || number > 2147483647
		|| number < -2147483648)
	{
		error_printer(map, free_dt);
		return (1);
	}
	push_number(stack, number);
	return (0);
}

int	insert_numbers(t_stack **stack, int argc, char *numbers[])
{
	t_map	*repeated;

	repeated = init_map();
	while (--argc > 0)
	{
		if (is_number(numbers[argc])
			&& !get_value(repeated, numbers[argc], ft_cstrlen(numbers[argc])))
		{
			if (verify_numbers(&repeated, numbers[argc], stack))
				return (1);
		}
		else
		{
			error_printer(&repeated, free_dt);
			return (1);
		}
	}
	clear_map(&repeated, free_dt);
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
		print_error("undifined operator\n");
}
