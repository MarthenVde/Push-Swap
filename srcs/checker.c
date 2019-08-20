/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:55:21 by marvan-d          #+#    #+#             */
/*   Updated: 2019/06/21 16:55:22 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	void	pass_flags(int *ac, char ***av, t_flag *f)
{
	(*av)++;
	(*ac)--;
	while (**av)
	{
		if (check_flags(**av))
		{
			if (!set_flags(**av, f))
				ft_err();
			(*av)++;
			(*ac)--;
		}
		else
			return ;
	}
}

static	int		set_stack_a(int ac, char **av, t_stack **a)
{
	char **stk_arr;

	if (ac == 1)
	{
		stk_arr = ft_strsplit(*av, ' ');
		ft_atostack(stk_arr, a);
		arr_del(stk_arr);
	}
	else if (ac > 1)
		ft_atostack(av, a);
	else
		return (0);
	return (1);
}

static	int		read_commands(t_stack **a, t_stack **b, t_flag f, int high)
{
	char	*in_stream;
	int		nr_opp;

	nr_opp = 0;
	while (get_next_line(FT_STDIN, &in_stream) > 0)
	{
		exec_cmd(in_stream, a, b, 0);
		if (f.v)
		{
			print_stack_v(*(a), *(b), high);
			usleep(60000);
			ft_putstr("\e[1;1H\e[2J");
		}
		if (f.c)
			print_box(3, in_stream);
		if (!(f.v) && f.c)
			usleep(50000);
		nr_opp++;
		ft_strdel(&in_stream);
	}
	return (nr_opp);
}

static	void	print_num_opp(int nbr)
{
	ft_putstr_col_fd(YEL, "The number of commands are [", FT_STDOUT);
	ft_putnbr(nbr);
	ft_putstr_col_fd(YEL, "]\n", FT_STDOUT);
}

int				main(int ac, char **av)
{
	t_flag	flags;
	t_stack	*a;
	t_stack	*b;
	int		high;
	int		nr_opp;

	pass_flags(&ac, &av, &flags);
	if (!set_stack_a(ac, av, &a))
		return (0);
	high = find_range_highest(a);
	nr_opp = read_commands(&a, &b, flags, high);
	if (flags.v)
		print_stack_v(a, b, high);
	if (flags.n)
		print_num_opp(nr_opp);
	if (ft_stack_sorted(&a, &b))
		ft_putstr_col_fd(GRN, "OK\n", FT_STDOUT);
	else
		ft_putstr_col_fd(RED, "KO\n", FT_STDOUT);
	free_stacks(&a, &b);
	return (0);
}
