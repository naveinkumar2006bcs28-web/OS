#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int p2, p3, p4, p5;

    p2 = fork();

    if (p2 == -1) {
        printf("Process p2 not created\n");
    } else if (p2 == 0) {
        printf("p2 child %d parent %d\n", getpid(), getppid());
    } else {
        p3 = fork();

        if (p3 == -1) {
            printf("Process p3 not created\n");
        } else if (p3 == 0) {
            p4 = fork();

            if (p4 == -1) {
                printf("Process p4 not created\n");
            } else if (p4 == 0) {
                printf("p4 child %d parent %d\n", getpid(), getppid());
            } else {
                p5 = fork();

                if (p5 == -1) {
                    printf("Process p5 not created\n");
                } else if (p5 == 0) {
                    printf("p5 child %d parent %d\n", getpid(), getppid());
                } else {
                    wait(NULL);
                    wait(NULL);
                    printf("p3 child %d parent %d\n", getpid(), getppid());
                }
            }
        } else {
            wait(NULL);
            wait(NULL);
            printf("p1 child %d parent %d\n", getpid(), getppid());
        }
    }

    return 0;
}

