#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int main(int argc, char **argv) {

    if(argc == 4) {

        int fd = open(argv[1], O_RDONLY);

        if(fd == -1) {
            fprintf(stderr, "Input file not found.\n");
            exit(EXIT_FAILURE);
        }

        char b = 0;
        int index = 0;

        while(read(fd, &b, 1)) {

            if(b == argv[2][index]) {
                ++index;
            }
            else {
                if(index > 0) {

                    off_t o = lseek(fd, 0, SEEK_CUR);
                    lseek(fd, o-index-1, SEEK_SET);
                    
                    while(index > 0) {
                        read(fd, &b, 1);
                        fprintf(stdout, "%c", b);
                        --index;
                    }
                }
                else {
                    fprintf(stdout, "%c", b);
                }
            }
            if(argv[2][index] == 0) {
                fprintf(stdout, "%s", argv[3]);
                index = 0;
            }
        }
        close(fd);
    }
    else {
        fprintf(stdout, "Usage: fr <file> 'from' 'to'\n");
        fprintf(stdout, "Example: ./fr main.c while 'HELLO WORLD!' > out.c\n");
    }
    exit(EXIT_SUCCESS);
}
