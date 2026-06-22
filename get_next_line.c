/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:20:44 by codespace         #+#    #+#             */
/*   Updated: 2026/06/22 10:36:51 by codespace        ###   ########.fr       */
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
	if (!leftover[i]) // this condition checks if the leftover ended without finding \n
		return (free(leftover), NULL);
	i++; // if there is a newline, skip it
	stash = malloc(ft_strlen(leftover) - i + 1);
	if (!stash)
		return (NULL);
	j = 0;
	while (leftover[i])
		stash[j++] = leftover[i++];
	stash[j] = '\0';
	free(leftover);
	return (stash);
}
void ft_free()
{
	
}
char	*read_and_concatenate(int fd, char *leftover) // this function reads from the the fd and combines the read with the leftover stash
{
	char *buffer;
	char *tmp;
	ssize_t bytes_read;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	if (!leftover)
		leftover = ft_strdup("");
		if (!leftover)
			return (free(buffer), NULL);
	while (!ft_strchr(leftover, '\n')) // while you haven't found a newline in the leftover,
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE); // read from the fd into a buffer with BUFFER_SIZE. Reurns # of bytes read,0,-ve
		if (bytes_read == 0) // if you reach the end of file or there's an error, stop
			break ;
		else if (bytes_read == -1)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(leftover, buffer);
		if (!tmp)
			return(free(buffer), NULL);
		free(leftover);
		leftover = tmp;
	}
	free(buffer);
	return (leftover);
}
char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (line);
}
