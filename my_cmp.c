#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main ( int argc, char *argv[] ){
if (argc!=3){
	printf("Error en el nombre d'arguments");
	exit(-1);
}
int fd1 = open(argv[1], O_RDONLY);
if (fd1 == -1) {
    perror("Error obrint l'arxiu");
    exit(-1);
}
int fd2 = open(argv[2], O_RDONLY);
if (fd2 == -1) {
    perror("Error obrint l'arxiu");
    exit(-1);
}
char buf1;
char buf2;
ssize_t i=1;
ssize_t j=1;
int byte=1;
int linia=1;
while (i>0 && j>0){
	i= read(fd1, &buf1, 1);
	j= read(fd2, &buf2, 1);
	if (i == -1 || j == -1) {
		perror("Error llegint els arxius");
		close(fd1);
		close(fd2);
		exit(-1);
}
	if (i == 0 || j == 0) {
		break;
}
	if (buf1!=buf2){
		printf("Diferencia al byte %d, a la linia %d\n",byte,linia);
		break;
}
	byte++;
	if (buf1=='\n'){
		linia++;
}
}
close(fd1);
close(fd2);
}
