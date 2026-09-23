#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>

int main() {
    pid_t p1, p3;
    char str[100];
    int i;
    printf("P1 Enter a String: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    p1 = fork();

    if (p1 < 0) {
        perror("Fork failed");
        return 1;
    }

    if (p1 == 0) {

        int vowels = 0;
        for (i = 0; str[i] != '\0'; i++) {
            char ch = tolower((unsigned char)str[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            }
        }
        printf("No of Vowels: %d\n", vowels);
    }
    else {
        p3 = fork();

        if (p3 < 0) {
            perror("Fork failed");
            return 1;
        }

        if (p3 == 0) {

            int special = 0;
            for (i = 0; str[i] != '\0'; i++) {
                if (!isalnum((unsigned char)str[i]) && !isspace((unsigned char)str[i])) {
                    special++;
                }
            }
            printf("No of special Characters: %d\n", special);
        }
        else {
            wait(NULL);
            wait(NULL);
        }
    }
    return 0;
}

[24bcs053@mepcolinux ex1]$./ex3
P1 Enter a String: Navein@123
No of Vowels: 3
No of special Characters: 1
[24bcs053@mepcolinux ex1]$./ex3
P1 Enter a String: JohnMarston@1976
No of Vowels: 3
No of special Characters: 1
[24bcs053@mepcolinux ex1]$./ex3
P1 Enter a String: Arthur@3@@@
No of Vowels: 2
No of special Characters: 4
[24bcs053@mepcolinux ex1]$exit
exit

Script done on Wednesday 22 July 2026 02:26:16 PM IST
