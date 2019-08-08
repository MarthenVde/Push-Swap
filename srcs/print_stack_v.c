/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack_v.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:06:24 by marvan-d          #+#    #+#             */
/*   Updated: 2019/08/08 14:06:26 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_stack_v(t_stack **head, int c, int size)
{
	int i;
	int div;
	t_stack *tmp;
	char chr;

	tmp = *head;
	if (size > 1000000000)
		div = 100000000;
	else if (size > 100000000)
		div = 10000000;
	else if (size > 10000000)
		div = 1000000;
	else if (size > 1000000)
		div = 100000;
	else if (size > 100000)
		div = 10000;
	else if (size > 10000)
		div = 128;
	else if (size > 1000)
		div = 16;
	else if (size > 500)
		div = 8;
	else if (size > 200)
		div = 4;
	else if (size > 100)
		div = 2;
	else
		div = 1;
	if (size > 400)
		chr = '.';
	else
		chr = '|';
	if (c == 1)
		ft_putstr(CYN);
	else if (c == 2)
		ft_putstr(MAG);
	while (tmp)
	{
		i = 0;
		while (i <= (tmp->data/div))
		{
			ft_putchar(chr);
			i++;
		}
		ft_putchar('\n');
		tmp = tmp->next;
	}
	ft_putstr(RESET);
}
