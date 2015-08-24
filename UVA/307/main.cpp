#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 500 + 7;

int n;
int a[maxn];
bool used[maxn];

bool cmp(const int &k1, const int &k2) {
    return k1 > k2;
}

bool dfs(int sum, int cnt, int pos, const int goal) {
    if(cnt == n) return true;
    for(int i = pos; i <= n; ++i) {
        if(used[i] || (!used[i - 1] && a[i - 1] == a[i])) continue;
        if(sum + a[i] < goal) {
            used[i] = true;
            if(dfs(sum + a[i], cnt + 1, i + 1, goal)) return true;
            used[i] = false;
        }
        if(sum + a[i] == goal) {
            used[i] = true;
            if(dfs(0, cnt + 1, 1, goal)) return true;
            used[i] = false;
            return false;
        }
        if(sum == 0) return false;
    }
    return false;
}

int main() {
    while(~scanf("%d", &n) && n) {
        int sum(0);

        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            sum += a[i];
        }

        sort(a + 1, a + n + 1, cmp);

        for(int i = a[1]; i <= sum; ++i) {
            memset(used, 0, sizeof(used));
            if(sum % i == 0) {
                if(dfs(0, 0, 1, i)) {
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }
    return 0;
}