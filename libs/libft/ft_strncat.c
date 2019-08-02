/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:54:06 by marvan-d          #+#    #+#             */
/*   Updated: 2019/05/28 13:54:07 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int s1_len;
	unsigned int s2_len;

	s1_len = ft_strlen(s1);
	s2_len = 0;
	while (s2[s2_len] != '\0' && s2_len < (unsigned int)n)
	{
		s1[s1_len + s2_len] = s2[s2_len];
		s2_len++;
	}
	s1[s1_len + s2_len] = '\0';
	return (s1);
}
