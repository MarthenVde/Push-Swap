/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 10:38:07 by marvan-d          #+#    #+#             */
/*   Updated: 2019/05/29 10:38:08 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	sub = ft_strnew(len);
	i = -1;
	if (!sub || !s)
		return (NULL);
	while (++i < len)
		sub[i] = s[start + i];
	return (sub);
}
