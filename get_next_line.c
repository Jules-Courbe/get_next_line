



#include "get_next_line_utils.h"


// apprendre a utiliser les variables statiques 

// apprendre a utiliser la fonction read 

// fichier free 

// En cas d erreur il faut retourner NULL / return le '\n' de chaque ligne sauf si la fin du fichier est atteinte sans '\n'

/*
Compilation avec -D BUFFER_SIZE=n (taille du buffer de read()), mais 
le projet doit aussi compiler sans ce flag, avec une valeur par défaut au choix.
Lire le minimum possible à chaque appel : ne pas lire tout le fichier puis le découper.
Tester avec des valeurs extrêmes de BUFFER_SIZE (1, 9999, 10000000).
Comportement indéfini si le fichier est modifié entre deux appels ou si c’est un fichier binaire.

Interdit : libft, lseek(), variables globales.
*/

void	read_file(char **argv)
{
	
}

char *get_next_line(int fd)
{
	printf("hello");
	write(fd, "e", 1);

	return (NULL);
}