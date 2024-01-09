/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 20:32:19 by ihajouji          #+#    #+#             */
/*   Updated: 2024/01/09 13:07:22 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *get_result(char *result, int fd)
{
	int 	byte;
	char	*buffer;
	char	*tmp;
	int		i;

	i = 0;
	byte = 1;
	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (byte > 0 && !ft_strchr(buffer, '\n'))
	{
		byte = read (fd, buffer, BUFFER_SIZE);
		if (byte < 0)
		{
			free(buffer);
			return (result);
		}
		buffer[byte] = '\0';
    	tmp = ft_strjoin(result, buffer);
    	free(result);
    	if (!tmp)
    	{
       		free(buffer);
        	return (NULL);
    	}
        result = tmp;
		
	}
		free (buffer);
		return (result);
}

static char	*get_line(char *result)
{
	char *line = NULL;
	int i;
	
	i = 0;
	while (result[i] && result[i] != '\n')
		i++;
	line = malloc (i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (result[i] && result [i] != '\n')
	{
		line[i] = result[i];
		i++;
	}
	if (result [i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*free_result(char *result)
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
	if (!result[i] || (result[i] == '\n' && result[i + 1] == '\0'))
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
	static char	*result;
	char	*line;

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	result = get_result(result, fd);
	if(!result)
		return (NULL);
	line = get_line(result);
	result = free_result(result);
	return (line);
}
 
int    main()
{
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        printf("%s", line);
        free(line);
    }
    return (0);
}