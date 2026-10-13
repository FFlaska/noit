#include <stdio.h>
#include <unistd.h>

int main(void) {
    if (getpid() != 1) {
        fprintf(stderr, "NOT PID 1. Dying!");
        return 1;
    }
    
    printf("welcome to noit! Itll be a long wait. Waiting...\n");
    fflush(stdout);

    for (;;) {
        pause();
    }
    return 0;
}
