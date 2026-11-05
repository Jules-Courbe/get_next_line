/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrburns <mrburns@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:30:25 by mrburns           #+#    #+#             */
/*   Updated: 2026/11/05 10:56:39 by mrburns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif 

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

// char	*ft_strchr(const char *s, int c);
void	ft_strlcpy(char *dst, const char *src, int size);
char	*ft_strjoin(char *s1, char *s2);
void	ft_strlcat(char *dst, char *src, size_t size);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*clear_stash(char *stash);
size_t	new_stash(char *stash);
void	ft_strlcat(char *dst, char *src, size_t size);

#endif 