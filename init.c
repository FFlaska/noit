#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("welcome to noit! Itll be a long wait. Waiting...\n");
    fflush(stdout);

    for (;;) {
        pause();
    }
}
