/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_method.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:31:33 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/05 15:45:24 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stack.h"

t_stack	*init_stack(void)
{
	return (NULL);
}

void	push_stack(t_stack **stack, void *data)
{
	t_stack		*temp;

	temp = malloc(sizeof(t_stack));
	temp->data = data;
	temp->next = NULL;
	if (*stack)
		temp->next = *stack;
	*stack = temp;
}

void	*pop_stack(t_stack **stack)
{
	void	*data;
	t_stack	*temp;

	if (!*stack)
		return (NULL);
	data = (*stack)->data;
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
	return (data);
}

void	*peek_stack(const t_stack *stack)
{
	if (!stack)
		return (NULL);
	return (stack->data); 
}

void	clear_stack(t_stack **stack, void (*free_value)(void *data))
{
	if (!*stack)
		return ;
	if ((*stack)->next)
		clear_stack(&(*stack)->next, free_value);
	free_value((*stack)->data);
	free(*stack);
	*stack = NULL;
}