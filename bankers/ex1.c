#include <stdio.h>
#include <stdbool.h>

struct Task
{
    int alloc[10];
    int max[10];
    int need[10];
    int done;
};

int main()
{
    int n, r;
    int i, j;

    printf("Enter number of taskes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &r);

    struct Task task[10];

    int avail[10];
    int work[10];
    int order[10];

    /* Enter Allocation Matrix */
    printf("\nEnter Allocation Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d", &task[i].alloc[j]);
        }
    }

    /* Enter Maximum Matrix */
    printf("\nEnter Maximum Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d", &task[i].max[j]);
        }
    }

    /* Enter Available Resources */
    printf("\nEnter Available Resources:\n");

    for (j = 0; j < r; j++)
    {
        scanf("%d", &avail[j]);
        work[j] = avail[j];
    }

    /* Calculate Remaining Need */
    for (i = 0; i < n; i++)
    {
        task[i].done = 0;

        for (j = 0; j < r; j++)
        {
            task[i].need[j] =
                task[i].max[j] -
                task[i].alloc[j];
        }
    }

    int count = 0;

    /* Banker's Algorithm */
    while (count < n)
    {
        bool found = false;

        for (i = 0; i < n; i++)
        {
            if (task[i].done == 0)
            {
                bool canRun = true;

                for (j = 0; j < r; j++)
                {
                    if (task[i].need[j] > work[j])
                    {
                        canRun = false;
                        break;
                    }
                }

                if (canRun)
                {
                    for (j = 0; j < r; j++)
                    {
                        work[j] += task[i].alloc[j];
                    }

                    order[count] = i;
                    task[i].done = 1;

                    count++;
                    found = true;
                }
            }
        }

        if (!found)
        {
            break;
        }
    }

    /* Display Remaining Need Matrix */
    printf("\n====================================\n");
    printf("        NEED MATRIX\n");
    printf("====================================\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d : ", i);

        for (j = 0; j < r; j++)
        {
            printf("%d ", task[i].need[j]);
        }

        printf("\n");
    }

    /* Check Safe State */
    printf("\n====================================\n");

    if (count == n)
    {
        printf("System Status : SAFE STATE\n");

        printf("Safe Sequence : ");

        for (i = 0; i < n; i++)
        {
            printf("P%d", order[i]);

            if (i != n - 1)
            {
                printf(" -> ");
            }
        }

        printf("\n");
    }
    else
    {
        printf("System Status : UNSAFE STATE\n");
    }

    printf("====================================\n");

    return 0;
}
