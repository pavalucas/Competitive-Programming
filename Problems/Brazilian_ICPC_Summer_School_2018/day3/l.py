n = int(input())
ini = "9" * (n-1) + "8"
fim = str(int(ini) + 1)
ini = int(ini + ini) + 1
fim = int(fim + fim) -1
print(ini)
print(fim)
