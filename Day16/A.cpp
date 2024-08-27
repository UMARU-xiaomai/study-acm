#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1007;
int f[maxn][maxn];// dp数组，存储了各子区间要成为回文串所需要添加的字符个数，x、y分别表示起点和终点
char s[maxn];
int len;
//p1435
int main() {
	scanf("%s", s + 1); 
	len = strlen(s + 1); 
	
    //初始化，每个只有一个字符的字符串是回文
    for(int i = 1; i <= len; i++) f[i][i] = 0;
	for(int k = 1; k < len; k++) //k是长度
		for(int i = 1; i <= len - k; i++) { //i是起点
			int j = i + k; //j是终点
			if(s[i] == s[j]) {
				f[i][j] = f[i + 1][j - 1];// 说明加上左i右j还是回文串，无需添加
			} else {
				f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;// 当左右不同时，需添加字符，这里有两种方案：一个是加右添左、一个是加左添右
			}
			//tips：使用dp时要确保后面的情况使用前面的数据时前面的数据必须已经循环过了；否则必须使用递归
		}
	
	cout << f[1][len];
	return 0;
}