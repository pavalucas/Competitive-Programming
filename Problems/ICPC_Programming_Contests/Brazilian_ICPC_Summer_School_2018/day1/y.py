n = int(input())
vec = [0] * (n+10)
vec[0] = 0
vec[1] = vec[2] = 1
for i in range(3, n + 1):
    vec[i] = vec[i-1] + vec[i-3]
print(vec[n])
