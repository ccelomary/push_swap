/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:41:32 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/06 14:47:16 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libiti.h"

void		print_error(const char *error_str)
{
	if (error_str)
	{
		while (*error_str)
		{
			write(2, error_str, sizeof(char));
			error_str++;
		}
	}
}