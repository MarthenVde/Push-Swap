/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:32:52 by marvan-d          #+#    #+#             */
/*   Updated: 2019/05/27 11:32:53 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	if (!dst && !src)
		return (NULL);
	i = -1;
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	if (src_ptr < dst_ptr)
		while (len-- > 0)
			dst_ptr[len] = src_ptr[len];
	else
		while (++i < len)
			dst_ptr[i] = src_ptr[i];
	return (dst);
}
