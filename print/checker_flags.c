/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:18:38 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/06 18:29:58 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	check_flags(char **format, t_flags *f)
{
	while (!is_inset(**format, "dxXs"))
	{
		if (**format >= '0' && **format <= '9')
		{
			if (f->is_perc)
				f->perc = ft_atoi(format);
			else
				f->width = ft_atoi(format);
		}
		else if (**format == '.')
		{
			f->is_perc = 1;
			(*format)++;
		}
	}
	f->format = **format;
	(*format)++;
}
