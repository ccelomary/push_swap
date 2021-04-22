/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:34:33 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/06 13:11:03 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int			width;
	int			perc;
	int			is_perc;
	char		format;
}				t_flags;

size_t			g_len;

long			tcondition (int condition, int a, int b);
void			ft_cputchar(char c);
void			ft_cputstr(char *s, long len);
void			ft_repeat_char(char c, int repeat);
void			ft_cputnbr(long number, int base, char type);
long			ft_catoi(char **s);
long			lenstr(char *s);
long			len_num(long num, int base);
void			init_flags(t_flags *f);
int				is_inset(char c, char *s);
void			display_number(int number, t_flags *f, char sign);
void			display_hex(unsigned int hex, t_flags *f);
void			display_with_perc(t_flags *f, long length, char *sign);
void			check_flags(char **format, t_flags *f);
void			apply_flags(t_flags *f, va_list *ap);
int				print(char *format, ...);
#endif
