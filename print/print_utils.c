/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:34:25 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/07 16:34:15 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

long	lenstr(char *s)
{
	long	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

long	len_num(long num, int base)
{
	long	len;

	len = 0;
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	while (num)
	{
		len++;
		num /= base;
	}
	return (len);
}

void	init_flags(t_flags *f)
{
	f->width = 0;
	f->is_perc = 0;
	f->perc = -1;
}

int		is_inset(char c, char *s)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}
