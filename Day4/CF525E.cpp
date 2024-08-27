#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

unordered_map<ll, ll> m[30];   // 使用了 unordered_map，比普通的 map 快，但这道题好像不卡 map？
// m[i][j] 代表用了 i 个阶乘符号，总和为 j 的方案数
int n, k;
ll ans;   // 答案开 long long 好习惯
ll s, a[30];
ll fac[30];

// 对前一半数字进行搜索
void dfs1(int cur = 1, int cnt = 0, ll sum = 0) {   // 当前处理到第 cur 个数字，用了 cnt 个阶乘符号，总和为 sum
	if (cur >= n / 2 + 1) {   // 当搜索的数字个数达到 n / 2 时，统计后退出搜索
		m[cnt][sum]++;
		return;
	}
	dfs1(cur + 1, cnt, sum);   // 不取当前数字
	if (sum + a[cur] <= s) dfs1(cur + 1, cnt, sum + a[cur]);   // 直接取当前数字
	if (a[cur] <= 19 && sum + fac[a[cur]] <= s && cnt < k) dfs1(cur + 1, cnt + 1, sum + fac[a[cur]]);   // 将当前数字变成其阶乘后再取
	// 这里要注意，由于 s <= 1e16，而 19！ 已经远大于 1e16，所以当当前数字大于19没有必要搜（而且再大的话 long long 也存不下）
	// 记得判断 cnt < k
	return;
}

// 将前半搜索完成的的信息储存到m(unordered_map)中，对后一半数字进行搜索
void dfs2(int cur = n / 2 + 1, int cnt = 0, ll sum = 0) {   // 同 dfs1
	if (cur >= n + 1) {
		// 这道题不要求用完所有的！
		// 所以当已经搜完了整个序列时，所有满足 i + cnt <= k 并且 j + sum = s 的 m[i][j] 都需要计入总数（将m（第一次搜索的结果）与第二次搜索的结果进行整合，查找答案）
		for (int i = 0 ; i + cnt <= k; i++) {
			if (m[i].count(s - sum))
				ans += m[i][s - sum];
		}
		return;
	}
	dfs2(cur + 1, cnt, sum);
	if (sum + a[cur] <= s) dfs2(cur + 1, cnt, sum + a[cur]);
	if (a[cur] <= 19 && sum + fac[a[cur]] <= s && cnt < k) dfs2(cur + 1, cnt + 1, sum + fac[a[cur]]);
	return;
}

void solve() {
	fac[0] = 1;
	for (int i = 1; i <= 19; i++) fac[i] = fac[i - 1] * i;   // 预处理阶乘
	dfs1(), dfs2();
	cout << ans << endl;
	return;
}

int main() {
	cin >> n >> k >> s;
	for (int i = 1; i <= n; i++) cin >> a[i];
	solve();
	return 0;
}
            /*（1）如果你需要高效的随即存取，而不在乎插入和删除的效率，使用vector
             （2）如果你需要大量的插入和删除，而不关心随机存取，则应使用list
             （3）如果你需要随机存取，而且关心两端数据的插入和删除，则应使用deque
*/
