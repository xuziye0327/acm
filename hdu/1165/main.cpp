#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int m, n;

int main() {
    while(~scanf("%d%d", &m, &n)) {
        printf("%d\n", m == 0 ? n + 1 : m == 3 ? (1 << (n + 3)) - 3 : m * (n + 1) + 1);
    }
    return 0;
}
