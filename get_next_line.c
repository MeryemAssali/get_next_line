/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:17:00 by mel-assa          #+#    #+#             */
/*   Updated: 2026/06/22 17:23:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *leftover)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!leftover[i])
		return (NULL);
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (leftover[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = leftover[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*update_leftover(char *leftover)
{
	size_t	i;
	size_t	j;
	char	*stash;

	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (!leftover[i])
		return (free(leftover), NULL);
	i++;
	stash = malloc(ft_strlen(leftover) - i + 1);
	if (!stash)
		free(leftover);
	return (NULL);
	j = 0;
	while (leftover[i])
		stash[j++] = leftover[i++];
	stash[j] = '\0';
	free(leftover);
	return (stash);
}

char	*join_and_free(char *leftover, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(leftover, buffer);
	free(leftover);
	return (tmp);
}

char	*read_and_concatenate(int fd, char *leftover)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	leftover = init_leftover(leftover);
	if (!leftover)
		return (free(buffer), NULL);
	while (!ft_strchr(leftover, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read == -1)
			return (free(leftover), free(buffer), NULL);
		buffer[bytes_read] = '\0';
		leftover = join_and_free(leftover, buffer);
		if (!leftover)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = read_and_concatenate(fd, leftover);
	if (!leftover)
		return (NULL);
	line = extract_line(leftover);
	leftover = update_leftover(leftover);
	return (line);
}
