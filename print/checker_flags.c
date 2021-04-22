/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:18:38 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/12 15:39:18 by mel-omar         ###   ########.fr       */
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
				f->perc = ft_catoi(format);
			else
				f->width = ft_catoi(format);
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
