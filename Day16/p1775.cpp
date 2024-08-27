#include <bits/stdc++.h>
using namespace std;

#define MAXN 303
#define INF INT_MAX

int n;
int dp[MAXN][MAXN];
int leaps[MAXN];

int dfs(int l, int r) {
    if (l > r) return 0;
    if (l == r) return 0; // 当只有一堆石子时，没有合并代价
    if (dp[l][r] != INF) return dp[l][r];
    
    // 计算区间 [l, r] 的总质量
    int total = leaps[r] - (l > 1 ? leaps[l - 1] : 0);
    
    for (int k = l; k < r; k++) {
        dp[l][r] = min(dp[l][r], dfs(l, k) + dfs(k + 1, r) + total);
    }
    
    return dp[l][r];
}

int main() {
    cin >> n;
    
    leaps[0] = 0;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        leaps[i] = leaps[i - 1] + tmp;
    }
    
    // 初始化DP数组为无穷大
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = INF;
        }
    }
    
    cout << dfs(1, n) << endl;
    return 0;
}
