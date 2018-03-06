
n = int(input())
methods = 0
for l in range(1, n):
    if (n-l) % l == 0:
        methods += 1
print(methods)
