### 题目链接
<a href="https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=456&page=show_problem&problem=2829">HERE</a>

### 题目描述
给n个人分配任务，给第i个人分配任务需要B分钟，第i个人完成任务需要J分钟，求最后一个人完成任务所需要的最少时间

### 解题思路
很容易就想到完成时间最长的人最先分配任务。

``` cpp
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
```