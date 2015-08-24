#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long ull;

const int maxn = 50 + 7;

char str[maxn];
int n, start[maxn], finish[maxn];

ull f(int *P, int i, int fina) {
    if(i == 0) return 0;
    if(P[i] == fina) return f(P, i - 1, fina);
    return f(P, i - 1, 6 - P[i] - fina) + (1ULL << (i - 1 ));
}

int main() {
    for(int i = 0; i < maxn; ++i) finish[i] = 1;
    scanf("%d", &n);
    scanf("%s", str + 1);
    for(int i = 1; i <= n; ++i) start[i] = str[i] - 'A' + 1;
    int k = n;
    while(k >= 1 && start[k] == finish[k]) --k;
    ull ans(0);
    if(k >= 1) {
        int other = 6 - start[k] - finish[k];
        ans = f(start, k - 1, other) + f(finish, k - 1, other) + 1;
    }
    printf("%I64u", ans);
    return 0;
}