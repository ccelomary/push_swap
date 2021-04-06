/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:31:47 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/06 11:40:18 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libiti.h"

int			is_number(const char *number)
{
	while (*number)
	{
		if (!isdigits(*number))
			return (0);
		number++;
	}
	return (1);
}
