/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:56:53 by marvin            #+#    #+#             */
/*   Updated: 2020/03/08 14:49:36 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_line(char *str, int lb)
{
	char	*tmp;
	int		i;

	tmp = malloc(lb + 1);
	i = 0;
	while (i < lb)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int		get_line_break(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		if (str[i++] == '\n')
			return (i);
	return (-1);
}

char	*send_line(char *str, char **line)
{
	char	*tmp_str;
	char	*tmp;
	int		lb;

	if (get_line_break(str) != -1)
	{
		lb = get_line_break(str) - 1;
		tmp_str = ft_strdup(&str[lb + 1]);
	}
	else
	{
		lb = ft_strlen(str);
		tmp_str = ft_strdup("");
	}
	tmp = get_line(str, lb);
	*line = tmp;
	free(str);
	return (tmp_str);
}

int		get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX];
	char		*tmp;
	int			r_num;

	if (fd < 0 || BUFFER_SIZE < 1 || (read(fd, NULL, 0)) < 0 || !line)
		return (-1);
	r_num = 1;
	if (!str[fd])
		str[fd] = ft_strdup("");
	while (get_line_break(str[fd]) == -1)
	{
		tmp = malloc(sizeof(char *) * BUFFER_SIZE + 1);
		if (!(r_num = read(fd, tmp, BUFFER_SIZE)))
		{
			free(tmp);
			break ;
		}
		tmp[r_num] = '\0';
		str[fd] = ft_strjoin(str[fd], tmp);
		free(tmp);
	}
	if (!str[fd])
		return (fail_fd(str[fd], line));
	str[fd] = send_line(str[fd], line);
	return (return_value(str[fd], r_num));
}
