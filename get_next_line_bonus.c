/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:50:52 by ihajouji          #+#    #+#             */
/*   Updated: 2024/01/17 21:47:10 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_result(char *result, int fd)
{
	int		byte;
	char	*buffer;
	char	*tmp;

	byte = 1;
	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free(result));
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	while (byte > 0 && !ft_strchr(buffer, '\n'))
	{
		byte = read (fd, buffer, BUFFER_SIZE);
		if (byte < 0)
			return (ft_free(result));
		if (byte == 0)
			break ;
		buffer[byte] = '\0';
		tmp = ft_strjoin(result, buffer);
		free(result);
		if (!tmp)
			return (ft_free(buffer));
		result = tmp;
	}
	free (buffer);
	return (result);
}

char	*ft_line(char *result)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	while (result[i] && result[i] != '\n')
		i++;
	if (result[i] == '\n')
		line = malloc (i + 2);
	else
		line = malloc (i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (result[i] && result [i] != '\n')
	{
		line[i] = result[i];
		i++;
	}
	if (result[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_remainder(char *result)
{
	char	*stash;
	int		i;
	int		j;

	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (result[i] != '\n' && result[i])
		++i;
	if (!result[i])
	{
		free(result);
		return (NULL);
	}
	stash = malloc((ft_strlen(result) - i + 1));
	if (stash)
	{
		while (result[++i])
			stash[j++] = result[i];
		stash[j] = '\0';
	}
	free(result);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*result[1024];
	char		*line;

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		result[fd] = ft_free(result[fd]);
		return (NULL);
	}
	result[fd] = get_result(result[fd], fd);
	if (!result[fd])
		return (NULL);
	line = ft_line(result[fd]);
	if (!line || !*line)
	{
		line = ft_free(line);
		result[fd] = ft_free(result[fd]);
		return (NULL);
	}
	result[fd] = get_remainder(result[fd]);
	return (line);
}
