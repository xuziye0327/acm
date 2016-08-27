#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int main () {
    int n;
    while (~scanf("%d", &n) && n) {
        multiset<int> s;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int k, x;
            scanf("%d", &k);
            while (k--) {
                scanf("%d", &x);
                s.insert(x);
            }
            auto beg = s.begin(), end = --s.end();
            ans += long((*end) - (*beg));
            s.erase(beg);
            s.erase(end);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
