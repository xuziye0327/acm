### 题目链接
<a href = "https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=2370">传送门</a>

### 题目描述
用n个火柴棍能组成多少种数字。

### 解题思路
设d[i]为用i根火柴棍能摆成的数字， c[i]为数字i使用的火柴棍。
在d[i]的状态下往后面加一个数字j， 那么d[i + c[j]] = d[i + c[j]] + d[i]。
先把单独的0去掉， 当n >= 6的时候加上1。
要用到大数， 懒得写模板 + 开java， 所以直接用py写了。

``` python3
MAXN = 2007

c = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]
d = [0 for i in range(MAXN)] 
d[0] = 1
for i in range(MAXN) :
	for j in range(10) :
		if i + c[j] < MAXN and not(i == 0 and j == 0) :
			d[i + c[j]] += d[i]

while True :
	try :
		n = int(input())
		ans = 0
		if n >= 6 :
			ans += 1
		for i in range(1, n + 1) :
			ans += d[i]
		print (ans)
	except :
		break
```
