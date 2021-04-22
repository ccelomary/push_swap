/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libiti.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:47:29 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/22 16:07:09 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBITI_H
# define LIBITI_H
# include <unistd.h>
# include <stdlib.h>

void		print_number(int number);
long		string2number(const char *string);
int			isequal(const char *s1, const char *s2);
int			isdigits(char c);
int			is_number(const char *number);
void		print_error(const char *error_str);
char		*strjoinchar(char *line, char c);
char		*ft_strdup(const char *string);
size_t		ft_cstrlen(const char *str);
#endif