#include <stdio.h>
#include <stdlib.h>

int* happiness;
int** adj;
int* adj_sizes;
int** dp;

void DFS(int i, int n) {
    if (dp[i][0] != -1 && dp[i][1] != -1) {
        return;
    }

    // 不参加宴会的情况
    int not_go = 0;
    for (int j = 0; j < adj_sizes[i]; j++) {
        int v = adj[i][j];
        DFS(v, n);
        not_go += (dp[v][0] > dp[v][1]) ? dp[v][0] : dp[v][1];
    }

    // 参加宴会的情况
    int go = happiness[i];
    for (int j = 0; j < adj_sizes[i]; j++) {
        int v = adj[i][j];
        DFS(v, n);
        go += dp[v][0];
    }

    dp[i][0] = not_go;
    dp[i][1] = go;
}

int main() {
    int n;
    scanf("%d", &n);

    happiness = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &happiness[i]);
    }

    adj = (int**)malloc(n * sizeof(int*));
    adj_sizes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        adj_sizes[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int l, k;
        scanf("%d %d", &l, &k);
        adj[k - 1] = (int*)realloc(adj[k - 1], (adj_sizes[k - 1] + 1) * sizeof(int));
        adj[k - 1][adj_sizes[k - 1]] = l - 1;
        adj_sizes[k - 1]++;
    }

    dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(2 * sizeof(int));
        dp[i][0] = -1;
        dp[i][1] = -1;
    }

    int root = 0;
    for (int i = 0; i < n; i++) {
        int is_root = 1;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < adj_sizes[j]; k++) {
                if (adj[j][k] == i) {
                    is_root = 0;
                    break;
                }
            }
            if (!is_root) break;
        }
        if (is_root) {
            root = i;
            break;
        }
    }

    DFS(root, n);

    int max_happiness = (dp[root][0] > dp[root][1]) ? dp[root][0] : dp[root][1];
    printf("%d\n", max_happiness);

    for (int i = 0; i < n; i++) {
        free(adj[i]);
        free(dp[i]);
    }
    free(adj);
    free(adj_sizes);
    free(dp);
    free(happiness);

    return 0;
}