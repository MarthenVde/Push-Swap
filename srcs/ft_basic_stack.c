/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 19:05:20 by marvan-d          #+#    #+#             */
/*   Updated: 2019/07/03 19:05:21 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack *ft_create_node(int data)
{
    t_stack *tmp;

    tmp = NULL;
    if ((tmp = (t_stack *)malloc(sizeof(t_stack))))
    {
        tmp->data = data;
        tmp->next = NULL;
    }
    return (tmp);
}

void	ft_add_stack_front(t_stack **head, t_stack *new)
{
	if (head && new)
	{
		new->next = *head;
		*head = new;
	}
}

void    ft_add_stack_end(t_stack **head, t_stack *new)
{
    t_stack *curr;

    curr = *head;
    if (curr)
    {
        while (curr->next)
            curr = curr->next;
        curr->next = new;
    }
    else
        *head = new;
}
