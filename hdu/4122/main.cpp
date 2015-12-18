#include <iostream>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

typedef pair<int, int> P;

const int maxn = 2500 + 7;
const string month[13] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
const int day[2][13] = { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                         {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };

int n, m, T, S;
deque<P> order, moon;

void init() {
    while(!order.empty()) order.pop_front();
    while(!moon.empty()) moon.pop_front();
}

int get_year(int yy) {
    return (!(yy % 400)) || (yy % 100 && (!(yy % 4)));
}

int get_month(string s) {
    for(int i = 1; i <= 12; ++i) if(s == month[i]) return i;
}

void get_order() {
    char m[5];
    int d, y, H;
    for(int i = 0; i < n; ++i) {
        P p;
        cin >> m >> d >> y >> H >> p.first;
        for(int j = 2000; j < y; ++j) H += (get_year(j) ? 366 : 365) * 24;
        for(int j = 1; j < get_month(m); ++j) H += day[get_year(y)][j] * 24;
        H += (d - 1) * 24;
        p.second = H;
        order.push_back(p);
    }
}

int main() {
    while(cin >> n >> m && n) {
        init();
        get_order();
        cin >> T >> S;
        long long res(0);
        for(int i = 0; i < m; ++i) {
            int cast;
            cin >> cast;
            while(!moon.empty() && cast <= moon.back().first + (i - moon.back().second) * S)
                moon.pop_back();
            moon.push_back(make_pair(cast, i));
            while(!order.empty() && i == order.front().second) {
                while(!moon.empty() && moon.front().second < order.front().second - T)
                    moon.pop_front();
                res += order.front().first * ((i - moon.front().second) * S + moon.front().first);
                order.pop_front();
            }
        }
        cout << res << endl;
    }
    return 0;
}