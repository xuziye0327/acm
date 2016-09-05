#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 7;
const int maxm = 30 + 7;

int d[maxn][maxm];

void RMQ_init(const vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n; ++i) d[i][0] = A[i];
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            d[i][j] = max(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int RMQ(int L, int R) {
    if (L > R) return 0;
    int k = 0;
    while ((1 << k + 1) <= R - L + 1) ++k;
    return max(d[L][k], d[R - (1 << k) + 1][k]);
}

int a[maxn];
int num[maxn];
int l[maxn], r[maxn];
vector<int> vec;

int main() {
    int n, q;
    while (~scanf("%d", &n) && n) {
        vec.clear();
        scanf("%d", &q);
        int t = 0;
        l[0] = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if (i != 0 && a[i] != a[i - 1]) {
                r[vec.size()] = i - 1;
                vec.push_back(t);
                l[vec.size()] = i;
                t = 0;
            }
            ++t;
            num[i] = vec.size();
        }
        RMQ_init(vec);
        while (q--) {
            int x, y;
            scanf("%d%d", &x, &y);
            --x, --y;
            if (a[x] == a[y]) printf("%d\n", y - x + 1);
            else {
                printf("%d\n", max(RMQ(num[x] + 1, num[y] - 1), max(y - l[num[y]] + 1, r[num[x]] - x + 1)));
            }
        }
    }
    return 0;
}
