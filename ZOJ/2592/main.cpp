#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, t, sum(0);
        cin >> n;
        while(n--) cin >> t, sum += t;
        cout << (sum > 0 ? sum : 0) << endl;
    }
    return 0;
}