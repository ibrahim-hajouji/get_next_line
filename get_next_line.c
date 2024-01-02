/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 20:32:19 by ihajouji          #+#    #+#             */
/*   Updated: 2024/01/02 16:01:39 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char *get_result(char *result, int fd)
{
	int 	byte;
	char	*buffer;
	
	byte = 1;
	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);

	while (byte == read (fd, buffer, BUFFER_SIZE) > 0 && ft_strchr(buffer, '\n'))
	{
		buffer[byte] = '\0';
		result = ft_strjoin(result, buffer);
	}
		free (buffer);
		return (result);
}

char	*get_line(char *result)
{
	char *line;
	int i;
	
	i = 0;
	while (result[i] && result[i] != '\n')
		i++;
	line = malloc (i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (result[i] && result[i] != '\n')
	{
		line[i] = result[i];
		i++;
	}
	if (result [i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*result = NULL;
	char	*line;
	int		byte;
	int 	i;
	
	i = 0;
	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	result = get_result(result, fd);
	if(!result)

		return (NULL);
	line = get_line(result);
	if (!line)
	{
		free (result);
		return (NULL);	
	}
	return (line);
}


int main()
{
	int fd = open("file.txt", O_RDONLY);
	char *str = get_next_line(fd);
	// while (str)
	// {
		printf("%s", str);
	// 	str = get_next_line(fd);
	// }
	return 0;
}
