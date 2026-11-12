/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucourbe <jucourbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:53:57 by mrburns           #+#    #+#             */
/*   Updated: 2026/11/12 15:15:04 by jucourbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
	return ;
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
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
	i = 0;
	while (src[i])
		i++;
	return ;
}

size_t	calcul_stash(char *stash)
{
	size_t	res;
	int		i;

	i = 0;
	if (!stash)
		return (0);
	res = 0;
	res = ft_strlen(stash); // nb de caractere sans '\0'
	while (stash[i] && stash[i] != '\n')
	{
		i++;
	}
	if (stash[i] == '\n')
		res -= i - 1;
	else
		res -= i;
	return (res);
}

char	*clear_stash(char *stash)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	rest = malloc(ft_strlen(stash) - i);	/* len - (i + 1) + 1 */
	if (!rest)
		return (free(stash), NULL);
	i++;
	j = 0;
	while (stash[i])
		rest[j++] = stash[i++];
	rest[j] = '\0';
	free(stash);
	return (rest);
}

