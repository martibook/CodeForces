n, a, b = map(int, input().split())
d = abs(a - b)

round = 1
n -= 1
while d != 1:
    n //= 2
    d //= 2
    round += 1

if d == n:
    print('Final!')
else:
    print(round)
