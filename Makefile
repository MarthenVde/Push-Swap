# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 16:57:40 by marvan-d          #+#    #+#              #
#    Updated: 2019/06/21 17:01:31 by marvan-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
HFILE = ./includes/push_swap.h
LINKER = -L./libft -lft
CFLAGS = -Wall -Werror -Wextra
LIBFILE = ./libft/libft.a
NAME_CH = checker
NAME_PS = push_swap
CC = gcc

SRC =	srcs/utils/exec_cmd.c \
		srcs/utils/error_checking.c \
		srcs/sorting_algos/range_sort.c \
		srcs/sorting_algos/range_utils.c\
		srcs/sorting_algos/small_sort.c \
		srcs/utils/flags.c \
		srcs/stack/ft_basic_stack.c \
		srcs/stack/ft_stack_commands.c \
		srcs/stack/ft_stack_operations.c \
		srcs/utils/print_stack_v.c

all: $(LIBFILE) $(NAME_CH) $(NAME_PS) $(HFILE)

$(LIBFILE):
	make -C libft

$(NAME_CH): srcs/checker.c $(SRC) $(HFILE)
	$(CC) -I includes/ $(CFLAGS) srcs/checker.c $(SRC) $(LINKER) -o $(NAME_CH)

$(NAME_PS): srcs/push_swap.c $(SRC) $(HFILE)
	$(CC) -I includes/ $(CFLAGS) srcs/push_swap.c $(SRC) $(LINKER) -o $(NAME_PS)

clean:
	rm $(NAME_CH) $(NAME_PS)

fclean:
	make -C libft fclean
	rm $(NAME_CH) $(NAME_PS)

re: fclean all