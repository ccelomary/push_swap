/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar@student.1337.ma <mel-omar>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:04:57 by mel-omar          #+#    #+#             */
/*   Updated: 2021/03/31 17:35:21 by mel-omar@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

long	ft_catoi(char **s)
{
	long	result;
	long	sign;

	sign = 1;
	result = 0;
	if (**s == '-')
		sign = -1;
	while (**s >= '0' && **s <= '9')
	{
		result = (result * 10 + **s - 48);
		(*s)++;
	}
	return (result * sign);
}
