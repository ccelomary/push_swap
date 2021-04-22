/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:36:18 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/22 17:02:13 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H
# include "../../ft_push_swap/include/pushswap.h"
# include "../../dt/hash_table/hash_map.h"

typedef struct s_args
{
	int			chunk;
	int			(*f)(t_stack *st, int chunk);
	size_t		len_st;
	char		*lower;
	char		*upper;
	char		*push2;
	char		*swap;
}				t_args;

typedef struct s_largs
{
	t_args		args;
	int			*iterchunk;
	int			chunk;
	int			(*comp)(int, int);
	char		s;
}				t_largs;

int			check1(int a, int b);
int			check2(int a, int b);
int			is_followed(t_stack *st, int chunk);
int			is_sorted2(t_stack *st, int (*compare)(int a, int b));
size_t		length_st(t_stack *st);
int			get_max_chunk(t_stack *st);
int			get_number_position(t_stack *st, int number);
int			get_last_one(t_stack *st, int chunk);
int			get_first_one(t_stack *st, int chunk);
int			number2pivot(t_stack *st, int pivot,
				int chunk, int (*compare)(int, int));
void		update_data(t_stack **st, int *iterchunk);
void		get_number2top(t_stack **st, int number,
				const char *oper);
int			compare2pivot(t_stack *st, int pivot, int chunk,
				int (*compare)(int, int));
size_t		count_length(t_stack *st);
void		copy2buffer(int *buffer, t_stack *st);
void		sort_buffer(int *buffer, size_t len);
int			pick_pivot(t_stack *st);
void		sn(t_stack **st, const char *oper);
int			is_sorted3(t_stack *st, int (*compare)(int, int));
void		three_numbers(t_stack **current_st);
void		pn(t_stack **a, t_stack **b, const char *oper, int *iterchunk);
t_args		init_args(int chunk, int (*f)(t_stack *st, int chunk),
				size_t length_st, char which_st);
t_largs		init_largs(t_args rargs, int *iterchunk,
				int (*comp)(int, int), char s);
void		push_selectednumber(t_stack **current_st,
				t_stack **reversed_st, int *iterchunk, t_args	args);
void		initcase2(t_stack **current_st,
				t_stack **reverse_st, t_largs args, size_t len_chunk);
void		pivot_part(t_stack **current_st, t_stack **reverse_st,
				t_largs args, int (*get_number)(t_stack *st,
					int pivot, int chunk, int (*compare)(int a, int b)));
void		quicksort(t_stack **current_st, t_stack **reverse_st,
				int *iterchunk, int (*compare)(int a, int b));
void		quicksort2(t_stack **current_st, t_stack **reverse_st,
				int *iterchunk, int (*compare)(int a, int b));
#endif
