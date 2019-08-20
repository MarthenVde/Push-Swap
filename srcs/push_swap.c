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
	char	**stk_arr;

	av++;
	ac--;
	if (ac == 1)
	{
		stk_arr = ft_strsplit(*av, ' ');
		ft_atostack(stk_arr, &a);
		arr_del(stk_arr);
	}
	else if (ac > 1)
		ft_atostack(av, &a);
	else
		return (0);
	if (!ft_stack_sorted(&a, &b))
	{
		if (ft_stack_size(&a) <= 5)
			small_sort(&a, &b, ft_stack_size(&a));
		else
			range_sort(&a, &b, ft_stack_size(&a), 1);
	}
	free_stacks(&a, &b);
	return (0);
}
