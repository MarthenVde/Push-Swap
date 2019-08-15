/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 12:40:23 by marvan-d          #+#    #+#             */
/*   Updated: 2019/06/13 12:40:24 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	size_t	i;
	size_t	len;
	char	*rev;

	if (s)
	{
		i = -1;
		len = ft_strlen(s);
		rev = ft_strnew(len);
		while (len)
			rev[++i] = s[(len--) - 1];
		return (rev);
	}
	return (NULL);
}
