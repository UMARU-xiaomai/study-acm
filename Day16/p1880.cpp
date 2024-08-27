#include <bits/stdc++.h>
using namespace std;

#define MAXN 204
#define INF INT_MAX

int n;
int dp[MAXN][MAXN];
int leaps[MAXN];
int pre_leaps[MAXN];

int dfs_max(int l, int r) {
    if (l > r) return 0;
    if (l == r) return 0; // 当只有一堆石子时，没有合并代价
    if (dp[l][r] != 0) return dp[l][r];
    
    // 计算区间 [l, r] 的总质量
    int total = pre_leaps[r] - pre_leaps[l - 1];
    
    for (int k = l; k < r; k++) {
        dp[l][r] = max(dp[l][r], dfs_max(l, k) + dfs_max(k + 1, r) + total);
    }
    
    return dp[l][r];
}

int dfs_min(int l, int r) {
    if (l > r) return 0;
    if (l == r) return 0; // 当只有一堆石子时，没有合并代价
    if (dp[l][r] != INF) return dp[l][r];
    
    // 计算区间 [l, r] 的总质量
    int total = pre_leaps[r] - pre_leaps[l - 1];
    
    for (int k = l; k < r; k++) {
        dp[l][r] = min(dp[l][r], dfs_min(l, k) + dfs_min(k + 1, r) + total);
    }
    
    return dp[l][r];
}

int main() {
    cin >> n;
    
    pre_leaps[0] = 0;
    for (int i = 1; i <= n; i++) {
        
        cin >> leaps[i];
        pre_leaps[i] = pre_leaps[i - 1] + leaps[i];
    }
	for (int i = 1; i <= n; i++) {
		pre_leaps[i+n] = pre_leaps[n+i-1]+leaps[i];
		/*
		有一种更简单的方法：把原数组往后复制一遍。

以样例4 5 9 4为例，复制后得到：

4 5 9 4 4 5 9 4

i~j长度不能超过n

		*/
	}
    
    // 初始化DP数组为无穷大,求min
    for (int i = 1; i <= 2*n; i++) {
        for (int j = 1; j <= 2*n; j++) {
            dp[i][j] = INF;
        }
    }
    int ans = INF;
	for (int i = 1; i <= n; i++) {//遍历复制一遍的数组中长度为n的答案，取最值，
		ans = min(ans,dfs_min(i,i+n-1));
	}
    cout << ans<< endl;
	
	// 初始化DP数组为0,求max
    for (int i = 1; i <= 2*n; i++) {
        for (int j = 1; j <= 2*n; j++) {
            dp[i][j] = 0;
        }
    }
    ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans,dfs_max(i,i+n-1));
	}
    cout << ans<< endl;
    return 0;
}
