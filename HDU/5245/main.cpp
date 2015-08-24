#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int T, Kase(0);
    scanf("%d", &T);
    while(T--) {
        double tot(0.0), M, N, K;
        double res(0.0);
        scanf("%lf%lf%lf", &M, &N, &K);
        for(int i = 1; i <= M; ++i) {
            for(int j = 1; j <= N; ++j) {
                tot = 0.0;
                tot += (i - 1) * (j - 1) * (M - i + 1) * (N - j + 1);
                tot += (i - 1) * (M - i + 1) * N;
                tot += (i - 1) * (N - j) * (M - i + 1) * j;
                tot += (j - 1) * M * (N - j + 1);
                tot += M * N;
                tot += (N - j) * M * j;
                tot += (M - i) * (j - 1) * i * (N - j + 1);
                tot += (M - i) * i * N;
                tot += (M - i) * (N - j) * i * j;
                tot = tot / (M * M * N * N);
                res += 1.0 - pow((1.0 - tot), K);
            }
        }
        printf("Case #%d: %d\n", ++Kase, (int)(res + 0.5));
    }
    return 0;
}