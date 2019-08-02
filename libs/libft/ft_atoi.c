/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:00:49 by marvan-d          #+#    #+#             */
/*   Updated: 2019/05/21 12:00:52 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	int ret;
	int is_neg;

	ret = 0;
	is_neg = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_neg = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		ret *= 10;
		if (ret < 0)
			if (is_neg == -1)
				return (0);
		ret += (int)(*str - '0');
		str++;
	}
	return (ret * is_neg);
}
