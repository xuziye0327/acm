#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int G, L;
        scanf("%d%d", &G, &L);
        if(L % G) printf("0\n");
        else {
            ull res(1);
            L = L / G;
            int n = (int)sqrt(L) + 1;
            for(int i = 2; i <= n; ++i) {
                if(L % i == 0) {
                    ull t(0);
                    while(L % i == 0) {
                        L /= i;
                        ++t;
                    }
                    res *= 6 * t;
                }
            }
            if(L != 1) res *= 6;
            printf("%I64u\n", res);
        }
    }
    return 0;
}