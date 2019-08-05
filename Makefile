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

HEADER_PATH = includes/
LIB_PATH = libs/libft/libft.a
CFLAGS = -Wall -Werror -Wextra
UTILS =	utils/exec_cmd.c \
		utils/error_checking.c \
		utils/sorting_algos/range_sort.c \
		utils/sorting_algos/range_utils.c\
		utils/sorting_algos/small_sort.c

SRC =	srcs/ft_basic_stack.c \
		srcs/ft_stack_commands.c \
		srcs/ft_stack_operations.c

CHECKER = srcs/checker.c
PUSHSWAP = srcs/push_swap.c
CC = gcc

all: checker pushswap

lib:
	cd libs/libft && make
libclean:
	cd libs/libft && make fclean
checker: lib
	$(CC) $(CFLAGS) -I$(HEADER_PATH) $(SRC) $(CHECKER) $(UTILS) -o checker $(LIB_PATH)
pushswap: lib
	$(CC) $(CFLAGS) -I$(HEADER_PATH) $(SRC) $(PUSHSWAP) $(UTILS) -o push_swap $(LIB_PATH)

clean: libclean
	rm checker push_swap
re: clean all