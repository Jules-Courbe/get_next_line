/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucourbe <jucourbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:52:17 by mrburns           #+#    #+#             */
/*   Updated: 2026/11/05 22:33:43 by jucourbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_n(char *stash)
{
	char	*new_stash;
	int		len_line;

	len_line = 0;
	if (stash == NULL || stash[0] == '\0')
		return (NULL);
	while (stash[len_line] && stash[len_line] != '\n')
		len_line++;
	new_stash = malloc(sizeof(char) * (len_line + 2));
	if (!new_stash)
		return (NULL);
	ft_strlcpy(new_stash, stash, len_line + 2);
	return (new_stash);
}
int		check_n(char *stash) // si stash ne contient pas \n je retourne 0
{
	int		i;

	i = 0;
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
	static char	*stash;
	char		*buf;
	int			ret;
	char		*res;

	res = NULL;
	ret = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!stash)
	{
		stash = malloc(1);
		stash[0] = '\0';
	}
	// probleme avec ret qui se remet toujours en positif 
	while ((check_n(stash) == 0) && ret != 0) // On boucle tant que stash est NULL ou que stash na pas de '\n' trouver
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		stash = ft_strjoin(stash, buf);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	res = find_n(stash); // je retourne jusqu a '\n' && res est malloc dans la fonction
	stash = clear_stash(stash); // je retire ce qui a ete ecrit et garde si il y a un reste avec un '\n'
	return (res);
}
