#!/bin/bash

gcc -Wall -Wextra -Werror stack/srcs/ft_main_method.c ft_push_swap/srcs/print_stack.c \
libiti/srcs/print_number.c  libiti/srcs/string2number.c checker/srcs/checker.c \
print/apply_flags.c print/checker_flags.c print/display.c \
print/ft_atoi.c print/ft_putnbr.c print/print.c print/print_utils.c \
print/display_flags.c ft_push_swap/srcs/is_sorted_stack.c \
ft_push_swap/srcs/operation_stack2.c libiti/srcs/compare_str.c \
ft_push_swap/srcs/operation_stack.c libiti/srcs/is_number.c readline/srcs/readline.c \
libiti/srcs/joinstr.c libiti/srcs/print_errors.c ft_push_swap/srcs/apply_operation.c  -o f