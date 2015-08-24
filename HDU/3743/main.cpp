/*
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> A;

ll merge_count(vector<int> &a) {
    int n = a.size();
    if(n <= 1) return 0;

    ll cnt = 0;
    vector<int> b(a.begin(), a.begin() + n / 2);
    vector<int> c(a.begin() + n / 2, a.end());

    cnt += merge_count(b);
    cnt += merge_count(c);

    int ai = 0, bi = 0, ci = 0;
    while(ai < n) {
        if(bi < b.size() && (ci == c.size() || b[bi] <= c[ci])) {
            a[ai++] = b[bi++];
        } else {
            cnt += n / 2 - bi;
            a[ai++] = c[ci++];
        }
    }

    return cnt;
}

int main() {
    int n, t;
    while(~scanf("%d", &n)) {
        A.clear();
        for(int i = 0; i < n; i++) {
            scanf("%d", &t);
            A.push_back(t);
        }
        printf("%I64d\n", merge_count(A));
    }
    return 0;
}
*/
/*
#include <cstdio>

const int maxn = 1000000 + 7;

int n;
long long res;
long long a[maxn], b[maxn];

void init() {
    res = 0;
    for(int i = 0; i < maxn; i++) a[i] = b[i] = 0;
}

void Merge(long long *a, int start, int mid, int end) {
    int i = start, j = mid + 1, k = start;
    while(i <= mid && j <= end) {
        if(a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            res += j - k;
            b[k++] = a[j++];
        }
    }
    while(i <= mid) b[k++] = a[i++];
    while(j <= end) b[k++] = a[j++];
    for(int i = start; i <= end; i++ )
        a[i] = b[i];
}

void MergeSort(long long *a, int start, int end) {
    int mid = (start + end) / 2;
    if(start < end) {
        MergeSort(a, start, mid);
        MergeSort(a, mid + 1, end);
        Merge(a, start, mid, end);
    }
}

int main() {
    while(~scanf("%d", &n)) {
        init();
        for(int i = 0; i < n; i++) {
            scanf("%I64d", &a[i]);
        }
        MergeSort(a, 0, n - 1);

        printf("%I64d\n", res);
    }
    return 0;
}
*/
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int maxn = 1000000 + 7;

int n;
long long res;
int C[maxn];
int t, A[maxn], B[maxn];
map<long long, int> m;

void init() {
    m.clear();
    res = 0;
    for(int i = 0; i < maxn; i++) A[i] = B[i] = C[i] = 0;
}

int lowbit(int x) {
    return x & (-x);
}

void update(int pos, int val) {
    for(int i = pos; i < maxn; i += lowbit(i)) {
        C[i] += val;
    }
}

int sum(int pos) {
    int s(0);
    while(pos > 0) {
        s += C[pos];
        pos -= lowbit(pos);
    }
    return s;
}

int main() {
    while (~scanf("%d", &n)) {
        init();
        for (int i = 0; i < n; i++) {
            scanf("%d", &t);
            A[i] = B[i] = t;
        }
        sort(B, B + n);
        for (int i = 0; i < n; i++) {
            m[B[i]] = m.size();
        }
        for (int i = 1; i <= n; i++) {
            update(m[A[i - 1]], 1);
            res += i - sum(m[A[i - 1]]);
        }
        printf("%I64d\n", res);
    }
    return 0;
}