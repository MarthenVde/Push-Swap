/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:03:19 by marvan-d          #+#    #+#             */
/*   Updated: 2019/08/13 13:03:20 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		check_flags(const char *av)
{
	if (*av == '-')
	{
		av++;
		while (*av)
		{
			if (*av != 'v' && *av != 'c' && *av != 'n')
				return (0);
			av++;
		}
	}
	else
		return (0);
	return (1);
}

int		set_flags(const char *av, t_flag *f)
{
	av++;
	while (*av)
	{
		if (*av == 'v' && f->v == 0)
			f->v = 1;
		else if (*av == 'n' && f->n == 0)
			f->n = 1;
		else if (*av == 'c' && f->c == 0)
			f->c = 1;
		else
			return (0);
		av++;
	}
	return (1);
}

void	print_box(int w, char *str)
{
	int i;

	i = -1;
	ft_putchar_col_fd(YEL, 0x2552, FT_STDOUT);
	while (++i < w)
		ft_putchar_col_fd(YEL, 0x2550, FT_STDOUT);
	ft_putchar_col_fd(YEL, 0x2555, FT_STDOUT);
	ft_putchar('\n');
	ft_putchar_col_fd(YEL, 0x2502, FT_STDOUT);
	ft_putstr_col_fd(GRN, str, FT_STDOUT);
	i = ft_strlen(str) - 1;
	while (++i < w)
		ft_putchar(' ');
	ft_putchar_col_fd(YEL, 0x2502, FT_STDOUT);
	ft_putchar('\n');
	ft_putchar_col_fd(YEL, 0x2558, FT_STDOUT);
	i = -1;
	while (++i < w)
		ft_putchar_col_fd(YEL, 0x2550, FT_STDOUT);
	ft_putchar_col_fd(YEL, 0x255B, FT_STDOUT);
	ft_putchar('\n');
}
