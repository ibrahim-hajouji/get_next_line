/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:19:58 by ihajouji          #+#    #+#             */
/*   Updated: 2024/01/02 15:39:19 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;
	
	i = 0;
	if (!s)
		return 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	int i = 0;
	char *str;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			((char *)s)[i + 1] = '\0'; 
			return ((char *)s);
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;
	size_t	result_len;

	i = 0;
	j = 0;

	result_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(sizeof(char) * (result_len));
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
