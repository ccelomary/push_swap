/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:16:33 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/06 18:21:34 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libiti.h"

static size_t	length(const char *string)
{
	size_t	len;

	len = 0;
	while (string[len])
		len++;
	return (len);
}

char		*ft_strdup(const char *string)
{
	char	*str;
	size_t	iterator;

	if (!string)
		return (0);
	str = malloc(sizeof(char) * (length(string) + 1));
	iterator = 0;
	while (string[iterator])
	{
		str[iterator] = string[iterator];
		iterator++;
	}
	str[iterator] = 0;
	return (str);
}
