/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_method.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:37:32 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/09 15:02:44 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

void	append(t_list **list, void *data)
{
	t_list	*temp;
	t_list	*before;

	temp = malloc(sizeof(t_list));
	temp->data = data;
	temp->next = NULL;
	if (!(*list))
		*list = temp;
	else
	{
		before = *list;
		while (before->next)
			before = before->next;
		before->next = temp;
	}
}

void	*pop(t_list **list)
{
	void	*data;
	t_list	*before;
	t_list	*temp;

	data = NULL;
	if (!(*list))
		return (data);
	if (!((*list)->next))
		data = free_node(list);
	else
	{
		before = (*list)->next;
		temp = *list;
		while (before->next)
		{
			temp = before;
			before = before->next;
		}
		temp->next = NULL;
		data = free_node(&before);
	}
	return (data);
}

void	iterate_list(const t_list *list, void func(void *data))
{
	t_list	*temp;

	temp = (t_list *)list;
	while (temp)
	{
		func(temp->data);
		temp = temp->next;
	}
}

void	clear_list(t_list **list, void free_data(void *data))
{
	if (!*list)
		return ;
	if ((*list)->next)
		clear_list(&((*list)->next), free_data);
	free_data((*list)->data);
	free(*list);
	*list = NULL;
}

size_t	length(const t_list *list)
{
	size_t	len;
	t_list	*lst;

	lst = (t_list *)list;
	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
