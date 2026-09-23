#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd[2], pid;
    int num[2];
    int a, b, x, y, temp, gcd, lcm;

    pipe(fd);

    pid = fork();

    if(pid > 0)              // Parent
    {
        close(fd[0]);

        printf("Enter two numbers: ");
        scanf("%d %d", &num[0], &num[1]);

        write(fd[1], num, sizeof(num));

        close(fd[1]);
    }

    else if(pid == 0)        // Child
    {
        close(fd[1]);

        read(fd[0], num, sizeof(num));

        a = num[0];
        b = num[1];

        x = a;
        y = b;

        while(y != 0)
        {
            temp = y;
            y = x % y;
            x = temp;
        }

        gcd = x;
        lcm = (a * b) / gcd;

        printf("GCD = %d\n", gcd);
        printf("LCM = %d\n", lcm);

        close(fd[0]);
    }

    return 0;
}
