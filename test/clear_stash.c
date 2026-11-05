#include <stdlib.h>
#include <stdio.h>

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
size_t	reste_stash(char *stash)
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
	res -= (i - 1);
	return (res);
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

char	*clear_stash(char *stash)
{
	char 	*new_stash;
	int		i;
	int		rest_len;

	i = 0;
	if (stash[i] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	rest_len = reste_stash(stash);
	new_stash = malloc(sizeof(char) * rest_len + 1);
	if (!new_stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
	{
		i++;
	}
	ft_strlcpy(new_stash, &stash[i + 1], rest_len);
	return (new_stash);
}

int main()
{
	char stash[15] = "Hello ca";
	printf("%s\n", clear_stash(stash));
}