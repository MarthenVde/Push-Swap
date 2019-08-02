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

static	int	det_flow(t_stack **head, int range)
{
	int flow;
	int fow_c;
	int rev_c;
	t_stack *tmp;
	t_stack **rev;

	tmp = *head;
	rev = head;
	fow_c = 0;
	rev_c = 0;
	while (tmp && tmp->data > range)
	{
		tmp = tmp->next;
		fow_c++;
	}
	ft_stack_reverse(rev);
	while (*rev && (*rev)->data > range)
	{
		(*rev) = (*rev)->next;
		fow_c++;
	}
	flow = (fow_c <= rev_c) ? 1 : 0;
	return (flow);
}


void	ft_chunking_sort(t_stack **a, t_stack **b, int s_size)
{

	t_chunk chunk;
	int flow;

	flow = 0;
	chunk.num_chunks = (s_size >= 500) ? 11 : 5;
	chunk.size = (s_size / chunk.num_chunks) + 1;
	while (*a != NULL)
	{
		chunk.range = range_upper(*a, chunk.size);
		while (!range_empty(*a, chunk.range))
		{
			flow = det_flow(a, chunk.range);
			if ((*a)->data <= chunk.range)
				exec_cmd("pb", a, b, 1);
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
			exec_cmd("rb", a, b, 1);
		}
		exec_cmd("pa", a, b, 1);
	}
}