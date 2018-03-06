n, k = map(int, input().split())
s = list(input())
sets = sorted(list(set(s)))


def bigger_one(c):
    for e in sets:
        if e > c:
            return e


if k > n:
    print(''.join(s) + (k - n) * sets[0])
else:
    t = s[0:k]
    for i in reversed(range(k)):
        if bigger_one(t[i]):
            t[i] = bigger_one(t[i])
            break
        else:
            t[i] = sets[0]
            continue
    print(''.join(t))
