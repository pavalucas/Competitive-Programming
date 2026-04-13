f = open("vasya.in")
inString = f.readline()
f.close()

a, b, k = map(int, inString.split())
coeff = [[a,b]]
if k > 1:
    coeff.append([a*a, 2*a*b, b*b])
for i in range(2,k):
    coeff.append([])
    for c in coeff[i-1]:
        coeff[i].append(a*c)
        coeff[i].append(b*c)

ans = 0
for c in coeff[k-1]:
    ans += c
fw = open("vasya.out", 'w')
fw.write(str(ans))
fw.close()