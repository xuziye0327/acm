#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 7;

int M, X, Y, X1, X2, Y1, Y2;
int C[maxn][maxn];
char cmd[5];
bool A[maxn][maxn];

void init() {
    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++)  { A[i][j] = false;; C[i][j] = 0; }
}

int lowbit(int i) {
    return i & (-i);
}

void update(int i, int j, int x) {
    for(int m = i; m <= maxn; m += lowbit(m))
        for(int n = j; n <= maxn; n += lowbit(n)) C[m][n] += x;
}

int sum(int i, int j) {
    if(i <= 0 || j <= 0) return 0;
    int s(0);
    for(int m = i; m > 0; m -= lowbit(m))
        for(int n = j; n > 0; n -= lowbit(n)) s += C[m][n];
    return s;
}

int main() {
    init();
    scanf("%d", &M);
    while(M--) {
        scanf("%s", cmd);
        if(cmd[0] == 'B') {
            scanf("%d%d", &X, &Y);
            X++; Y++;
            if(!A[X][Y]) {
                update(X, Y, 1);
                A[X][Y] = true;
            }
        } else if (cmd[0] == 'D') {
            scanf("%d%d", &X, &Y);
            X++; Y++;
            if(A[X][Y]) {
                update(X, Y, -1);
                A[X][Y] = false;
            }
        } else if(cmd[0] == 'Q') {
            scanf("%d%d%d%d", &X1, &X2, &Y1, &Y2);
            X1++; X2++; Y1++; Y2++;
            int x1(min(X1, X2)), x2(max(X1, X2)), y1(min(Y1, Y2)), y2(max(Y1, Y2));
            int res(0);
            res = sum(x2, y2) + sum(x1 - 1, y1 - 1) - sum(x1 - 1, y2) - sum(x2, y1 - 1);

            printf("%d\n", res);
        }
    }
    return 0;
}