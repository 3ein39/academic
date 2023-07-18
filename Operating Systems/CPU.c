// a simple main function that prints hello world

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <wait.h>
#include <unistd.h>

// assume we run on a single 1 core machine
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: cpu <string>\n");
        exit(1);
    }
    char *str = argv[1];
    while (1) {
         for (int i = 0; i < 100000000; i++) {
         }

        printf("%s\n", str);
    }
    return 0;
}
//prompt> gcc -o cpu cpu.c -Wall
//prompt> ./cpu A & ./cpu B & ./cpu C & ./cpu D
// terminal output will be

//A
//B
//C
//D
//A
//B
//C
//D...