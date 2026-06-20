/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:15:33 by codespace         #+#    #+#             */
/*   Updated: 2026/04/11 15:30:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *str, int c);

#endif