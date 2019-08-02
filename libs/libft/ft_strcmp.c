/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:01:51 by marvan-d          #+#    #+#             */
/*   Updated: 2019/05/21 12:01:54 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((unsigned char)*s1 == (unsigned char)*s2 && *s2 && *s1)
	{
		s1++;
		s2++;
	}
	if ((unsigned char)*s1 < (unsigned char)*s2)
		return (-1);
	if ((unsigned char)*s1 > (unsigned char)*s2)
		return (1);
	return (0);
}
