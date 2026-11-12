/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucourbe <jucourbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:52:17 by mrburns           #+#    #+#             */
/*   Updated: 2026/11/12 15:29:13 by jucourbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_n(char *stash)
{
	char	*new_stash;
	int		len_line;

	if (!stash || stash[0] == '\0')
		return (NULL);
	len_line = 0;
	while (stash[len_line] && stash[len_line] != '\n')
		len_line++;
	if (stash[len_line] == '\n')
		len_line++;
	new_stash = malloc(sizeof(char) * (len_line + 1));
	if (!new_stash)
		return (NULL);
	ft_strlcpy(new_stash, stash, len_line + 1);
	return (new_stash);
}
int		check_n(char *stash) // si stash ne contient pas \n je retourne 0
{
	int		i;

	i = 0;
	if (!stash)
		return(0);
	while(stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	update_stash(char **stash, char *buf)
{
	char	*tmp;

	if (!*stash)
	{
		*stash = malloc(1);
		if (!*stash)
			return (1);
		(*stash)[0] = '\0';
	}
	tmp = ft_strjoin(*stash, buf);
	if (!tmp)
		return (1);
	free(*stash);
	*stash = tmp;
	return (0);
}

int	join_buff_to_stash(char **stash, int fd, int ret)
{
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(*stash), *stash = NULL, 1);
	while (!check_n(*stash) && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (free(buf), free(*stash), *stash = NULL, 1);
		buf[ret] = '\0';
		if (ret == 0)
			break ;
		if (update_stash(stash, buf))
			return (free(buf), free(*stash), *stash = NULL, 1);
	}
	free(buf);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	if (join_buff_to_stash(&stash, fd, 1) == 1)
		return (NULL);
	if (!stash || stash[0] == '\0')
	return (free(stash), stash = NULL, NULL);
	res = find_n(stash);
	if (!res)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = clear_stash(stash);
	return (res);
}
