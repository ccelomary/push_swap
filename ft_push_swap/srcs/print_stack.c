/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 13:07:47 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/05 17:43:19 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

static void	print_both(int *da, int *db)
{
	print("%.08d  %.08d\n", *da, *db);
}

static void	print_left(int *da)
{
	print("%.8d  %8s\n", *da, "");
}

static void	print_right(int *db)
{
	print("%8s  %.08d\n", "", *db);
}
static void	print_bottom(void)
{
	print("----      ----\n");
	print("%2s        %2s\n", "a", "b");
}

void		print2_stack(const t_stack *a, const t_stack *b)
{
	t_stack		*temp;
	void (*printer)(int *dt);

	while (a && b)
	{
		print_both(a->data, b->data);
		a = a->next;
		b = b->next;
	}
	if (!a)
	{
		temp = (t_stack *)b;
		printer = print_right;
	}
	else
	{
		temp = (t_stack *)a;
		printer  = print_left;
	}
	while (temp)
	{
		printer(temp->data);
		temp = temp->next;
	}
	print_bottom();
}