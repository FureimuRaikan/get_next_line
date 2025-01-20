/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:53:30 by yguinio           #+#    #+#             */
/*   Updated: 2024/11/28 11:13:52 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	bytes;
	char	*buff;

	i = 0;
	bytes = nmemb * size;
	if (size && (bytes / size) != nmemb)
		return (NULL);
	buff = (void *)malloc(bytes);
	if (!buff)
		return (NULL);
	while (i < bytes)
		buff[i++] = 0;
	return (buff);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1 && s1[++i])
		join[i] = s1[i];
	j = 0;
	while (s2 && s2[j])
		join[i++] = s2[j++];
	join[ft_strlen(s1) + ft_strlen(s2)] = 0;
	free(s1);
	return (join);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)(str + i));
	return (NULL);
}
