#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Error: Es necessiten exactament dos noms de fitxers.\n");
        exit(-1);
    }

    int fd_arxiu_1 = open(argv[1], O_RDONLY);
    if (fd_arxiu_1 < 0) {
        perror("Error en obrir el primer fitxer");
        exit(-1);
    }

    int fd_arxiu_2 = open(argv[2], O_RDONLY);
    if (fd_arxiu_2 < 0) {
        perror("Error en obrir el segon fitxer");
        close(fd_arxiu_1);
        exit(-1);
    }

    char byte1, byte2;
    int posicio = 1, linia = 1;

    while (read(fd_arxiu_1, &byte1, 1) == 1 && read(fd_arxiu_2, &byte2, 1) == 1) {
        if (byte1 != byte2) {
            printf("Diferència trobada en la posició %d, línia %d\n", posicio, linia);
            close(fd_arxiu_1);
            close(fd_arxiu_2);
            return 0;
        }
        if (byte1 == '\n') {
            linia++;
            posicio = 0;
        }
        posicio++;
    }

    close(fd_arxiu_1);
    close(fd_arxiu_2);
    return 0;
}
