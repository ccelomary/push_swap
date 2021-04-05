/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:01:27 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/07 18:12:27 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	display_number(int number, t_flags *f, char sign)
{
	if (number == 0 && !f->is_perc)
		ft_putchar('0');
	if (sign == '-')
		ft_putchar('-');
	ft_putnbr(number, 10, 'd');
}

void	display_hex(unsigned int hex, t_flags *f)
{
	if (hex == 0 && !f->is_perc)
		ft_putchar('0');
	ft_putnbr(hex, 16, f->format);
}
