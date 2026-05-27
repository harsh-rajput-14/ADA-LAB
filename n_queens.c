#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x[20], count = 1;

int place(int k, int j)
{
    int i;

    for(i = 1; i < k; i++)
    {
        if(x[i] == j || abs(x[i] - j) == abs(i - k))
            return 0;
    }

    return 1;
}

void queens(int k, int n)
{
    int i, j;

    for(j = 1; j <= n; j++)
    {
        if(place(k, j))
        {
            x[k] = j;

            if(k == n)
            {
                printf("\nSolution %d\n", count++);

                for(i = 1; i <= n; i++)
                    printf("%d row <---> %d column\n", i, x[i]);
            }
            else
            {
                queens(k + 1, n);
            }
        }
    }
}

int main()
{
    int n;

    printf("Enter number of queens: ");
    scanf("%d", &n);

    queens(1, n);

    return 0;
}
