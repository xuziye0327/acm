### 题目链接
<a href="http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=1313">HERE</a>

### 题目描述
N个人围成一个圈传球，从第一个人开始，每人把球给他左边第k(1<=k<=N/2)个人。问可以使每个人摸到至少一次球的最大k。

### 解题思路
打表可发现
1. N是奇数，ans=N/2
2. N是偶数
 (1. N/2是奇数，ans=N/2-2
 (2. N/2是偶数，ans=N/2-1

``` java
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by myz on 2015/11/11.
 */
public class Main {
    static public void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int t = cin.nextInt();
        BigInteger b;
        boolean blank = false;
        while (t-- > 0) {
            if (blank) {
                System.out.println();
            }
            blank = true;
            b = cin.nextBigInteger();
            if (b.mod(BigInteger.valueOf(2)).equals(BigInteger.ONE)) {
                System.out.println(b.divide(BigInteger.valueOf(2)));
            } else {
                BigInteger temp = b.divide(BigInteger.valueOf(2));
                if (temp.mod(BigInteger.valueOf(2)).equals(BigInteger.ONE)) {
                    temp = temp.subtract(BigInteger.valueOf(2));
                } else {
                    temp = temp.subtract(BigInteger.ONE);
                }
                System.out.println(temp);
            }
        }
    }
}
```