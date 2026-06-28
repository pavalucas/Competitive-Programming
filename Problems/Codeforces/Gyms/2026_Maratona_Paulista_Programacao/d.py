n = int(input())
max_len = n + n + 1 + n + n + 1
linhas = []
for i in range(2*n+1):
    linhas.append(' ' * max_len)
    
linhas[0] = linhas[0][:n] +  '_' * (n+1)
for i in range(n):
    linhas[i+1] = linhas[i+1][:n-1-i] + '/' + linhas[i+1][n-1-i:2*n+i] + '\\'
    
linhas[n] = linhas[n][:1] + n * "_" + linhas[n][n+1:] + (n+1) * "_"

for i in range(n):
    linhas[n+i+1] = linhas[n+i+1][:n+1+i] + '\\' + linhas[n+i+1][n+2+i:max_len-i-1] + '/'
linhas[-1] = linhas[-1][:2*n+1] + '_' * (n+1) + linhas[-1][2*n+1+n+1:]

for i in range(2*n+1):
    print(linhas[i])