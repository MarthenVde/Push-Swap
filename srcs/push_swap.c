/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 12:47:45 by marvan-d          #+#    #+#             */
/*   Updated: 2019/07/01 12:47:46 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (ac == 2)
		ft_atostack(ft_strsplit(*(av + 1), ' '), &a);
	else if (ac > 2)
		ft_atostack(av + 1, &a);
	else
		return (0);
	if (!ft_stack_sorted(&a, &b))
	{
		if (ft_stack_size(&a) <= 5)
			small_sort(&a, &b, ft_stack_size(&a));
		else
			range_sort(&a, &b, ft_stack_size(&a));
	}
	ft_stack_del(&a);
	ft_stack_del(&b);
	return (0);
}
