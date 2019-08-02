/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:02:40 by marvan-d          #+#    #+#             */
/*   Updated: 2019/05/28 14:02:41 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dslen;
	size_t srlen;
	size_t i;

	dslen = (size_t)ft_strlen(dst);
	srlen = (size_t)ft_strlen(src);
	i = 0;
	if (dslen >= dstsize)
		return (dstsize + srlen);
	while (src[i] != '\0' && (i + dslen + 1) < dstsize)
	{
		dst[dslen + i] = src[i];
		i++;
	}
	dst[dslen + i] = '\0';
	return (dslen + srlen);
}
