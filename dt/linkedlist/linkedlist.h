/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:36:38 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/09 15:24:05 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include <stdlib.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

void				*free_node(t_list **list);
void				append(t_list **list, void *data);
void				*pop(t_list **list);
void				iterate_list(const t_list *list, void func(void *data));
void				clear_list(t_list **list, void free_data(void *));
size_t				length(const t_list *lst);
#endif
