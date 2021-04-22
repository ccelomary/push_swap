/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:43:43 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/22 15:56:36 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/readline.h"

static char	getchar(int fd)
{
	char	c;

	read(fd, &c, 1);
	return (c);
}

char	*readline(int fd)
{
	char		*line;
	char		c;

	line = NULL;
	c = getchar(fd);
	while (c != '\n')
	{
		if (c == 0)
		{
			free(line);
			return (NULL);
		}
		line = strjoinchar(line, c);
		c = getchar(fd);
	}
	return (line);
}
