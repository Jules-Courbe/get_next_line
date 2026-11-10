/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrburns <mrburns@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 20:04:05 by mrburns           #+#    #+#             */
/*   Updated: 2026/11/10 20:04:08 by mrburns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 11
# endif 

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

// char	*ft_strchr(const char *s, int c);
void	ft_strlcpy(char *dst, const char *src, int size);
char	*ft_strjoin(char *stash, char *buf);
void	ft_strlcat(char *dst, char *src, size_t size);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*clear_stash(char *stash);
size_t	new_stash(char *stash);

#endif 
