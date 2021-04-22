/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:01:27 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/12 15:43:26 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	display_number(int number, t_flags *f, char sign)
{
	if (number == 0 && !f->is_perc)
		ft_cputchar('0');
	if (sign == '-')
		ft_cputchar('-');
	ft_cputnbr(number, 10, 'd');
}

void	display_hex(unsigned int hex, t_flags *f)
{
	if (hex == 0 && !f->is_perc)
		ft_cputchar('0');
	ft_cputnbr(hex, 16, f->format);
}
