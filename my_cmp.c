#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main ( int argc, char *argv[] ){
        if (argc < 2)
        {
                perror("Error: No s'ha proporcionat cap nom de fitxer.\n");
                exit(-1);
        }
	if (argc < 3)
	{
		perror("Error: Es necessiten dos noms de fitxers.\n");
	}

        int fd_arxiu_1 = open(argv[1], O_RDONLY;
        if (fd_arxiu_1 < 0)
        {
                perror("Error: No s'ha trobat el fitxer.\n");
                exit(-1);
        }

        int fd_arxiu_2 = open(argv[2], O_RDONLY;
        if (fd_arxiu_2 < 0)
        {
                perror("Error: No s'ha trobat el fitxer.\n");
                exit(-1);
        }

	int i = 0;
	char buffer[i];

        fread(buffer, sizeof(char), i, fd_arxiu_1);


        close(fd_arxiu_1);
	close(fd_arxiu_2);
        return 0;
}
