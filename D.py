from math import sqrt


def gen_prime(N):
    prime = []
    l = [i for i in range(2, N)]
    while len(l) > 0:
        prime.append(l[0])
        l = [x for x in l[1:] if x % prime[-1] != 0]
    return prime


def gen_pfactor(n):
    f = []
    x = n
    for i in range(2, n+1):
        add = False
        while x % i == 0:
            x /= i
            add = True
        if add:
            f.append(i)
        if x <= 1:
            break
    return f


def main():
    N = int(1E5)
    prime = gen_prime(N)
    n = int(input())
    a = [int(x) for x in input().split()]
    used = dict(zip(prime, [False for i in range(len(prime))]))
    b = []
    ai = 0
    while ai < len(a):
        e = a[ai]
        pfs = gen_pfactor(e)
        any_used = [1 if used[pf] else 0 for pf in pfs]
        if sum(any_used) > 0:
            ele = 1
            pi = 0
            while ele < e:
                while used[prime[pi]]:
                    pi += 1
                ele *= prime[pi]
                used[prime[pi]] = True
            b.append(ele)
            ai += 1
            break
        else:
            b.append(e)
            for pf in pfs:
                used[pf] = True
            ai += 1
    pi = 0
    while ai < n:
        while used[prime[pi]]:
            pi += 1
        b.append(prime[pi])
        used[prime[pi]] = True
        ai += 1

    print(' '.join([str(e) for e in b]))


if __name__ == "__main__":
    main()
