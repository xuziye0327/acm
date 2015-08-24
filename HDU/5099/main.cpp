#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, kase(0);
    cin >> n;
    while(n--) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << "Case " << ++kase << ": " ;
        if(s1[0] < s2[0]) cout << "<" ;
        else if(s1[0] > s2[0]) cout << ">" ;
        else cout << "=";
        cout << " ";
        if(s1[1] == s2[1]) {
            s1 = s1.substr(2, 4);
            s2 = s2.substr(2, 4);
        } else {
            s1 = s1.substr(2, 3);
            s2 = s2.substr(2, 3);
        }
        if(s1 < s2) cout << "<" ;
        else if(s1 > s2) cout << ">" ;
        else cout << "=";
        cout << endl;
    }
    return 0;
}