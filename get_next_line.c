/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:20:44 by codespace         #+#    #+#             */
/*   Updated: 2026/05/16 10:20:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Extract line from buffer
char	*extract_line(char *leftover)
{
	char	*line;
	size_t i;

	i = 0;
	if (!leftover[i]) // if leftover is empty, return NULL
		return (NULL);
	while (leftover[i] && leftover[i] != '\n') // loop through the buffer until new line is found or you reach the end
		i++;
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
