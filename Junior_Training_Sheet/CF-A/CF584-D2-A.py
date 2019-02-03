import math
n, t = map(int, input().split())
strAcc = "2"
for i in range(n-1):
    strAcc += "0"

num = int(strAcc) / float(t)
resp = int(math.ceil(num)) * t

if len(str(resp)) != n:
    print(-1)
else:
    print(resp)