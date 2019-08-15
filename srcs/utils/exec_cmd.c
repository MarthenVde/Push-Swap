/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 08:40:53 by marvan-d          #+#    #+#             */
/*   Updated: 2019/08/15 15:59:26 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	void	arr_del(char **arr)
{
	int i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

static	void	exec(int index, t_stack **stk_a, t_stack **stk_b)
{
	if (index == 3)
		ft_stack_push(stk_b, stk_a);
	if (index == 4)
		ft_stack_push(stk_a, stk_b);
	if (index == 0 || index == 2)
		ft_stack_swap(stk_a);
	if (index == 1 || index == 2)
		ft_stack_swap(stk_b);
	if (index == 5 || index == 7)
		ft_stack_rotate(stk_a);
	if (index == 6 || index == 7)
		ft_stack_rotate(stk_b);
	if (index == 8 || index == 10)
		ft_stack_reverse_rotate(stk_a);
	if (index == 9 || index == 10)
		ft_stack_reverse_rotate(stk_b);
}

void			exec_cmd(char *cmd, t_stack **stk_a, t_stack **stk_b, int mode)
{
	char	**cmd_lst;
	int		index;

	index = -1;
	cmd_lst = ft_strsplit("sa,sb,ss,pa,pb,ra,rb,rr,rra,rrb,rrr", ',');
	while (cmd_lst[++index])
		if (ft_strequ(cmd, cmd_lst[index]))
		{
			if (mode == 1)
				ft_putendl_fd(cmd, FT_STDOUT);
			else if (mode == 2)
			{
				ft_putstr(YEL);
				ft_putendl_fd(cmd, FT_STDOUT);
				ft_putstr(RESET);
			}
			exec(index, stk_a, stk_b);
			arr_del(cmd_lst);
			return ;
		}
	arr_del(cmd_lst);
	ft_err();
}
