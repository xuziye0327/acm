#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 100 + 7;

struct Node {
    double x, y, z, i;
}node[maxn];

int n;

double dis(double x1, double y1, double x2, double y2, double z2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + z2 * z2);
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        double Max(0.0);
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%lf%lf%lf%lf", &node[i].x, &node[i].y, &node[i].z, &node[i].i);
        for(int i = -100; i <= 100; ++i) {
            for(int j = -100; j <= 100; ++j) {
                double E(0.0);
                for(int k = 0; k < n; ++k) {
                    double d = dis(i, j, node[k].x, node[k].y, node[k].z);
                    E += node[k].i * node[k].z / d / d / d;
                }
                Max = max(Max, E);
            }
        }
        printf("%.2f\n", Max);
    }
    return 0;
}