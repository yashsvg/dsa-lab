#include <stdio.h>

#define MAX 10

int adj[MAX][MAX], visited[MAX], queue[MAX];
int front = 0, rear = 0;

void bfs(int start, int n) {
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n = 4;

    // Example graph
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;

    bfs(0, n);

    return 0;
}