### 题目链接
<a href="http://acm.sdut.edu.cn/sdutoj/problem.php?action=showproblem&problemid=2416">HERE</a>

### 题目描述
直接看图，给出OA，OB，OM，求出(-b, H)这一段的体积。

### 解题思路
根据微积分求出公式，公式见代码。

``` cpp
/* ***********************************************
Author        :myz
Created Time  :2016年02月20日 星期六 20时52分30秒
File Name     :a.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

const double PI = acos(-1);

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T, Case(0);
    scanf("%d", &T);
    while (T--) {
        double a, b, H;
        scanf("%lf%lf%lf", &a, &b, &H);
        if (H >= b) H = b;
        printf("Case %d: %.3f\n", ++Case, PI * a * b * H - 
                PI * a * H * H * H / (3.0 * b) + PI * a * b * b * 2.0 / 3.0);
    }
    return 0;
}
