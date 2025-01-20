/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:11:22 by yguinio           #+#    #+#             */
/*   Updated: 2024/11/28 12:21:35 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *storage)
{
	char	*buff;
	int		count;

	count = 1;
	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr(storage, '\n') && count != 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == -1)
		{
			if (buff)
				free(buff);
			if (storage)
				free(storage);
			return (NULL);
		}
		buff[count] = 0;
		storage = ft_strjoin(storage, buff);
	}
	free(buff);
	return (storage);
}

char	*ft_line(char *storage)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_next_line(char *storage)
{
	char	*next;
	int		i;
	int		j;
	size_t	storage_len;

	i = 0;
	j = 0;
	storage_len = ft_strlen(storage);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	next = ft_calloc((storage_len - i + 1), sizeof(char));
	if (!next)
		return (NULL);
	while (storage[++i])
		next[j++] = storage[i];
	next[j] = 0;
	free(storage);
	return (next);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage[fd] = ft_read_file(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = ft_line(storage[fd]);
	storage[fd] = ft_next_line(storage[fd]);
	return (line);
}
