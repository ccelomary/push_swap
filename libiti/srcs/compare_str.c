/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:44:36 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/22 15:45:54 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isequal(const char *s1, const char *s2)
{
	unsigned int	iterator;

	iterator = 0;
	while (s1[iterator] && s2[iterator])
	{
		if (s1[iterator] != s2[iterator])
			return (0);
		iterator++;
	}
	if (s1[iterator] || s2[iterator])
		return (0);
	return (1);
}
