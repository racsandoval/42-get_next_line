/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:56:55 by marvin            #+#    #+#             */
/*   Updated: 2020/03/08 14:49:38 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	copy = malloc(len + 1);
	i = 0;
	while (i < len)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = malloc(len1 + len2 + 1);
	if (!join)
		return (0);
	i = 0;
	while (++i < len1 + 1)
		join[i - 1] = s1[i - 1];
	j = 0;
	while (j < len2)
	{
		join[i + j - 1] = s2[j];
		j++;
	}
	join[i + j - 1] = 0;
	free(s1);
	return (join);
}

int		fail_fd(char *str, char **line)
{
	*line = ft_strdup("");
	free(str);
	return (-1);
}

int		return_value(char *str, int r_num)
{
	if (str && !ft_strlen(str))
	{
		str = NULL;
		free(str);
	}
	return (r_num ? 1 : 0);
}
