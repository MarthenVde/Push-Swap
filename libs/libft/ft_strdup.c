/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:58:47 by marvan-d          #+#    #+#             */
/*   Updated: 2019/05/21 11:58:55 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		count;

	if (!(dup = ft_strnew(ft_strlen(str))))
		return (NULL);
	count = 0;
	while (str[count] != '\0')
	{
		dup[count] = str[count];
		count++;
	}
	dup[count] = '\0';
	return (dup);
}
