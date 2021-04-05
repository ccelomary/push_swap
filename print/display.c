/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:40:48 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/07 18:14:04 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	ft_putchar(char c)
{
	g_len++;
	write(1, &c, 1);
}

void	ft_putstr(char *s, long len)
{
	long	iter;

	iter = 0;
	while (iter < len && s[iter] != '\0')
	{
		ft_putchar(s[iter]);
		iter++;
	}
}

void	ft_repeat_char(char c, int repeat)
{
	while (--repeat >= 0)
		ft_putchar(c);
}

void	display_with_perc(t_flags *f, long length, char *sign)
{
	if (f->format == 's')
	{
		if (f->perc >= 0)
			ft_repeat_char(' ', length - f->perc);
	}
	else
	{
		if (*sign == '-')
		{
			ft_putchar('-');
			*sign = '+';
		}
		if (f->perc >= length)
			ft_repeat_char('0', f->perc - length);
	}
}
