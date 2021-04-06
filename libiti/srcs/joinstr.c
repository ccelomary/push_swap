/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joinstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:52:01 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/06 12:06:44 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libiti.h"

static size_t	lenstr(const char *line)
{
	size_t		length;

	if (!line)
			return (0);
	length = 0;
	while (line[length])
		length++;
	return (length);
}

static char	*strcpy(char *dest, const char *srcs)
{
	unsigned int		iter;

	iter = 0;
	if (!srcs)
		return (NULL);
	while (srcs[iter])
	{
		dest[iter] = srcs[iter];
		iter++;
	}
	return (dest);
}

char	*strjoinchar(char *line, char c)
{
	char		*jline;
	size_t		len;

	len = lenstr(line);
	jline = malloc(sizeof(char) * (len + 2));
	strcpy(jline, line);
	jline[len] = c;
	jline[len + 1] = 0;
	free(line);
	return (jline);
}