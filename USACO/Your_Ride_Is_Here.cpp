/*
ID: xuziye01
PROG: ride
LANG: C++11
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main () {
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    string str1, str2;
    cin >> str1 >> str2;
    int n1(1), n2(1);
    for (int i = 0; i < str1.size(); ++i) {
        n1 *= str1[i] - 'A' + 1;
    }
    for (int i = 0; i < str2.size(); ++i) {
        n2 *= str2[i] - 'A' + 1;
    }
    printf("%s\n", (n1 % 47) == (n2 % 47) ? "GO" : "STAY");
    return 0;
}
