#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <set>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int maxn = 1E5 + 7;

int n, m;
int t[maxn];
bool e[maxn * 2];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(e, false, sizeof(e));
        set<int> s;
        s.clear();
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &t[i]);
            e[t[i]] = true;
        }
        sort(t, t + n);
        for(int i = 0; i < n - 1; ++i) {
            if(t[i + 1] - t[i] > 1) s.insert(t[i] + 1);
        }
        s.insert(t[n - 1] + 1);
        while(m--) {
            int q;
            scanf("%d", &q);
            if(!e[q]) printf("%d\n", q);
            else printf("%d\n", *s.lower_bound(q));
        }
    }
    return 0;
}