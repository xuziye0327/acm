#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 500 + 7;

int ma[maxn][maxn];
vector<pii> vec[maxn];

int main() {
//    freopen("my.out", "w", stdout);
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < maxn; ++i) vec[i].clear();
        if (n == 1) {
            printf("1 1\n1 1\n");
            continue;
        } else if (n == 2) {
            printf("1 3\n1 1\n1 2 1 3\n");
            continue;
        } else if (n == 3) {
            printf("2 3\n1 2\n1 3 2 3\n1 1 2 1 2 2\n");
            continue;
        } else if (n == 4) {
            printf("2 5\n1 4\n1 5 2 5\n1 1 2 1 2 2\n1 2 1 3 2 3 2 4\n");
            continue;
        } else if (n == 5) {
            printf("3 5\n3 4\n1 4 1 5\n2 4 2 5 3 5\n2 2 2 3 3 3 3 2\n3 1 2 1 1 1 1 2 1 3\n");
            continue;
        }
        for (int i = 1; i <= (n + 1) >> 1; ++i) {
            int x = 2 * i - 1;
            for (int j = i; j >= 1; --j) {
                ma[i][j] = ma[j][i] = x;
            }
        }
        if (((n + 1) >> 1) & 1) {
            int num = 2;
            for (int i = ((n + 1) >> 1) + 1; i <= n + 1; i += 2) {
                for (int j = 1; j <= num >> 1; ++j) ma[j][i] = ma[j][i + 1] = num;
                num += 4;
            }
            num = 4;
            for (int i = 2; i <= (n + 1) >> 1; i += 2) {
                for (int j = ((n + 1) >> 1) + 1; j <= ((n + 1) >> 1) + (num >> 1); ++j) ma[i][j] = ma[i + 1][j] = num;
                num += 4;
            }
        } else {
            int num = 2;
            for (int i = 1; i <= n - 1; i += 2) {
                for (int j = ((n + 1) >> 1) + 1; j < ((n + 1) >> 1) + 1 + i; ++j) ma[i][j] = ma[i + 1][j] = num;
                num += 4;
            }
            num = 4;
            for (int j = ((n + 1) >> 1) + 2; j <= n + !(n & 1); j += 2) {
                for (int i = 1; i <= num >> 1; ++i) ma[i][j] = ma[i][j + 1] = num;
                num += 4;
            }
        }
        for (int i = 1; i <= (n + 1) >> 1; ++i) {
            for (int j = (n + 1) >> 1; j >= 1; --j) {
                vec[ma[i][j]].push_back(pii(i, j));
            }
        }
        for (int i = 1; i <= (n + 1) >> 1; ++i) {
            if (i & 1) {
                for (int j = n + !(n & 1); j > (n + 1) >> 1; --j) {
                    vec[ma[i][j]].push_back(pii(i, j));
                }
            } else {
                for (int j = ((n + 1) >> 1) + 1; j <= n + !(n & 1); ++j) {
                    vec[ma[i][j]].push_back(pii(i, j));
                }
            }
        }
        printf("%d %d\n", (n + 1) >> 1, n + !(n & 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < vec[i].size(); ++j) {
                if (j) printf(" ");
                printf("%d %d", vec[i][j].first, vec[i][j].second);
            }
            printf("\n");
        }
    }
    return 0;
}
