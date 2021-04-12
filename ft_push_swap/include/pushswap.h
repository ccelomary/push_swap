/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 13:05:01 by mel-omar          #+#    #+#             */
/*   Updated: 2021/04/12 14:34:30 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "../../stack/include/stack.h"
#include "../../dt/hash_table/hash_map.h"
# include "../../libiti/include/libiti.h"
# include "../../print/print.h"

void		printer_data(void *data);
void		print2_stack(const t_stack *a, const t_stack *b);
void		swap_first2(t_stack **stack);
void		rotate_stack_up(t_stack **stack);
void		rotate_stack_down(t_stack **stack);
void		push_number(t_stack **stack, int number);
void		from_a2b(t_stack **a, t_stack **b);
void		swap_a_and_b(t_stack **a, t_stack **b);
void		rotate_up_ab(t_stack **a, t_stack **b);
void		rotate_down_ab(t_stack **a, t_stack **b);
int			is_sorted(t_stack *st);
int			insert_numbers(t_stack **stack, int argc, char *numbers[]);
void		execute_operation(const char *operation, t_stack **a, t_stack **b);

#endif