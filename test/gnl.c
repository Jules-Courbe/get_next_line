#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 42

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

char	*bonjour(int fd)
{
	static char	*stash;
	char		*buf;
	int			ret;
	char		*res;

	ret = 1;
	res = NULL;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!stash || check_n(stash) == 0) // On boucle tant que stash est NULL ou que stash na pas de '\n' trouver
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		stash = ft_strjoin(stash, buf);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		else if (ret == 0)
		{
			res = stash;
			free(stash);
			return (NULL);
		}
	}
	res = find_n(&stash); // je retourne jusqu a '\n' && res est malloc dans la fonction
	stash = clear_stash(stash); // je retire ce qui a ete ecrit et garde si il y a un reste avec un '\n'
	return (res);
}
