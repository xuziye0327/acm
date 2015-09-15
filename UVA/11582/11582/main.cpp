//
//  main.cpp
//  11582
//
//  Created by ZmiL on 15/9/11.
//  Copyright (c) 2015年 ZmiL. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef pair<int, int> P;

const int maxn = 1000 + 7;

vector<int> F[maxn];
set<P> ma;

int pow_mod(ull a, ull b, ull n) {
    ull res(1ull);
    a %= n;
    while (b) {
        if (b & 1) {
            res = res * a % n;
        }
        a = a * a % n;
        b >>= 1;
    }
    return (int)res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    for (int k = 1; k <= 1000; ++k) {
        ma.clear();
        F[k].push_back(1 % k);
        F[k].push_back(1 % k);
        ma.insert(P(F[k][0], F[k][1]));
        for (int i = 2; ; ++i) {
            int t = (F[k][i - 2] + F[k][i - 1]) % k;
            if (ma.count(P(F[k][i - 1], t))) break;
            else {
                ma.insert(P(F[k][i - 1], t));
                F[k].push_back(t);
            }
        }
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        int m, res;
        ull a, b, n;
        scanf("%llu%llu%llu", &a, &b, &n);
        m = (int)F[n].size() - 1;
        res = pow_mod(a, b, m);
        printf("%d\n", res == 0 ? F[n][m - 1] : F[n][res - 1]);
    }
    return 0;
}