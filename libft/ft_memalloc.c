/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:20:18 by marvan-d          #+#    #+#             */
/*   Updated: 2019/05/21 13:20:20 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*ret;
	size_t			i;
	unsigned char	*ptr;

	i = -1;
	ret = (void *)malloc(sizeof(ret) * size);
	if (!ret)
		return (NULL);
	ptr = ret;
	while (++i < size)
		ptr[i] = 0;
	return (ret);
}
