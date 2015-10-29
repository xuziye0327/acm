/*
ID: xuziye01
PROG: friday
LANG: C++11
*/

#include <cstdio>

using namespace std;

const int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int ans[8];

bool judge(int y) {
    if (y % 400 == 0) return true;
    if (y %   4 == 0 && y % 100 != 0) return true;
    return false;
}

int main() {
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    int N, d(13);
    scanf("%d", &N);
    for (int y = 1900; y < 1900 + N; ++y) {
        for (int i = 1; i <= 12; ++i) {
            if (d % 7 == 0) ++ans[7];
            else  ++ans[d % 7];
            d += day[i];
            if (i == 2 && judge(y)) ++d;
        }
    }
    printf("%d %d", ans[6], ans[7]);
    for (int i = 1; i < 6; ++i) {
        printf(" %d", ans[i]);
    }
    printf("\n");
    return 0;
}
