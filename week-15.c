
#include <stdio.h>

#define MAX 20
#define INF 10000000

int n, cost[MAX][MAX];

// Dijkstra's Algorithm
void dijkstra(int src, int dest)
{
    int dist[MAX], prev[MAX], visited[MAX];
    int i, count, u, v, min;

    // Initialize arrays
    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
        prev[i] = -1;
        visited[i] = 0;
    }

    dist[src] = 0;

    // Find shortest paths
    for (count = 0; count < n; count++)
    {
        min = INF;
        u = -1;

        // Find unvisited vertex with minimum distance
        for (i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        // Stop if remaining vertices are unreachable
        if (u == -1)
            break;

        visited[u] = 1;

        // Update adjacent vertices
        for (v = 0; v < n; v++)
        {
            if (cost[u][v] > 0 && !visited[v] &&
                dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = dist[u] + cost[u][v];
                prev[v] = u;
            }
        }
    }

    // Check whether destination is reachable
    if (dist[dest] == INF)
    {
        printf("\nNo path from %d to %d", src, dest);
        return;
    }

    printf("\nShortest distance from %d to %d = %d",
           src, dest, dist[dest]);

    // Reconstruct shortest path
    int path[MAX], len = 0;

    for (v = dest; v != -1; v = prev[v])
    {
        path[len++] = v;
    }

    printf("\nShortest Path: ");

    for (i = len - 1; i >= 0; i--)
    {
        printf("%d", path[i]);

        if (i > 0)
            printf(" -> ");
    }

    printf("\n");
}

int main()
{
    int i, j, src, dest;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of nodes!");
        return 0;
    }

    printf("\nEnter cost matrix (0 = no edge):\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] < 0)
            {
                printf("Dijkstra's algorithm does not support negative edges!");
                return 0;
            }
        }
    }

    printf("\nEnter start node and end node (0 to %d): ", n - 1);
    scanf("%d %d", &src, &dest);

    if (src < 0 || src >= n || dest < 0 || dest >= n)
    {
        printf("Invalid source or destination!");
        return 0;
    }

    dijkstra(src, dest);

    return 0;
}
