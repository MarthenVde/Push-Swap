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

#include <stdio.h>

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
