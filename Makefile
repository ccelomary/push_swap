# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-omar <mel-omar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/06 15:06:22 by mel-omar          #+#    #+#              #
#    Updated: 2021/04/22 17:04:43 by mel-omar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap checker
CHECKER = checker
PUSHSWAP = push_swap

SRCS_CHECKER = stack/srcs/ft_main_method.c ft_push_swap/srcs/print_stack.c \
				libiti/srcs/print_number.c  libiti/srcs/string2number.c  \
				print/apply_flags.c print/checker_flags.c print/display.c \
				dt/linkedlist/linkedlist_method.c dt/linkedlist/linkedlist_method2.c \
				dt/hash_table/additional_method.c dt/hash_table/hash_map_method.c \
				print/ft_atoi.c print/ft_putnbr.c print/print.c print/print_utils.c \
				dt/hash_table/hash_method2.c print/display_flags.c ft_push_swap/srcs/is_sorted_stack.c \
				ft_push_swap/srcs/operation_stack2.c libiti/srcs/compare_str.c \
				print/additional_funcn.c ft_push_swap/srcs/operation_stack.c libiti/srcs/is_number.c readline/srcs/readline.c \
				libiti/srcs/joinstr.c libiti/srcs/ft_cstrlen.c libiti/srcs/print_errors.c ft_push_swap/srcs/apply_operation.c \
				ft_checker/srcs/checker.c

SRCS_PUSHSWAP = stack/srcs/ft_main_method.c ft_push_swap/srcs/print_stack.c \
				libiti/srcs/print_number.c  libiti/srcs/string2number.c  \
				print/apply_flags.c print/checker_flags.c print/display.c \
				dt/linkedlist/linkedlist_method.c dt/linkedlist/linkedlist_method2.c \
				dt/hash_table/additional_method.c dt/hash_table/hash_map_method.c \
				print/ft_atoi.c print/ft_putnbr.c print/print.c print/print_utils.c \
				dt/hash_table/hash_method2.c print/display_flags.c ft_push_swap/srcs/is_sorted_stack.c \
				ft_push_swap/srcs/operation_stack2.c libiti/srcs/compare_str.c \
				print/additional_funcn.c \
				ft_push_swap/srcs/operation_stack.c libiti/srcs/is_number.c \
				libiti/srcs/joinstr.c libiti/srcs/ft_cstrlen.c libiti/srcs/print_errors.c ft_push_swap/srcs/apply_operation.c \
				ft_pushswap/srcs/ft_pushswap.c ft_pushswap/srcs/shared_function.c ft_pushswap/srcs/shared_function2.c \
				ft_pushswap/srcs/shared_function3.c ft_pushswap/srcs/shared_function4.c \
				ft_pushswap/srcs/shared_function5.c ft_pushswap/srcs/shared_function6.c \
				ft_pushswap/srcs/shared_function7.c ft_pushswap/srcs/quicksort.c \
				ft_pushswap/srcs/quicksort2.c 

OBJECTS_PUSHSWAP = stack/srcs/ft_main_method.o ft_push_swap/srcs/print_stack.o \
				libiti/srcs/print_number.o  libiti/srcs/string2number.o  \
				print/apply_flags.o print/checker_flags.o print/display.o \
				dt/linkedlist/linkedlist_method.o dt/linkedlist/linkedlist_method2.o \
				dt/hash_table/additional_method.o dt/hash_table/hash_map_method.o \
				print/ft_atoi.o print/ft_putnbr.o print/print.o print/print_utils.o \
				dt/hash_table/hash_method2.o print/display_flags.o ft_push_swap/srcs/is_sorted_stack.o \
				ft_push_swap/srcs/operation_stack2.o libiti/srcs/compare_str.o \
				print/additional_funcn.o \
				ft_push_swap/srcs/operation_stack.o libiti/srcs/is_number.o \
				libiti/srcs/joinstr.o libiti/srcs/ft_cstrlen.o libiti/srcs/print_errors.o ft_push_swap/srcs/apply_operation.o \
				ft_pushswap/srcs/ft_pushswap.o ft_pushswap/srcs/shared_function.o ft_pushswap/srcs/shared_function2.o \
				ft_pushswap/srcs/shared_function3.o ft_pushswap/srcs/shared_function4.o \
				ft_pushswap/srcs/shared_function5.o ft_pushswap/srcs/shared_function6.o \
				ft_pushswap/srcs/shared_function7.o ft_pushswap/srcs/quicksort.o \
				ft_pushswap/srcs/quicksort2.o 

OBJECTS_CHECKER = stack/srcs/ft_main_method.o ft_push_swap/srcs/print_stack.o \
				libiti/srcs/print_number.o libiti/srcs/string2number.o  \
				print/apply_flags.o print/checker_flags.o print/display.o \
				dt/linkedlist/linkedlist_method.o dt/linkedlist/linkedlist_method2.o \
				print/additional_funcn.o dt/hash_table/hash_method2.o \
				dt/hash_table/additional_method.o dt/hash_table/hash_map_method.o \
				print/ft_atoi.o print/ft_putnbr.o print/print.o print/print_utils.o \
				libiti/srcs/ft_cstrlen.o print/display_flags.o ft_push_swap/srcs/is_sorted_stack.o \
				ft_push_swap/srcs/operation_stack2.o libiti/srcs/compare_str.o \
				ft_push_swap/srcs/operation_stack.o libiti/srcs/is_number.o readline/srcs/readline.o \
				libiti/srcs/joinstr.o libiti/srcs/print_errors.o ft_push_swap/srcs/apply_operation.o \
				ft_checker/srcs/checker.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(CHECKER):
	@gcc $(FLAGS) $(SRCS_CHECKER) -o $(CHECKER)
	@rm -rf $(OBJECTS_CHECKER)

$(PUSHSWAP):
	@gcc $(FLAGS) $(SRCS_PUSHSWAP) -o $(PUSHSWAP)
	@rm -rf $(OBJECTS_PUSHSWAP)
clean:
	@rm -rf $(OBJECTS_CHECKER)
	@rm -rf $(OBJECTS_PUSHSWAP)
fclean: clean
	@rm -rf $(NAME)

re : fclean all