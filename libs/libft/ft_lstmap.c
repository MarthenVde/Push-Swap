/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:06:34 by marvan-d          #+#    #+#             */
/*   Updated: 2019/06/05 12:06:39 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;

	new_lst = NULL;
	if (lst)
	{
		if (!(new_lst = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		new_lst = f(lst);
		new_lst->next = ft_lstmap(lst->next, f);
	}
	return (new_lst);
}
