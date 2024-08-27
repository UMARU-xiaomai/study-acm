#include<bits/stdc++.h>
using namespace std;

#define MAXT 1005  // 将时间的最大值设置为 1005
int need_time[MAXT], value[MAXT];
int dp[MAXT];  // dp 数组大小也设置为 MAXT,指下标时间内能获得的最大权值
int t, m;

int main() {
    cin >> t >> m;
    for (int i = 0; i < m; i++) {
        cin >> need_time[i] >> value[i];
    }

    // 动态规划解决问题
    for (int i = 0; i < m; i++) {
        // 逆序遍历，以避免重复使用同一个草药
        for (int j = t; j >= need_time[i]; j--) {
            dp[j] = max(dp[j], dp[j - need_time[i]] + value[i]);
        }
    }

    cout << dp[t] << endl;
    return 0;
}
