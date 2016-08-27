#include <bits/stdc++.h>

using namespace std;

const int maxn = 30 + 7;

struct point {
    int x, y;
    bool operator < (const point &k) const {
        return x != k.x ? x < k.x : y < k.y;
    }
};

struct quar {
    point p[5];
};

int x, y, N;
point p[maxn];
vector<quar> v;

void init() {
    v.clear();
    memset(p, 0, sizeof(p));
}

int main() {
    while(~scanf("%d", &N) && N) {
        init();
        for(int i = 0; i < N; i++) {
            scanf("%d%d", &x, &y);
            p[i].x = x;
            p[i].y = y;
        }
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                for(int k = j + 1; k < N; k++) {
                    for(int m = k + 1; m < N; m++) {
                        quar q;
                        q.p[0].x = p[i].x;
                        q.p[0].y = p[i].y;
                        q.p[1].x = p[j].x;
                        q.p[1].y = p[j].y;
                        q.p[2].x = p[k].x;
                        q.p[2].y = p[k].y;
                        q.p[3].x = p[m].x;
                        q.p[3].y = p[m].y;
                        sort(q.p, q.p + 4);
                        if(q.p[0].x == q.p[1].x && q.p[1].y == q.p[3].y && q.p[2].x == q.p[3].x && q.p[0].y == q.p[2].y) {
                            v.push_back(q);
                        }
                    }
                }
            }
        }

        int res(0);
        vector<quar> :: iterator it1;
        vector<quar> :: iterator it2;
        for(it1 = v.begin(); it1 != v.end(); it1++) {
            for(it2 = it1 + 1; it2 != v.end(); it2++) {
                quar q1 = (*it1), q2 = (*it2);
                int inq1(0), inq2(0);
                bool ok = true;
                for(int i = 0; i < 4; i++) {
                    if((q2.p[i].x >= q1.p[0].x && q2.p[i].x <= q1.p[2].x && q2.p[i].y >= q1.p[0].y && q2.p[i].y <= q1.p[1].y) ||
                       (q1.p[i].x >= q2.p[0].x && q1.p[i].x <= q2.p[2].x && q1.p[i].y >= q2.p[0].y && q1.p[i].y <= q2.p[1].y)) ok = false;
                }
                for(int i = 0; i < 4; i++) {
                    if(q2.p[i].x > q1.p[0].x && q2.p[i].x < q1.p[2].x && q2.p[i].y > q1.p[0].y && q2.p[i].y < q1.p[1].y) {
                        inq1++;
                    }
                }
                for(int i = 0; i < 4; i++) {
                    if(q1.p[i].x > q2.p[0].x && q1.p[i].x < q2.p[2].x && q1.p[i].y > q2.p[0].y && q1.p[i].y < q2.p[1].y) {
                        inq2++;
                    }
                }
                if(ok) {
                    res = max(res, (q1.p[1].y - q1.p[0].y) * (q1.p[2].x - q1.p[0].x) + (q2.p[1].y - q2.p[0].y) * (q2.p[2].x - q2.p[0].x));
                } else if(inq1 == 4) {
                    res = max(res, (q1.p[1].y - q1.p[0].y) * (q1.p[2].x - q1.p[0].x));
                } else if(inq2 == 4) {
                    res = max(res, (q2.p[1].y - q2.p[0].y) * (q2.p[2].x - q2.p[0].x));
                }
            }
        }
        if(res > 0) printf("%d\n", res);
        else printf("imp\n");
    }
    return 0;
}