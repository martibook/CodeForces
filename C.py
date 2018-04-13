from math import sqrt


def permutate(x):
    ll = []
    if len(x) <= 0:
        ll.append([])
    else:
        ll = []
        candi = permutate(x[1:])
        for l in candi:
            ll.append([x[0]] + l)
        ll += candi
    return ll


def main():
    x = input()
    n = len(x)
    perm = [''.join(i) for i in permutate(x) if len(i) > 0]
    perm = [i for i in perm if not i.startswith('0')]
    ans = [i for i in [int(j) for j in perm] if sqrt(i) == int(sqrt(i))]
    if len(ans) > 0:
        it = max(ans)
        print(n - len(str(it)))
    else:
        print(-1)


if __name__ == '__main__':
    main()