/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:21:44 by marvan-d          #+#    #+#             */
/*   Updated: 2019/08/05 10:21:45 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	find_range_lowest(t_stack *head)
{
	int		lowest;
	t_stack	*tmp;

	tmp = head;
	lowest = tmp->data;
	while (tmp)
	{
		if (tmp->data < lowest)
			lowest = tmp->data;
		tmp = tmp->next;
	}
	return (lowest);
}

int	find_range_highest(t_stack *head)
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

int	range_empty(t_stack *head, int range)
{
	while (head)
	{
		if (head->data <= range)
			return (0);
		head = head->next;
	}
	return (1);
}

int	range_upper(t_stack *head, int chunk_size)
{
	t_stack	*curr;
	int		upper;
	int		lowest;

	lowest = find_range_lowest(head);
	while (chunk_size--)
	{
		curr = head;
		upper = find_range_highest(head);
		while (curr)
		{
			if (curr->data > lowest && curr->data < upper)
				upper = curr->data;
			curr = curr->next;
		}
		lowest = upper;
	}
	return (upper);
}
