#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 7;

int n, x, x1, x2, y, y1, y2;
int A[maxn][maxn], C[maxn][maxn];
int T, Q, Case(0);
char cmd[5];

int lowbit(int X) {
    return X & (-X);
}

void update(int X, int Y, int val) {
    for(int i = X; i < maxn; i += lowbit(i)) {
        for(int j = Y; j < maxn; j += lowbit(j)) {
            C[i][j] += val;
        }
    }
}

int sum(int X, int Y) {
    int s(0);
    for(int i = X; i > 0; i -= lowbit(i)) {
        for(int j = Y; j > 0; j -= lowbit(j)) {
            s += C[i][j];
        }
    }
    return s;
}

void init() {
    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++) {
            A[i][j] = 1;
            C[i][j] = 0;
        }
    }
    for(int i = 1; i < maxn; i++) {
        for(int j = 1; j < maxn; j++) {
            update(i, j, 1);
        }
    }
}

int main() {
    scanf("%d", &T);
    while(T--) {
        init();
        printf("Case %d:\n", ++Case);
        scanf("%d", &Q);
        while(Q--) {
            scanf("%s", cmd);
            if(cmd[0] == 'S') {
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                x1++; y1++; x2++; y2++;
                printf("%d\n", sum(max(x1, x2), max(y1, y2)) + sum(min(x1, x2) - 1, min(y1, y2) - 1) - sum(max(x1, x2), min(y1, y2) - 1) - sum(min(x1, x2) - 1, max(y1, y2)));
            } else if(cmd[0] == 'A') {
                scanf("%d%d%d", &x, &y, &n);
                x++; y++;
                A[x][y] += n;
                update(x, y, n);
            } else if(cmd[0] == 'D') {
                scanf("%d%d%d", &x, &y, &n);
                x++; y++;
                n = min(n, A[x][y]);
                A[x][y] -= n;
                update(x, y, -n);
            } else if(cmd[0] == 'M') {
                scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &n);
                x1++; y1++; x2++; y2++;
                n = min(n, A[x1][y1]);
                A[x1][y1] -= n;
                update(x1, y1, -n);
                A[x2][y2] += n;
                update(x2, y2, n);
            }
        }
    }
    return 0;
}