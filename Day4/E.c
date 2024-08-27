#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int r, c;
char **city_map;
int start[2];
int **directions;
int ***mem;
int n;

void DFS(int x, int y, int cur_direct);

int main() {
    scanf("%d %d", &r, &c);
    city_map = (char **)malloc(r * sizeof(char *));
    for (int i = 0; i < r; i++) {
        city_map[i] = (char *)malloc((c + 1) * sizeof(char));
        scanf("%s", city_map[i]);
        for (int j = 0; j < c; j++) {
            if (city_map[i][j] == '*') {
                start[0] = i;
                start[1] = j;
                city_map[i][j] = '.';
            }
        }
    }

    scanf("%d", &n);
    mem = (int ***)malloc(r*sizeof(int **));
    for (int i = 0; i < r; i++) {
        mem[i] = (int **)malloc(c*sizeof(int *));
        for (int k = 0;k<c; k++)
        {
            mem[i][k] = (int*)malloc(n*sizeof(int));
            for (int j = 0;j<n;j++)
            {
                mem[i][k][j] = 0;
            }
        }
    }
    directions = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        directions[i] = (int *)malloc(2 * sizeof(int));
        char cur_dir[6];
        scanf("%s", cur_dir);
        if (strcmp(cur_dir, "NORTH") == 0) {
            directions[i][0] = -1;
            directions[i][1] = 0;
        } else if (strcmp(cur_dir, "SOUTH") == 0) {
            directions[i][0] = 1;
            directions[i][1] = 0;
        } else if (strcmp(cur_dir, "WEST") == 0) {
            directions[i][0] = 0;
            directions[i][1] = -1;
        } else if (strcmp(cur_dir, "EAST") == 0) {
            directions[i][0] = 0;
            directions[i][1] = 1;
        }
    }

    DFS(start[0], start[1], 0);

    for (int i = 0; i < r; i++) {
        printf("%s\n", city_map[i]);
        free(city_map[i]);
    }
    free(city_map);
    for (int i = 0; i < n; i++) {
        free(directions[i]);
    }
    free(directions);

    return 0;
}

void DFS(int x, int y, int cur_direct) {
    if (cur_direct >= n ) {
        return;
    }
    int dx = directions[cur_direct][0];
    int dy = directions[cur_direct][1];
    int nx = x, ny = y;
    if (cur_direct == n - 1) {
        while (0 <= nx + dx && nx + dx < r && 0 <= ny + dy && ny + dy < c && city_map[nx + dx][ny + dy] != 'X') {
            nx += dx;
            ny += dy;
            city_map[nx][ny] = '*';
        }
        return;
    }
    while (0 <= nx + dx && nx + dx < r && 0 <= ny + dy && ny + dy < c && city_map[nx + dx][ny + dy] != 'X') {
        nx += dx;
        ny += dy;
        if (mem[nx][ny][cur_direct+1]==0)
        {
            mem[nx][ny][cur_direct+1]=1;
            DFS(nx, ny, cur_direct+1);
        }
        // DFS(nx, ny, cur_direct + 1);
    }
} 
