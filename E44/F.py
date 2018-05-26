# though it runs time limit exceeded I think it's a right solution
from string import ascii_lowercase


def main():
    n, m = map(int, input().split())
    s = input()

    M = int(pow(2, 30))
    h = {ch: [0 for _ in range(n + 1)] for ch in ascii_lowercase}
    for ch, l in h.items():
        for i, e in enumerate(s, 1):
            if e == ch:
                l[i] = ((l[i - 1] << 1) + 1) % M
            else:
                l[i] = (l[i - 1] << 1) % M

    p = [1 for _ in range(n + 1)]
    for i in range(1, len(p)):
        p[i] = (p[i - 1] << 1) % M

    a = [0 for _ in range(len(ascii_lowercase))]
    b = [0 for _ in range(len(ascii_lowercase))]
    for _ in range(m):
        x, y, l = map(int, input().split())
        for i, ch in enumerate(ascii_lowercase):
            a[i] = ((h[ch][x + l - 1] - h[ch][x - 1] * p[l]) % M + M) % M
            b[i] = ((h[ch][y + l - 1] - h[ch][y - 1] * p[l]) % M + M) % M
        a = sorted(a)
        b = sorted(b)
        for i in range(len(a)):
            if a[i] != b[i]:
                print('NO')
                break
        else:
            print('YES')


if __name__ == '__main__':
    main()
