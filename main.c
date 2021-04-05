/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:58:41 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/05 17:48:59 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "stack/include/stack.h"
#include "libiti/include/libiti.h"
#include "ft_push_swap/include/pushswap.h"

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			iterator;

	a = init_stack();
	b = init_stack();
	iterator = argc - 1;
	while (iterator > 0)
	{
		push_number(&a, string2number(argv[iterator]));
		iterator--;
	}
	from_a2b(&a, &b);
	from_a2b(&a, &b);
	from_a2b(&a, &b);
	print2_stack(a, b);
	from_a2b(&b, &a);
	print2_stack(a, b);
	clear_stack(&a, free);
	clear_stack(&b, free);
	while (1);
	return (0);
}
