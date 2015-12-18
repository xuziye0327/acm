#include <cstdio>
#include <algorithm>

using namespace std;

struct Job {
    int B, J;
    bool operator < (const Job& k) const {
        return J > k.J;
    }
}job[1007];

int main() {
    int N, Case(0);
    while (~scanf("%d", &N) && N) {
        for (int i = 0; i < N; ++i) {
            scanf("%d%d", &job[i].B, &job[i].J);
        }
        sort(job, job + N);
        int now = 0, cost = 0;
        for (int i = 0; i < N; ++i) {
            now += job[i].B;
            cost = max(cost, now + job[i].J);
        }
        printf("Case %d: %d\n", ++Case, cost);
    }
    return 0;
}
