
#include <stdio.h>

#define MAX 20
#define INF 10000000

int n, d[MAX][MAX];

// Floyd-Warshall Algorithm
void floyd()
{
    int i, j, k;

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (d[i][k] != INF && d[k][j] != INF &&
                    d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

// Display shortest distance matrix
void display()
{
    int i, j;

    printf("\nAll-Pairs Shortest Distance Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (d[i][j] == INF)
                printf("%8s", "INF");
            else
                printf("%8d", d[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of vertices!");
        return 0;
    }

    printf("\nEnter cost matrix (use %d for INF):\n", INF);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (scanf("%d", &d[i][j]) != 1)
            {
                printf("Invalid input!");
                return 0;
            }
        }
    }

    // Apply Floyd-Warshall Algorithm
    floyd();

    // Display result
    display();

    // Check for negative cycle
    for (i = 0; i < n; i++)
    {
        if (d[i][i] < 0)
        {
            printf("\nNegative weight cycle detected!");
            return 0;
        }
    }

    printf("\nNo negative weight cycle detected.");

    return 0;
}
