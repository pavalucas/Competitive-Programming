def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

def lcm(a, b):
    if a == 0 and b == 0:
        return 0
    return a // gcd(a,b) * b

n = int(input())
resp = 1
for i in range(2,n+1):
    resp = lcm(resp, i)
print(resp)

