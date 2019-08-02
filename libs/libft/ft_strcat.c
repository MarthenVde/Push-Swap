/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 11:04:14 by marvan-d          #+#    #+#             */
/*   Updated: 2019/05/28 11:04:16 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned int len1;
	unsigned int len2;

	len1 = ft_strlen(s1);
	len2 = 0;
	while (s2[len2] != '\0')
	{
		s1[len1 + len2] = s2[len2];
		len2++;
	}
	s1[len1 + len2] = '\0';
	return (s1);
}
