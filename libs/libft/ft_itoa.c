/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:30:06 by marvan-d          #+#    #+#             */
/*   Updated: 2019/06/24 11:41:40 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_numlen(int n)
{
	int len;

	len = 0;
	while (n /= 10)
		len++;
	return (len + 1);
}

char			*ft_itoa(int n)
{
	char	*ret;
	int		l;
	int		neg;

	neg = (n < 0);
	if (n == MIN_INT)
		return (ft_strdup("-2147483648"));
	if (neg)
		n *= -1;
	l = ft_numlen(n) + neg;
	if (!(ret = ft_strnew(l)))
		return (NULL);
	while (l--)
	{
		ret[l] = n % 10 + '0';
		n /= 10;
	}
	if (neg)
		ret[0] = '-';
	return (ret);
}
