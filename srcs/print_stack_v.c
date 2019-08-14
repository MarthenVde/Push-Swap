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
#include <sys/ioctl.h>

void	print_stack_v(t_stack *stk_a,  t_stack *stk_b, int highest)
{
	int i;
	int div;
	struct winsize w;
    
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	div = 1;
	while ((abs(highest) / div) > (w.ws_col / 2))
		div++;
	while (stk_a && stk_b)
	{
		i = -1;
		while (++i <= (abs(stk_a->data) / div))
		{
			ft_putstr(CYN);
			ft_putchar(0x2585);
			ft_putstr(RESET);
		}
		while (++i <= (w.ws_col - abs(stk_b->data) / div))
			ft_putchar(' ');
		while (++i <= w.ws_col)
		{
			ft_putstr(MAG);
			ft_putchar(0x2585);
			ft_putstr(RESET);
		}
		ft_putchar('\n');
		stk_a = stk_a->next;
		stk_b = stk_b->next;
	}
	while (stk_a)
	{
		i = -1;
		while (++i <= (abs(stk_a->data) / div))
		{
			ft_putstr(CYN);
			ft_putchar(0x2586);
			ft_putstr(RESET);
		}
		ft_putchar('\n');
		stk_a = stk_a->next;
	}
	while (stk_b)
	{
		i = -1;
		while (++i < (w.ws_col - (abs(stk_b->data) / div)))
			ft_putchar(' ');
		while (++i < w.ws_col)
		{
			ft_putstr(MAG);
			ft_putchar(0x2586);
			ft_putstr(RESET);
		}
		ft_putchar('\n');
		stk_b = stk_b->next;
	}
	ft_putstr(RESET);
}
