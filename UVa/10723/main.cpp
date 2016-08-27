#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>

using namespace std;

typedef unsigned long long ull;

const int maxn = 37;

char str1[maxn], str2[maxn];
int d1[maxn][maxn], d2[maxn][maxn];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int T, Case(0);
    scanf("%d", &T);
    getchar();
    while (T--) {
        memset(d1, 0, sizeof(d1));
        memset(d2, 0, sizeof(d2));
        gets(str1 + 1);
        gets(str2 + 1);
        int len1 = strlen(str1 + 1);
        int len2 = strlen(str2 + 1);

        for (int i = 0; i < maxn; ++i) {
            d1[i][0] = d1[0][i] = i;
            d2[i][0] = d2[0][i] = 1;
        }
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (str1[i] == str2[j]) {
                    d1[i][j] = d1[i - 1][j - 1] + 1;
                    d2[i][j] = d2[i - 1][j - 1];
                } else {
                    d1[i][j] = min(d1[i - 1][j], d1[i][j - 1]) + 1;
                    if (d1[i - 1][j] < d1[i][j - 1]) d2[i][j] = d2[i - 1][j];
                    else if (d1[i - 1][j] > d1[i][j - 1]) d2[i][j] = d2[i][j - 1];
                    else d2[i][j] = d2[i - 1][j] + d2[i][j - 1];
                }
            }
        }

        printf("Case #%d: %d %d\n", ++Case, d1[len1][len2], d2[len1][len2]);
    }
    return 0;
}
