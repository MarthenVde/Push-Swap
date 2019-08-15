/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 18:14:02 by marvan-d          #+#    #+#             */
/*   Updated: 2019/06/14 18:14:04 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char *ret;

	if (!s1 || !s2 || !(ret = ft_strnew(ft_strlen(s1) + len)))
		return (NULL);
	ft_strcpy(ret, s1);
	ft_strncat(ret, s2, len);
	return (ret);
}
