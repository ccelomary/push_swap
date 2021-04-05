/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:30:28 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/07 18:38:53 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

char	is_negative(int *number)
{
	if (*number < 0)
	{
		*number *= -1;
		return ('-');
	}
	return ('+');
}

void	get_str_data(char **str, long *len, va_list *ap)
{
	*str = va_arg(*ap, char *);
	*str = (!*str) ? "(null)" : *str;
	*len = lenstr(*str);
}

char	get_number_data(int *number, long *length, va_list *ap, t_flags *f)
{
	char	sign;

	*number = va_arg(*ap, int);
	sign = is_negative(number);
	*length = len_num(*number, 10) + ((!*number && !f->is_perc) ? 1 : 0);
	return (sign);
}

void	get_hex_data(unsigned int *hex, long *length, va_list *ap, t_flags *f)
{
	*hex = va_arg(*ap, unsigned int);
	*length = len_num(*hex, 16) + ((!*hex && !f->is_perc) ? 1 : 0);
}

void	apply_flags(t_flags *f, va_list *ap)
{
	char			*str;
	int				number;
	unsigned int	hex;
	long			length;
	char			sign;

	if (f->format == 's')
		get_str_data(&str, &length, ap);
	else if (f->format == 'd')
		sign = get_number_data(&number, &length, ap, f);
	else
		get_hex_data(&hex, &length, ap, f);
	if (f->width > 0)
	{
		ft_repeat_char(' ', f->width - ((length > f->perc) ? length : f->perc)
				- ((sign == '-') ? 1 : 0));
	}
	if (f->is_perc)
		display_with_perc(f, length, &sign);
	if (f->format == 's')
		ft_putstr(str, ((f->perc >= 0) ? f->perc : length));
	else if (f->format == 'd')
		display_number(number, f, sign);
	else
		display_hex(hex, f);
}
