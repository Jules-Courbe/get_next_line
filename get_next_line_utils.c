/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrburns <mrburns@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:53:57 by mrburns           #+#    #+#             */
/*   Updated: 2026/11/12 17:22:08 by mrburns          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;

	len_dst = 0;
	j = 0;
	if (size == 0)
		return ;
	while (j < size && dst[j])
		j++;
	len_dst = j;
	if (len_dst == size)
		return ;
	i = 0;
	while (src[i] && i < size - len_dst - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = 0;
	len_s2 = 0;
	while (s1[len_s1])
		len_s1++;
	while (s2[len_s2])
		len_s2++;
	str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcat(str, s2, len_s1 + len_s2 + 1);
	return (str);
}

void	ft_strlcpy(char *dst, const char *src, int size)
{
	int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}

static char	*copy_rest(char *stash, int start)
{
	char	*rest;
	int		j;
	int		len;

	len = 0;
	while (stash[start + len])
		len++;
	rest = malloc(len + 1);
	if (!rest)
		return (NULL);
	j = 0;
	while (stash[start + j])
	{
		rest[j] = stash[start + j];
		j++;
	}
	rest[j] = '\0';
	return (rest);
}

char	*clear_stash(char *stash)
{
	int		i;
	char	*rest;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i] || !stash[i + 1])
		return (free(stash), NULL);
	rest = copy_rest(stash, i + 1);
	free(stash);
	return (rest);
}
