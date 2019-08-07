/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 12:43:28 by marvan-d          #+#    #+#             */
/*   Updated: 2019/07/01 12:43:29 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# define FT_STDIN 0
# define FT_STDOUT 1
# define FT_STDERR 2

typedef	struct	s_stack
{
	int				data;
	struct s_stack	*next;
}				t_stack;

typedef	struct	s_chunk
{
	int	high;
	int	low;
	int	size;
	int	range;
}				t_chunk;

void			ft_stack_del(t_stack **head);
int				range_upper(t_stack *head, int chunk_size);
int				range_empty(t_stack *head, int range);
int				find_range_highest(t_stack *head);
int				find_range_lowest(t_stack *head);
void			small_sort(t_stack **a, t_stack**b, int size);
void			exec_cmd(char *cmd, t_stack **stk_a, t_stack **stk_b, int mode);
void			ft_stack_reverse(t_stack **head);
void			range_sort(t_stack **a, t_stack **b, int s_size);
void			ft_stack_print(t_stack **head);
void			ft_add_stack_end(t_stack **head, t_stack *new);
t_stack			*ft_create_node(int data);
void			ft_atostack(char **arr, t_stack **head);
int				ft_stack_size(t_stack **head);
void			ft_add_stack_front(t_stack **head, t_stack *new);
void			ft_stack_swap(t_stack **head);
void			ft_stack_rotate(t_stack **head);
void			ft_stack_reverse_rotate(t_stack **head);
void			ft_stack_push(t_stack **head_a, t_stack **head_b);
int				ft_only_digits(const char *str);
int				ft_stack_sorted(t_stack **stack_a, t_stack **stack_b);
int				ft_overflow(char *str);
void			ft_err(void);
int				ft_duplicates(char **arr);
#endif
