/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map_method.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:18:24 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/09 15:25:47 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"

t_map			*init_map(void)
{
	int		iter;
	t_map	*map;

	iter = 0;
	map = malloc(sizeof(t_map));
	while (iter < SIZE)
	{
		map->lst[iter] = NULL;
		iter++;
	}
	return (map);
}

int				get_hash_code(const void *key, size_t key_size)
{
	int				result;
	size_t			iter;
	unsigned char	*k;

	iter = 0;
	result = 0;
	k = (unsigned char *)key;
	while (iter < key_size)
	{
		result += k[iter] * 31;
		iter++;
	}
	return (result % SIZE);
}

void			set_value(t_map *map, const void *key,
		void *value, size_t key_size)
{
	int				backet_id;
	t_key_value		*k_v;
	t_list			*list;

	backet_id = get_hash_code(key, key_size);
	if (map->lst[backet_id])
	{
		list = map->lst[backet_id];
		while (list)
		{
			if (compare(((t_key_value *)list->data)->key, key, key_size))
			{
				k_v = (t_key_value *)list->data;
				k_v->value = value;
				return ;
			}
			list = list->next;
		}
	}
	k_v = init_kv(copy_key(key, key_size), value);
	append(&map->lst[backet_id], k_v);
	return ;
}

void			*get_value(t_map *map, const void *key, size_t key_size)
{
	int		id;
	t_list	*list;

	id = get_hash_code(key, key_size);
	if (!map->lst[id])
		return (NULL);
	list = map->lst[id];
	while (list)
	{
		if (compare(((t_key_value *)list->data)->key, key, key_size))
			return (((t_key_value *)list->data)->value);
		list = list->next;
	}
	return (NULL);
}

void			clear_map(t_map **map, void free_data(void *kv))
{
	int		iter;

	iter = 0;
	if (!map)
		return ;
	while (iter < SIZE)
	{
		clear_list(&((*map)->lst[iter]), free_data);
		iter++;
	}
	free(*map);
	*map = NULL;
}
