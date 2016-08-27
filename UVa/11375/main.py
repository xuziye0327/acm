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
