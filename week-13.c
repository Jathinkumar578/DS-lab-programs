
#include <stdio.h>

#define MAX 20

int n, adj[MAX][MAX], visited[MAX];

// Breadth First Search (BFS)
void bfs(int s)
{
    int q[MAX], f = 0, r = 0;
    int u, v;

    for (v = 0; v < n; v++)
        visited[v] = 0;

    visited[s] = 1;
    q[r++] = s;

    while (f < r)
    {
        u = q[f++];

        printf("%d ", u);

        for (v = 0; v < n; v++)
        {
            if (adj[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                q[r++] = v;
            }
        }
    }
}

// Depth First Search (DFS)
void dfs(int u)
{
    int v;

    visited[u] = 1;

    printf("%d ", u);

    for (v = 0; v < n; v++)
    {
        if (adj[u][v] == 1 && visited[v] == 0)
        {
            dfs(v);
        }
    }
}

int main()
{
    int i, j, s;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of cities!");
        return 0;
    }

    printf("Enter adjacency matrix (%d x %d):\n", n, n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);

            if (adj[i][j] != 0 && adj[i][j] != 1)
            {
                printf("Invalid adjacency matrix!");
                return 0;
            }
        }
    }

    printf("Enter starting node (0 to %d): ", n - 1);
    scanf("%d", &s);

    if (s < 0 || s >= n)
    {
        printf("Invalid starting node!");
        return 0;
    }

    // BFS Traversal
    printf("\nNodes reachable using BFS: ");
    bfs(s);

    // Reset visited array
    for (i = 0; i < n; i++)
        visited[i] = 0;

    // DFS Traversal
    printf("\nNodes reachable using DFS: ");
    dfs(s);

    printf("\n");

    return 0;
}
