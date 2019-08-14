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

int	main(int ac, char **av)
{
	t_flag flags;
	t_stack	*a;
	t_stack	*b;
	char	*in_stream;
	int		high;
	int		nr_opp;

	flags.v = 0;
	flags.c = 0;
	flags.n = 0;
	nr_opp = 0;
	a = NULL;
	b = NULL;
	av += 1;
	ac--;
	in_stream = NULL;
	while (*av)
	{
		if (check_flags(*av) == 1)
		{
			if (set_flags(*av, &flags) == 0)
				ft_err();
			av += 1;
			ac--;
		}
		else
			break;
		
	}
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
				usleep(51000);
				ft_putstr("\e[1;1H\e[2J");
			}
			if (flags.c)
			{
				ft_putchar(0x2552);
				ft_putchar(0x2550);
				ft_putchar(0x2550);
				ft_putchar(0x2550);
				ft_putchar(0x2550);
				ft_putchar(0x2555);
				ft_putchar('\n');
				ft_putchar(0x2502);
				ft_putstr(GRN);
				ft_putstr(in_stream);
				ft_putstr(RESET);
				if (ft_strlen(in_stream) < 3)
					ft_putstr("  ");
				else
					ft_putchar(' ');
				ft_putchar(0x2502);
				ft_putchar('\n');
				ft_putchar(0x2558);
				ft_putchar(0x2550);
				ft_putchar(0x2550);
				ft_putchar(0x2550);
				ft_putchar(0x2550);
				ft_putchar(0x255B);

				ft_putstr("\n");
				if (!(flags.v))
				{
					usleep(51000);
					ft_putstr("\e[1;1H\e[2J");
				}
			}
			nr_opp++;
		}
	if (flags.v)
		print_stack_v(a, b, high);
	if (flags.n)
	{
		ft_putstr(YEL);
		ft_putstr("Ammount of operations [");
		ft_putnbr(nr_opp);
		ft_putendl("]");
		ft_putstr(RESET);
	}
	if (ft_stack_sorted(&a, &b))
	{
		ft_putstr(GRN);
		ft_putendl("OK");
		ft_putstr(RESET);
	}
	else
	{
		ft_putstr(RED);
		ft_putendl("KO");
		ft_putstr(RESET);
	}
	ft_stack_del(&a);
	ft_stack_del(&b);
	return (0);
}
