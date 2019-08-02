/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:59:10 by marvan-d          #+#    #+#             */
/*   Updated: 2019/05/21 11:59:13 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (--n && *s2 && *s1)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			break ;
		s1++;
		s2++;
	}
	if ((unsigned char)*s1 < (unsigned char)*s2)
		return (-1);
	if ((unsigned char)*s1 > (unsigned char)*s2)
		return (1);
	return (0);
}
