import math

def soma( N ):
    x = (180 * (N - 2)) / N
    alpha = (180 - x) / 2
    beta = 180 - (x / 2) - 90
    x = math.radians(x)
    alpha = math.radians(alpha)
    beta = math.radians(beta)
    l = math.sqrt((4 * math.sin(beta)) / (math.sin(x/2) * N))
    y = (math.sin(x) * (l / 2)) / (math.sin(alpha))
    P = (l + y) / 2
    fator = math.sqrt(P * (P - l/2) * (P - l/2) * (P - y))
    t = 1 - (N * fator)
    res = (N * fator * -1) / ((t - 1) * (1 - t))
    return res

with open('baklava.in', 'r') as f:
    t = int(f.readline())
    for i in range(t):
        n = int(f.readline())
        print("%.5f" % (soma(n) * 10000))