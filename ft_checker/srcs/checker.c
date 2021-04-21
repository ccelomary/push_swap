/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:05:07 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/21 16:19:07 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		*operation;

	a = init_stack();
	b = init_stack();
	if (argc > 1 && !insert_numbers(&a, argc, argv))
	{
		while (1)
		{
			operation = readline(0);
			if (!operation)
				break ;
			execute_operation(operation, &a, &b);
			print2_stack(a, b);
			free(operation);
		}
		if (is_sorted(a) && !b)
			print("OK\n");
		else
			print("KO\n");
	}
	clear_stack(&a, free);
	clear_stack(&b, free);
	return (0);
}
