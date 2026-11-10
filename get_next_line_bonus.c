/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrburns <mrburns@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 20:04:19 by mrburns           #+#    #+#             */
/*   Updated: 2026/11/10 20:09:31 by mrburns          ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*buf;
	int			ret;
	char		*res;
	char 		*tmp;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	res = NULL;
	ret = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (!stash[fd])
	{
		stash[fd] = malloc(1);
		if (!stash[fd])
		{
			free(buf);
			return (NULL);
		}
		stash[fd][0] = '\0';
	}
	// probleme avec ret qui se remet toujours en positif 
	while (check_n(stash[fd]) == 0 && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			free(stash[fd]);
			stash[fd] = NULL;
			return (NULL);
		}
		buf[ret] = '\0';
		tmp = ft_strjoin(stash[fd], buf);
		if (!tmp)
		{
			free(buf);
			free(stash[fd]);
			stash[fd] = NULL;
			return (NULL);
		}
		stash[fd] = tmp;
	}
	free(buf);
	res = find_n(stash[fd]); // je retourne jusqu a '\n' && res est malloc dans la fonction
	stash[fd] = clear_stash(stash[fd]); // je retire ce qui a ete ecrit et garde si il y a un reste avec un '\n'
	return (res);
}
