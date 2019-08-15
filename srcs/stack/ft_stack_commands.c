/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:04:22 by marvan-d          #+#    #+#             */
/*   Updated: 2019/07/26 11:04:23 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		ft_stack_sorted(t_stack **stk_a, t_stack **stk_b)
{
	t_stack *tmp;

	tmp = *stk_a;
	if ((*stk_a) && !(*stk_b))
	{
		while (tmp->next)
		{
			if (tmp->data >= tmp->next->data)
				return (0);
			tmp = tmp->next;
		}
		return (1);
	}
	return (0);
}

int		ft_stack_size(t_stack **head)
{
	t_stack	*curr;
	int		size;

	curr = *head;
	size = 0;
	while (curr)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}

void	ft_atostack(char **arr, t_stack **head)
{
	int data;

	if (!(*arr) || !arr || ft_duplicates(arr) == 0)
		ft_err();
	while (*arr)
	{
		if (!ft_only_digits(*arr) || ft_overflow(*arr))
			ft_err();
		data = atoi(*arr);
		ft_add_stack_end(head, ft_create_node(data));
		arr++;
	}
}
