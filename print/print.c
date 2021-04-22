/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:56:22 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/31 17:51:37 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	print(char *format, ...)
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
			ft_cputchar(*format);
			format++;
		}
	}
	return (g_len);
}
