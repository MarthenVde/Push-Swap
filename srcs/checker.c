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
	int		num_of_operations;
	t_stack	*a;
	t_stack	*b;
	char	*in_stream;

	a = NULL;
	b = NULL;
	num_of_operations = 0;
	in_stream = NULL;
	if (ac == 2)
		ft_atostack(ft_strsplit(*(av + 1), ' '), &a);
	else if (ac > 2)
		ft_atostack(av + 1, &a);
	else
		return (0);
	while (get_next_line(FT_STDIN, &in_stream) > 0)
		exec_cmd(in_stream, &a, &b, 0);
	if (ft_stack_sorted(&a, &b))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_stack_del(&a);
	ft_stack_del(&b);
	return (0);
}
