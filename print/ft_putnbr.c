/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:53:21 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/31 17:51:23 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static void	ft_hex(long number, char type)
{
	if (type == 'X')
		ft_cputchar(number + 55);
	else
		ft_cputchar(number + 87);
}

static void	ft_putnbr_helper(long number, int base, char type)
{
	if (number)
	{
		ft_putnbr_helper(number / base, base, type);
		if ((number % base) < 10)
			ft_cputchar((number % base) + 48);
		else
			ft_hex(number % base, type);
	}
}

void	ft_cputnbr(long number, int base, char type)
{
	if (number < 0)
	{
		ft_cputchar('-');
		number *= -1;
	}
	ft_putnbr_helper(number, base, type);
}
