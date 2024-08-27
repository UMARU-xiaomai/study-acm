#include <bits/stdc++.h>
using namespace std;
int n;
int a[101][101];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int k = 1; k <= n; k++)//记得k循环在i和j之前
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
               if(a[i][k]==1 && a[k][j]==1)
               {
                     a[i][j] = 1;
               };//这道题是p3647的简化，只需要求求任意俩点间能不能链接
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}