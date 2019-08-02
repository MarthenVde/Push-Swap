/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunking_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:23:11 by marvan-d          #+#    #+#             */
/*   Updated: 2019/07/25 13:23:12 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>





#include <stdio.h>

static	int	find_highest(t_stack *head)
{
	int highest;

	highest = head->data;
	while (head)
	{
		if (head->data > highest)
			highest = head->data;
		head = head->next;
	}
	return (highest);
}

static	int	find_lowest(t_stack *head)
{
	int lowest;

	lowest = head->data;
	while (head)
	{
		if (head->data < lowest)
			lowest = head->data;
		head = head->next;
	}
	return (lowest);
}

static int	range_empty(t_stack *head, int range)
{
	while (head)
	{
		if (head->data <= range)
			return (0);
		head = head->next;
	}
	return (1);
}

static	int	range_upper(t_stack *head, int chunk_size)
{
	t_stack *tmp;
	int upper;
	int lowest;

	lowest = find_lowest(head);
	while (chunk_size--)
	{
		tmp = head;
		upper = find_highest(head);
		while (tmp)
		{
			if (tmp->data > lowest && tmp->data < upper)
				upper = tmp->data;
			tmp = tmp->next;
		}
		lowest = upper;
	}
	return (upper);
}

static	int	det_flow(t_stack **head, int range, int len)
{
	int index;
	int high;
	int low;
	t_stack *cur;

	cur = *head;
	low = -1;
	high = -1;
	index = 0;
	while (cur)
	{
		if (low == -1 &&  cur->data <= range)
			low = index;
		if (high <=  range)
			high = index;
		index++;
		cur = cur->next;
	}
	//printf("len = %i |-| low = %i |-| high = %i |-| (len -  high) = %i  |-| range = %i\n",len, low, high, (len - high), range);
	if (high != -1 && (len -  high) < low)
	{
		//ft_putendl("flow reverse");
		return (0);
	}
	return (1);
}

static	int	det_flow_highest(t_stack **head, int n)
{
	int start;
	int end;
	t_stack *cur;

	cur = *head;
	start = 0;
	end = 0;
	while (cur)
	{
		if (cur->data == n)
		{
			while (cur)
			{
				cur = cur->next;
				end++;
			}
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

void	ft_chunking_sort(t_stack **a, t_stack **b, int s_size)
{

	t_chunk chunk;
	int flow;

	flow = 0;
	chunk.size = (s_size >= 500) ? 32 : 20;
	while (*a != NULL)
	{
		chunk.range = range_upper(*a, chunk.size);
		while (!range_empty(*a, chunk.range))
		{
			
			if ((*a)->data <= chunk.range)
				exec_cmd("pb", a, b, 1);
			flow = det_flow(a, chunk.range,  ft_stack_size(a));
			if (flow)
				exec_cmd("ra", a, b, 1);
			else
				exec_cmd("rra", a, b, 1);
		}
	}
	while (*b != NULL)
	{
		int highest = find_highest(*b);
		while ((*b)->data != highest)
		{
			if (det_flow_highest(b, highest))
				exec_cmd("rb", a, b, 1);
			else
				exec_cmd("rrb", a, b, 1);
		}
		exec_cmd("pa", a, b, 1);
	}
}