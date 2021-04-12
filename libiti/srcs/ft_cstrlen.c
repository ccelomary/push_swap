/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:39:13 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/12 14:42:15 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libiti.h"

size_t 	ft_cstrlen(const char *str)
{
	size_t		len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}
