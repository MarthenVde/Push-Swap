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

static	void	pass_flags(int *ac, char **av, t_flag *f)
{
	av++;
	ac--;
	while (*av)
	{
		if (check_flags(*av))
		{
			if (!set_flags(*av, f))
				ft_err();
			av++;
			ac--;
		}
		else
			return;
	}
}

int	main(int ac, char **av)
{
	t_flag flags;
	t_stack	*a;
	t_stack	*b;
	char	*in_stream;
	int		high;
	int		nr_opp;

	nr_opp = 0;
	a = NULL;
	b = NULL;
	pass_flags(&ac, av, &flags);
	if (ac == 1)
	{
		ft_atostack(ft_strsplit(*(av), ' '), &a);
	}
	else if (ac > 1)
		ft_atostack(av, &a);
	else
		return (0);
	high = find_range_highest(a);
	while (get_next_line(FT_STDIN, &in_stream) > 0)
		{
			exec_cmd(in_stream, &a, &b, 0);
				if (flags.v)
	{
		print_stack_v(a, b, high);
		usleep(60000);
		ft_putstr("\e[1;1H\e[2J");
	}
	if (flags.c)
	{
		print_box(3, in_stream);
		if (!(flags.v))
		{
			usleep(60000);
			ft_putstr("\e[1;1H\e[2J");
		}
	}
			nr_opp++;
		}
	if (flags.v)
		print_stack_v(a, b, high);
	if (flags.n)
	{
		ft_putnbr(nr_opp);
		ft_putendl(" operations");
	}
	if (ft_stack_sorted(&a, &b))
		ft_putstr_col_fd(GRN, "OK\n", FT_STDOUT);
	else
		ft_putstr_col_fd(RED, "KO\n", FT_STDOUT);
	ft_stack_del(&a);
	ft_stack_del(&b);
	return (0);
}
