#include <bits/stdc++.h>

using namespace std;

const int maxn = 50 + 7;

int main() {
    int T;
    int A[maxn];
    cin >> T;
    while(T--) {
        int N;
        bool ok = false;
        int res(0);
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for(int i = 1; i < N; i++) {
            if(A[i] > A[i - 1]) ok = true;
            if(ok && A[i] < A[i - 1]) {
                res++;
                ok = false;
            }
        }
        cout << res << endl;
    }
    return 0;
}