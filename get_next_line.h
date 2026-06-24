/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:19:17 by mel-assa          #+#    #+#             */
/*   Updated: 2026/06/24 17:40:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_and_concatenate(int fd, char *leftover);
char	*extract_line(char *leftover);
char	*update_leftover(char *leftover);
char	*join_and_free(char *leftover, char *buffer);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *stn);
char	*ft_strjoin(const char *str1, const char *str2);
char	*init_leftover(char *leftover);

#endif