#include <bits/stdc++.h>

using namespace std;

const int maxn = 12 + 7;
const double eps = 1e-6;

struct trick {
    double l;
    int id;
};

struct triangle {
    trick a, b, c;
};

double res;
bool used[maxn];
trick V[maxn];
vector <triangle> v;

bool make_tri(triangle &t) {
    if(t.a.l + t.b.l > t.c.l && t.b.l + t.c.l > t.a.l && t.a.l + t.c.l > t.b.l) return true;
    return false;
}

void bs(double sov) {
    bool ok = true;
    for(vector<triangle> :: iterator it = v.begin(); it != v.end(); it++) {
        if(!used[(*it).a.id] && !used[(*it).b.id] && !used[(*it).c.id]) {
            double p = ((*it).a.l + (*it).b.l + (*it).c.l) / 2.0;
            used[(*it).a.id] = used[(*it).b.id] = used[(*it).c.id] = true;
            bs(sov + sqrt(p * (p - (*it).a.l) * (p - (*it).b.l) * (p - (*it).c.l)));
            used[(*it).a.id] = used[(*it).b.id] = used[(*it).c.id] = false;
        }
    }
    res = max(res, sov);
}

int main() {
    int N;
    while(~scanf("%d", &N) && N) {
        fill(used, used + maxn, false);
        memset(V, 0, sizeof(V));
        v.clear();
        res = 0;
        for(int i = 0; i < N; i++) {
            scanf("%lf", &V[i].l);
            V[i].id = i;
        }
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                for(int k = j + 1; k < N; k++) {
                    triangle t;
                    t.a = V[i]; t.b = V[j]; t.c = V[k];
                    if(make_tri(t)) v.push_back(t);
                }
            }
        }
        bs(0.0);
        printf("%.2f\n", res);
    }
    return 0;
}