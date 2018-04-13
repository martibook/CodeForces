from math import log
from math import floor


def main():
    X, d = map(int, input().split())
    n = 0
    l = []
    v = 1
    while X > 0:
        m = floor(log((X+1), 2))
        l += [v] * m
        n += m
        v += d
        X -= (2**m - 1)

    print(n)
    print(' '.join([str(x) for x in l]))


if __name__ == '__main__':
    main()