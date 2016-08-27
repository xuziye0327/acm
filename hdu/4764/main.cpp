#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, k;
    while(~scanf("%d%d", &N, &k) && N) {
        int res((N + k) / (k + 1));
        if(N != (k + 1) * res - k) printf("Tang\n");
        else printf("Jiang\n");
    }
    return 0;
}