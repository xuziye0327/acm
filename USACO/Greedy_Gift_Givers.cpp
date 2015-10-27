/*
ID: xuziye01
PROG: gift1
LANG: C++11
*/

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

const int maxn = 17;

using namespace std;

int money[maxn];
string str[maxn];
map<string, int> nameToNo;

int main() {
    ios::sync_with_stdio(false);
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
        nameToNo[str[i]] = nameToNo.size();
    }
    string name;
    while (cin >> name) {
        int x, tot, real = 0;
        cin >> tot >> x;
        if (x != 0)
            real = tot / x;
        money[nameToNo[name]] -= real * x;
        for (int i = 0; i < x; ++i) {
            cin >> name;
            money[nameToNo[name]] += real;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << str[i] << " " << money[nameToNo[str[i]]] << endl;
    }
    return 0;
}
