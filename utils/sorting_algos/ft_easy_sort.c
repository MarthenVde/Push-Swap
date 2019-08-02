/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_easy_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:22:41 by marvan-d          #+#    #+#             */
/*   Updated: 2019/07/25 11:22:42 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <push_swap.h>

static void easy_sort_3(t_stack **a, t_stack **b)
{
	t_stack *p;

	p = *a;
	if (p->data > p->next->data && p->data < p->next->next->data)
		exec_cmd("sa", a, b, 1);
	else if (p->data > p->next->data && p->next->data > p->next->next->data)
	{
		exec_cmd("sa", a, b, 1);
		exec_cmd("rra", a, b, 1);
	}
	else if (p->next->next->data < p->data && p->next->data < p->next->next->data)
		exec_cmd("ra", a, b, 1);
	else if (p->next->data > p->next->next->data && p->data < p->next->next->data)
	{
		exec_cmd("sa", a, b, 1);
		exec_cmd("ra", a, b, 1);
	}
	else if (p->data < p->next->data && p->data > p->next->next->data)
		exec_cmd("rra", a, b, 1);
	else
		return ;
}

void	ft_easy_sort(t_stack **a, t_stack **b, int size)
{
	t_stack *p;

	p = *a;
	if (size == 1 || size > 5 || size < 1)
		return ;
	if (size == 2)
	{
		if (p->data > p->next->data)
			return ;
		else
			exec_cmd("sa", a, b, 1);
	}
	else if (size == 3)
	{
		easy_sort_3(a, b);
	}
}
