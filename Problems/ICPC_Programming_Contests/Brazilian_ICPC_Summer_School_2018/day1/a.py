n = int(input())
vec = []
for i in range(n):
    a,b = map(int, input().split())
    vec.append((a,b))
resp = 0
for i in range(n):
    x1, y1 = vec[i]
    x2, y2 = vec[(i+1)%n]
    resp += x1*y2 - x2*y1
print(abs(resp * 0.5))
