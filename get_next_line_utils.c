/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:12:35 by mel-assa          #+#    #+#             */
/*   Updated: 2026/06/22 17:24:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*ptr;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count * size)
		ptr[i++] = 0;
	return ((void *)ptr);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((unsigned char)str[i] == (unsigned char)c)
		return ((char *)&str[i]);
	return (NULL);
}

size_t	ft_strlen(const char *stn)
{
	size_t	i;

	i = 0;
	while (stn[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*stn;
	size_t	i;
	size_t	j;

	if (!str1 || !str2)
		return (NULL);
	stn = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!stn)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		stn[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		stn[i + j] = str2[j];
		j++;
	}
	stn[i + j] = '\0';
	return (stn);
}

char	*init_leftover(char *leftover)
{
	if (!leftover)
	{
		leftover = ft_calloc(1, sizeof(char));
		if (!leftover)
			return (NULL);
	}
	return (leftover);
}
