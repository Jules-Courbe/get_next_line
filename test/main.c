#include "get_next_line.h"

int    main(int ac, char **av)
{
    int        fd[2];
    char    *line[2];

    if (ac != 3)
        return (1);
    fd[0] = open(av[1], O_RDONLY);
    fd[1] = open(av[2], O_RDONLY);
    if (fd[0] < 0 || fd[1] < 0)
    {
        if (fd[0] >= 0)
            close(fd[0]);
        if (fd[1] >= 0)
            close(fd[1]);
        return (1);
    }
    line[0] = get_next_line(fd[0]);
	line[1] = get_next_line(fd[1]);

	printf("%s", line[0]);
	printf("%s", line[1]);
	line[0] = get_next_line(fd[0]);
	printf("%s", line[0]);
    return (0);
}

/*
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int i = 0;

	if (argc != 2)
	{
		write(2, "Usage: ./gnl fichier\n", 21);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	while ( i < 6)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;	
	}
	close(fd);
	return (0);
}*/
