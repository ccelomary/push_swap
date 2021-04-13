/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string2number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:10:24 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/13 13:30:25 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isdigits(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			string2number(const char *string)
{
	long int	number;
	int			sign;

	number = 0;
	sign = 1;
	if (!string)
		return (0);
	else if (*string == '-')
	{
		sign  = -1;
		string++;
	}
	else if (*string == '+')
		string++;
	while (isdigits(*string))
	{
		number = (number * 10) + (int)(*string - 48);
		string++;
	}
	return (sign * number);
}