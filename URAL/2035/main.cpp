#include <cstdio>

int main() {
    int a(-1), b(-1);
    int X, Y, C;
    scanf("%d%d%d", &X, &Y, &C);
    if(X + Y >= C)
        for(int i = 0; i <= X; ++i) {
            if(C - i > Y) continue;
            if(C - i < 0) break;
            a = i; b = C - i;
            break;
        }
    if(a == -1 || b == -1) printf("Impossible\n");
    else printf("%d %d", a, b);
    return 0;
}