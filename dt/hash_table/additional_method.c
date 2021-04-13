/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_method.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:29:31 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/13 12:48:03 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_map.h"

int				compare(const void *val1, const void *val2, size_t key_size)
{
	size_t			iter;
	unsigned char	*v1;
	unsigned char	*v2;

	v1 = (unsigned char *)val1;
	v2 = (unsigned char *)val2;
	iter = 0;
	while (iter < key_size && v1[iter] == v2[iter])
		iter++;
	if (v1[iter] != v2[iter])
		return (0);
	return (1);
}

t_key_value		*init_kv(void *key, void *value)
{
	t_key_value		*k_v;

	k_v = malloc(sizeof(t_key_value));
	k_v->key = key;
	k_v->value = value;
	return (k_v);
}
