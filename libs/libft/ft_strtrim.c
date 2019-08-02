/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:34:48 by marvan-d          #+#    #+#             */
/*   Updated: 2019/05/29 13:34:49 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*ts;

	if (s)
	{
		start = 0;
		end = ft_strlen(s);
		while (ft_iswhitespace(s[start]))
			start++;
		while (ft_iswhitespace(s[end - 1]))
			end--;
		if ((end - start) < 0)
			return (ft_strdup(""));
		ts = ft_strsub(s, start, (end - start));
		return (ts);
	}
	return (NULL);
}
