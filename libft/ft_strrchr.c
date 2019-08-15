/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:59:31 by marvan-d          #+#    #+#             */
/*   Updated: 2019/05/28 14:59:32 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = ft_strlen(s) - 1;
	if ((unsigned char)c == '\0')
		return ((char *)s + len + 1);
	while (s + len != s - 1)
	{
		if (*(s + len) == (unsigned char)c)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}
