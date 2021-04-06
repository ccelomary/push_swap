/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:15:36 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/09 15:46:38 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_MAP_H
# define HASH_MAP_H
# define SIZE 31

# include "../linkedlist/linkedlist.h"

typedef struct	s_key_value
{
	void		*key;
	void		*value;
}				t_key_value;

typedef struct	s_hash_map
{
	int			size;
	t_list		*lst[SIZE];
}				t_map;

void			*copy_key(const unsigned char *key, size_t key_size);
t_map			*init_map(void);
int				compare(const void *val1, const void *val2, size_t key_size);
t_key_value		*init_kv(void *key, void *value);
void			free_kv(void *k_v);
void			set_value(t_map *map, const void *key,
		void *value, size_t key_size);
void			*get_value(t_map *map, const void *key, size_t key_size);
t_list			*get_keys(const t_map *map);
void			clear_map(t_map **map, void free_data(void *k_v));
#endif
