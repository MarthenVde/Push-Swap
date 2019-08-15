/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_col_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:22:46 by marvan-d          #+#    #+#             */
/*   Updated: 2019/08/15 18:22:47 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_col_fd(char *colour, char const *s, int fd)
{
	while (*s)
	{
		ft_putchar_col_fd(colour, *s, fd);
		s++;
	}
}
