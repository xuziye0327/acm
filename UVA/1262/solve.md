枚举/数学

直接枚举可过， 用数学算出来也行。

枚举不多说了。 说下数学做法。

根据第一组样例进行说明：
```
1
AYGSU
DOMRA
CPFAS
XBODG
WDYPK
PRXWO
CBOPT
DOSBG
GTRAR
APMMS
WSXNU
EFGHI
```

这组样例， 第一到五个字母只能是 ![{A,C,D,W}, {B,O,P}, {G,M,O,X}, {A,P}, {G,S,U}][1]。
总共有 ![4*3*4*2*3][2] 种可能的情况。 第一个字母确定的情况下后面只能有 ![3*4*2*3=72][3] 种可能。 第一个字母为 ![A][A] 的串序号范围为 ![1~72][4]， 第一个字母为 ![C][C] 的串序号范围为 ![73~144][5]。 这样依次推出剩下的字母。

[1]: https://latex.codecogs.com/gif.latex?%7BA%2CC%2CD%2CW%7D%2C%20%7BB%2CO%2CP%7D%2C%20%7BG%2CM%2CO%2CX%7D%2C%20%7BA%2CP%7D%2C%20%7BG%2CS%2CU%7D
[2]: https://latex.codecogs.com/gif.latex?4*3*4*2*3
[3]: https://latex.codecogs.com/gif.latex?3*4*2*3%3D72
[4]: https://latex.codecogs.com/gif.latex?1%7E72
[5]: https://latex.codecogs.com/gif.latex?73%7E144
[A]: https://latex.codecogs.com/gif.latex?A
[C]: https://latex.codecogs.com/gif.latex?C