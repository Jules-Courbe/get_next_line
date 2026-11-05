#include <stdlib.h>
#include <stdio.h>


void	ft_strlcat(char *stash, char *buf, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;

	len_dst = 0;
	j = 0;
	i = 0;
	if (size == 0 || !size)
		return ;
	while (stash[j] && j < size)
		j++;
	len_dst = j;
	if (len_dst == size)
		return ;
	while (buf[i] && i < size - len_dst - 1)
	{
		stash[j] = buf[i];
		i++;
		j++;
	}
	stash[j] = '\0';
	return ;
}

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

char	*ft_strjoin(char *stash, char *buf)
{
	char	*new;

	new = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buf) + 1));
	if (!new)
		return (NULL);
	new[0] = '\0';
	ft_strlcat(new, stash, (ft_strlen(stash) + ft_strlen(buf) + 1));
	ft_strlcat(new, buf, (ft_strlen(stash) + ft_strlen(buf) + 1));
	free(stash);
	return (new);
}

int main()
{
	char buf[15] = "Hello ca\n j\n aq";
	char *stash;
	char *tmp;

	tmp = stash;
	stash = malloc(1);
	stash[0] = '\0';

	printf("%s\n", ft_strjoin(stash, buf));
}