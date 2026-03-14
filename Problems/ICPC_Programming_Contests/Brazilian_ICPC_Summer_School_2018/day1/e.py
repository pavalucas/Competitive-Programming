def solve(n):
    if n == 1:
        return [[1]]
    l = []
    for p in solve(n-1):
        l.append([1] + p)
        if len(p) == 1:
            l.append([p[0] + 1])
        elif p[1] > p[0]:
            l.append([p[0] + 1] + p[1:])
    return l

k = int(input())
l = solve(k)
for p in reversed(l):
    a = len(p)
    for i in range(a):
        if i == a - 1:
            print(p[a-i-1], end='')
        else:
            print("%d+" % p[a-i-1], end='')
    print()
