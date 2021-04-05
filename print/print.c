/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:56:22 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/07 15:18:09 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include <stdio.h>

int		print(char *format, ...)
{
	va_list		ap;
	t_flags		flag;

	g_len = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			init_flags(&flag);
			check_flags(&format, &flag);
			apply_flags(&flag, &ap);
		}
		else
		{
			ft_putchar(*format);
			format++;
		}
	}
	return (g_len);
}
