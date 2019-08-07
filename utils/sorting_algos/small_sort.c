/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:58:39 by marvan-d          #+#    #+#             */
/*   Updated: 2019/08/05 10:58:40 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	void	small_sort_3(t_stack **a, t_stack **b)
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

void	small_sort_4(t_stack **a, t_stack **b)
{
	exec_cmd("pb", a, b, 1);
	small_sort_3(a, b);
	exec_cmd("pa", a, b, 1);
	if ((*a)->data > (*a)->next->next->next->data)
		exec_cmd("ra", a, b, 1);
	else if ((*a)->data > (*a)->next->next->data)
	{
		exec_cmd("sa", a, b, 1);
		exec_cmd("ra", a, b, 1);
		exec_cmd("sa", a, b, 1);
		exec_cmd("rra", a, b, 1);
	}
	else if ((*a)->data > (*a)->next->data)
		exec_cmd("sa", a, b, 1);
}

void	small_sort(t_stack **a, t_stack **b, int size)
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
		small_sort_3(a, b);
	else if (size == 4)
		small_sort_4(a, b);
}
