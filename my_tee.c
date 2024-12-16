#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

//Problema 1
int main ( int argc, char *argv[] ){
	if (argc < 2)
	{
                perror("Error: No s'ha proporcionat cap nom de fitxer.\n");
                exit(-1);
	}

	int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
	{
		perror("Error: No s'ha trobat el fitxer.\n");
                exit(-1);
	}

	char c;

	while(read(STDIN_FILENO, &c, 1) > 0){
		if (write(fd, &c, 1) < 0)
		{
			perror("Error: No s'ha pogut escriure al fitxer.\n");
			exit(-1);
		}
	}
	close(fd);
	return 0;
}
