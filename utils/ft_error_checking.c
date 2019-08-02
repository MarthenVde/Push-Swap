/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_checking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:55:42 by marvan-d          #+#    #+#             */
/*   Updated: 2019/07/10 13:55:43 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_err(void)
{
    ft_putendl_fd("Error", FT_STDERR);
	exit(0);
}

int		ft_only_digits(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
    while (*str)
	{
        if (!(ft_isdigit(*str)))
            return (0);
		str++;
	}
    return (1);
}

int		ft_overflow(char *str)
{
	int ret;
	int is_neg;

	ret = 0;
	is_neg = 1;
	if (ft_strequ(str, "-2147483648"))
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_neg = -1;
		str++;
	}
	while (*str)
	{
		ret = ret * 10 + (int)(*str - '0');
		if (ret < 0)
			return (1);
		str++;
	}
	return (0);
}

int		ft_duplicates(char **arr)
{
	int i;
	char *tmp;

	tmp = *arr;
	while (*arr)
	{
		i = 1;
		tmp = *arr;
		while(*(arr + i))
		{
			if (ft_strcmp(*(arr + i), tmp) == 0)
				return (0);
			i++;
		}
		arr++;
	}
	return (1);
}
