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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
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

char	*find_n(char *stash)
{
	char	*new_stash;
	int		len_line;

	len_line = 0;
	if (stash == NULL || stash[0] == '\0')
		return (NULL);
	while (stash[len_line] && stash[len_line] != '\n')
		len_line++;
	new_stash = malloc(sizeof(char) * (len_line + 1));
	if (!new_stash)
		return (NULL);
	ft_strlcpy(new_stash, stash, len_line + 1);
	return (new_stash);
}
int main()
{
	char	stash[15] = "hello \n jdke d5";
	printf("%s\n", find_n(stash));
}
