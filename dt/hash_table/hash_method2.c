/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_method2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:17:26 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/09 15:28:18 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"

t_list		*get_keys(const t_map *map)
{
	t_list			*list;
	t_list			*lst;
	int				iter;
	unsigned char	*key;

	iter = 0;
	list = NULL;
	while (iter < SIZE)
	{
		lst = map->lst[iter];
		while (lst)
		{
			key = ((t_key_value *)lst->data)->key;
			append(&list, key);
			lst = lst->next;
		}
		iter++;
	}
	return (list);
}

void		*copy_key(const unsigned char *key, size_t key_size)
{
	size_t			iter;
	unsigned char	*dst;

	iter = 0;
	dst = malloc(key_size + 1);
	while (iter < key_size)
	{
		dst[iter] = key[iter];
		iter++;
	}
	dst[iter] = 0;
	return (dst);
}
