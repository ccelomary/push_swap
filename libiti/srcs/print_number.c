/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:48:18 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/05 16:23:55 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libiti.h"

static void	print_number_helper(long num)
{
	char	c;

	if (num)
	{
		print_number_helper(num / 10);
		c = (char)((num % 10) + 48);
		write(1, &c, sizeof(char));
	}
}
void		print_number(int number)
{
	long	num;

	num = number;
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if (!num)
		write(1, "0", 1);
	else
		print_number_helper(num);
}