n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
denom = 1
for i in range(n):
    denom *= a[i]
num = 0
for i in range(n):
    tmp = 1
    for j in range(i):
        tmp *= min(a[j], k - 1)
    tmp2 = 1
    for j in range(i + 1, n):
        tmp2 *= a[j]
    num += max(0, tmp * (a[i] - k + 1) * tmp2)
r = num / denom
print("{:.15f}".format(r))