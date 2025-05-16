#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int adj[MAX][MAX], visited[MAX], stack[MAX], top = -1, V;
void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < V; i++)
        if (adj[v][i] && !visited[i])
            dfs(i);
    stack[++top] = v;
}

void topologicalSort() {
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs(i);

    while (top >= 0)
        printf("%d ", stack[top--]);
    printf("\n");
}

int main() {
    int E, u, v;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v): \n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topologicalSort();
    return 0;
}
