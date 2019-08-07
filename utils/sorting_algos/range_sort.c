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

static	void	push_ranges_b(t_stack **a, t_stack **b, t_chunk chunk)
{
	int flow;

	while (*a)
	{
		chunk.range = range_upper(*a, chunk.size);
		while (!range_empty(*a, chunk.range))
		{
			if ((*b) && (*b)->next && (*b)->data < (*b)->next->data)
				exec_cmd("sb", a, b, 1);
			if ((*a)->data <= chunk.range)
				exec_cmd("pb", a, b, 1);
			flow = det_flow(a, chunk.range, ft_stack_size(a));
			if (flow)
				exec_cmd("ra", a, b, 1);
			else
				exec_cmd("rra", a, b, 1);
		}
	}
}

static	void	push_back_a(t_stack **a, t_stack **b, t_chunk chunk)
{
	while (*b)
	{
		chunk.high = find_range_highest(*b);
		while ((*b)->data != chunk.high)
		{
			if (det_flow_high(b, chunk.high))
				exec_cmd("rb", a, b, 1);
			else
				exec_cmd("rrb", a, b, 1);
		}
		exec_cmd("pa", a, b, 1);
	}
}

void			range_sort(t_stack **a, t_stack **b, int s_size)
{
	t_chunk	chunk;

	chunk.size = (s_size >= 500) ? 32 : 20;
	push_ranges_b(a, b, chunk);
	push_back_a(a, b, chunk);
}
