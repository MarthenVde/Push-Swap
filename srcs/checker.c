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
	t_stack	*a;
	t_stack	*b;
	char	*in_stream;
	int		high;

	a = NULL;
	b = NULL;
	av += 1;
	ac--;
	in_stream = NULL;
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
			print_stack_v(a, b, high);
			usleep(51000);
			ft_putstr("\e[1;1H\e[2J");
		}
	print_stack_v(a, b, high);
	if (ft_stack_sorted(&a, &b))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_stack_del(&a);
	ft_stack_del(&b);
	return (0);
}
