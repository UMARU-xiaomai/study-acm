#include <bits/stdc++.h>
using namespace std;

#define MAXN 52
int m, n;
int loveness[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> loveness[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));//批量设置值

    for (int x1 = 1; x1 <= m; x1++) {
        for (int y1 = 1; y1 <= n; y1++) {
            for (int x2 = 1; x2 <= m; x2++) {
                int y2 = x1 + y1 - x2;// 一个规律：x1+y1=x2+y2
                if (y2 < 1 || y2 > n) continue;

                int value = loveness[x1][y1];
                if (x1 != x2) value += loveness[x2][y2];

                dp[x1][y1][x2][y2] = max({
                    dp[x1-1][y1][x2-1][y2],
                    dp[x1-1][y1][x2][y2-1],
                    dp[x1][y1-1][x2-1][y2],
                    dp[x1][y1-1][x2][y2-1]
                }) + value;
            }
        }
    }

    cout << dp[m][n][m][n] << endl;
    return 0;
}
