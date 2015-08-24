#include <cstdio>

const int maxn = 100 + 7;
const char col[] = {'G', 'R'};

int n;
char mm[maxn][maxn];

void solve() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) mm[i][j] = 'B';
    for(int i = 0; i < n; i++) mm[0][i] = 'Y';

    for(int i = 0; i < (n - 1) / 2; i++) {
        char c = col[i % 2];
        for(int j = i + 1; j < n; j++) {
            mm[j][i] = c;
        }
        for(int j = 1; j <= i + 1; j++) {
            mm[j][i + 1] = c;
        }
    }

    for(int i = (n - 1) / 2; i < n - 1; i++) {
        char c = col[i % 2];
        for(int j = i + 2; j < n; j++) {
            mm[j][i] = c;
        }
        mm[i + 2][i + 1] = c;
        for(int j = 2; j <= i + 2; j++) {
            mm[j][i + 2] = c;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%c", mm[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        if(n == 1) printf("Y\n");
        else if(n <= 4) printf("No solution!\n");
        else if(n == 6) {
            printf("YYYYYY\n");
            printf("GGRGRR\n");
            printf("GRRGRB\n");
            printf("GRGGRB\n");
            printf("GRGRRB\n");
            printf("GRGBBB\n");
        } else {
            solve();
        }
    }
    return 0;
}