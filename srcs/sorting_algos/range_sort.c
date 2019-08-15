/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 09:47:52 by marvan-d          #+#    #+#             */
/*   Updated: 2019/08/05 09:47:53 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	int		det_flow(t_stack **head, int range, int len)
{
	int		i;
	int		high;
	int		low;
	t_stack	*cur;

	cur = *head;
	low = -1;
	high = -1;
	i = 0;
	while (cur)
	{
		if (low == -1 && cur->data <= range)
			low = i;
		if (high <= range)
			high = i;
		i++;
		cur = cur->next;
	}
	if ((len - high) < low)
		return (0);
	return (1);
}

static	int		det_flow_high(t_stack **head, int n)
{
	int		start;
	int		end;
	t_stack	*cur;

	cur = *head;
	start = 0;
	end = 0;
	while (cur)
	{
		if (cur->data == n)
			while (cur)
			{
				cur = cur->next;
				end++;
			}
		else
		{
			cur = cur->next;
			start++;
		}
	}
	if (start < end)
		return (1);
	return (0);
}

static	void	push_to_b(t_stack **a, t_stack **b, t_chunk chk, int m)
{
	int flow;

	while (*a)
	{
		chk.range = range_upper(*a, chk.size);
		while (!range_empty(*a, chk.range))
		{
			if ((*b) && (*b)->next && (*b)->data < (*b)->next->data)
				exec_cmd("sb", a, b, m);
			if ((*a)->data <= chk.range)
				exec_cmd("pb", a, b, m);
			flow = det_flow(a, chk.range, ft_stack_size(a));
			if (flow)
				exec_cmd("ra", a, b, m);
			else
				exec_cmd("rra", a, b, m);
		}
	}
}

static	void	push_to_a(t_stack **a, t_stack **b, t_chunk chk, int m)
{
	while (*b)
	{
		chk.high = find_range_highest(*b);
		while ((*b)->data != chk.high)
		{
			if (det_flow_high(b, chk.high))
				exec_cmd("rb", a, b, m);
			else
				exec_cmd("rrb", a, b, m);
		}
		exec_cmd("pa", a, b, m);
	}
}

void			range_sort(t_stack **a, t_stack **b, int size, int mode)
{
	t_chunk	chunk;

	chunk.size = (size >= 500) ? 32 : 20;
	push_to_b(a, b, chunk, mode);
	push_to_a(a, b, chunk, mode);
}
