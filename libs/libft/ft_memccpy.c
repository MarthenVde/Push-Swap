/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:54:31 by marvan-d          #+#    #+#             */
/*   Updated: 2019/05/23 12:54:32 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*new_dst;
	unsigned char	*new_src;

	i = -1;
	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	while (++i < n)
	{
		new_dst[i] = new_src[i];
		if (new_src[i] == (unsigned char)c)
			return (new_dst + i + 1);
	}
	return (NULL);
}
