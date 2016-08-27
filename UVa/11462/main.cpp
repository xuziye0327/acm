#include <cstdio>
#include <cstring>

const int maxn = 107;

int cnt[maxn];

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            ++cnt[x];
        }
        bool flag = false;
        for (int i = 1; i <= 100; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                if (flag) printf(" ");
                flag = true;
                printf("%d", i);
            }
        }
        printf("\n");
    }
    return 0;
}
