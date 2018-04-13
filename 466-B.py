n = int(input())
k = int(input())
A = int(input())
B = int(input())

cost = 0
if k == 1:
    print((n - 1) * A)
else:
    while n != 0:
        q, r = divmod(n, k)
        cost += r * A
        n -= r
        cost += min((n - q) * A, B)
        n = q
    print(cost-A)
