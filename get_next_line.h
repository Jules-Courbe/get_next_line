/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrburns <mrburns@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:30:25 by mrburns           #+#    #+#             */
/*   Updated: 2026/11/12 16:36:22 by mrburns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11
# endif

# include <unistd.h>
# include <stdlib.h>

void	ft_strlcpy(char *dst, const char *src, int size);
char	*ft_strjoin(char *stash, char *buf);
void	ft_strlcat(char *dst, char *src, size_t size);
char	*get_next_line(int fd);
char	*clear_stash(char *stash);

#endif
