#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        double tt, sum(0);
        for(int i = 0; i < 12; ++i) {
            scanf("%lf", &tt);
            sum += tt;
        }
        sum /= 12.0;
        int k = (int)((sum + 0.005) * 100.0);
        if(k % 10 != 0) printf("$%.2f\n", k / 100.0);
        else if(k % 100 != 0) printf("$%.1f\n", k / 100.0);
        else printf("$%d\n", k / 100);
    }
    return 0;
}