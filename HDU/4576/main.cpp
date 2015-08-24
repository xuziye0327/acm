#include<iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 200 + 7;

double d[2][maxn];

int main(){
    int n,m,l,r,t;
    while(~scanf("%d %d %d %d",&n,&m,&l,&r)&&n){
        t = 0;
        memset(d, 0, sizeof(d));
        d[0][1] = 1.0;
        while(m--) {
            int a, b, op;
            scanf("%d", &op);
            memset(d[(t + 1) % 2], 0, sizeof(d[(t + 1) % 2]));
            for(int i = 1; i <= n; ++i) {
                a = i - (op % n), b = i + (op % n);
                while(a<=0) a += n;
                while(b>n) b -= n;
                d[(t + 1) % 2][a] += d[t % 2][i] / 2.0;
                d[(t + 1) % 2][b] += d[t % 2][i] / 2.0;
            }
            ++t;
        }
        double res(0.0);
        for(int i = l; i <= r; ++i) {
            res += d[t % 2][i];
        }
        printf("%.4f\n", res);
    }
    return 0;
}

