#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1000000 + 7;

int m, n;
int A[3][maxn];

int main() {
    for(int i = 0; i < maxn; ++i) A[0][i] = i + 1;
    A[1][0] = A[0][1];
    for(int i = 1; i < maxn; ++i) A[1][i] = A[1][i - 1] + 1;
    A[2][0] = A[1][1];
    for(int i = 1; i < maxn; ++i) A[2][i] = A[2][i - 1] + 2;
    A[3][0] = A[2][1];
    for(int i = 1; i < 27; ++i) A[3][i] = A[3][i - 1] * 2 + 3;
    while(~scanf("%d%d", &m, &n)) {
        printf("%d\n", A[m][n]);
    }
    return 0;
}