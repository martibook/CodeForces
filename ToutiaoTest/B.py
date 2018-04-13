from math import log
from math import floor


n = int(input())
if n == 1:
    print(0)
else:
    q = floor(log(n, 2))
    rest = n - 2 ** q
    m = 2 ** (q - 1)
    while rest % m != 0:
        q -= 1
        rest = n - 2 ** q
        m = 2 ** (q - 1)

    result = q + rest // m
    print(result)

