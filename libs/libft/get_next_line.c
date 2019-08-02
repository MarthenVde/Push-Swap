/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvan-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 10:49:45 by marvan-d          #+#    #+#             */
/*   Updated: 2019/06/10 10:49:47 by marvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_realloc_str(char *str, char *new)
{
	char *tmp;

	tmp = str;
	str = new;
	free(tmp);
	return (new);
}

static	char	*read_to_str(int fd, char *str)
{
	char	buff[BUFF_SIZE + 1];
	ssize_t	b_read;

	while (!(ft_strchr(str, '\n')))
	{
		if ((b_read = read(fd, buff, BUFF_SIZE)) < 0)
			return (NULL);
		buff[b_read] = '\0';
		str = ft_realloc_str(str, ft_strjoin(str, buff));
		if (b_read == 0)
			return (str);
	}
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static char *str;
	char		*adr_lf;
	int			ret;

	str = !str ? ft_strnew(1) : str;
	if (!line || BUFF_SIZE < 1 || !(str = read_to_str(fd, str)))
		return (-1);
	if ((adr_lf = ft_strchr(str, '\n')))
	{
		if (!(*line = (ft_strndup(str, adr_lf - str))))
			return (-1);
		str = ft_realloc_str(str, ft_strdup(adr_lf + 1));
		return (1);
	}
	if (str[0] == '\0')
		ret = 0;
	else if (!(*line = ft_strdup(str)))
		ret = -1;
	else
		ret = 1;
	ft_strdel(&str);
	return (ret);
}
