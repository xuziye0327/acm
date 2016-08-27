#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <set>
#include <vector>
#include <queue>
using namespace std;

const int inf = 1 << 30;
const int maxn = 100 + 7;

queue<int> v;
int a[maxn][maxn], dp[maxn][maxn];

int main()
{
    int T;
    scanf("%d",&T);int kase=0;
    while(T--)
    {
        int m, n;
        scanf("%d%d", &m, &n);
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < maxn; ++i)
            for(int j = 0; j < maxn; ++j) dp[i][j] = inf;
        printf("Case %d\n", ++kase);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        for(int i = 0; i < n; ++i) dp[m - 1][i] = a[m - 1][i];
        for(int i = m - 1; i >= 1; --i) {
            for(int j = 0; j < n; ++j) {
                if(j == 0) dp[i - 1][j] = min(dp[i - 1][j], a[i - 1][j] + min(dp[i][0], dp[i][1]));
                else if(j == n - 1) dp[i - 1][j] = min(dp[i - 1][j], a[i - 1][j] + min(dp[i][n - 2], dp[i][n - 1]));
                else dp[i - 1][j] = min(dp[i - 1][j], a[i - 1][j] + min(min(dp[i][j - 1], dp[i][j + 1]), dp[i][j]));
            }
        }
        int res(inf);
        int last(-1);
        for(int i = 0; i < n; ++i) res = min(res, dp[0][i]);
        for(int j = 0; j < m; ++j) {
            if(last == -1) {
                for(int i = n - 1; i >= 0; --i) {
                    if(res == dp[j][i]) { v.push(i); res -= a[j][i]; last = i; continue; }
                }
            } else {
                for(int i = last + 1; i >= last - 1; --i) {
                    if(i >= n || i < 0) continue;
                    if(res == dp[j][i]) { v.push(i); res -= a[j][i]; last = i; continue; }
                }
            }
        }
        bool beg(true);
        while(!v.empty()) {
            if(!beg) printf(" ");
            beg = false;
            printf("%d", v.front() + 1);
            v.pop();
        }
        printf("\n");
    }
    return 0;
}