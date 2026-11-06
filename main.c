/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucourbe <jucourbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:35:19 by mrburns           #+#    #+#             */
/*   Updated: 2026/11/06 13:02:23 by jucourbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int    main(int ac, char **av)
{
    int        fd;
    char    *line;

    if (ac < 2)
    {
        printf("To few argument\n");
        return(0);
    }
    else
        fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        printf("Error fd\n");
        return (1);
    }
    line = get_next_line(fd);
    if (!line)
        return (0);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    free (line);
    close (fd);
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