/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 19:06:53 by marvan-d          #+#    #+#             */
/*   Updated: 2019/07/03 19:06:54 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_swap(t_stack **head)
{
	t_stack *tmp;

	if (*head && (*head)->next)
	{
		tmp = (*head)->next;
		(*head)->next = (*head)->next->next;
		ft_add_stack_front(head, tmp);
	}
}

void	ft_stack_rotate(t_stack **head)
{
	t_stack *end;
	t_stack *new_head;

	end = *head;
	if (*head && (*head)->next)
	{
		new_head = (*head)->next;
		while (end->next)
			end = end->next;
		end->next = *head;
		(*head)->next = NULL;
		*head = new_head;
	}
}

void	ft_stack_reverse_rotate(t_stack **head)
{
	t_stack *second_last;
	t_stack *end;

	second_last = *head;
	if (*head && (*head)->next)
	{
		while (second_last->next->next)
			second_last = second_last->next;
		end = second_last->next;
		end->next = *head;
		*head = end;
		second_last->next = NULL;
	}
}

void	ft_stack_push(t_stack **stk_a, t_stack **stk_b)
{
	t_stack *tmp;

	tmp = *stk_a;
	if (*stk_a)
	{
		*stk_a = (*stk_a)->next;
		ft_add_stack_front(stk_b, tmp);
	}
}
