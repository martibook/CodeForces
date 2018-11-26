def main():
    q = int(input())
    for _ in range(q):
        l, r = map(int, input().split())
        n = r - l + 1
        if n % 2 == 0:
            if ai(l) % 2 == 1:
                r = 1 * (n // 2)
            else:
                r = -1 * (n // 2)
        else:
            if ai(l) % 2 == 1:
                r = 1 * (n // 2) + ai(r)
            else:
                r = -1 * (n // 2) + ai(r)
        print(r)


def ai(i):
    return i if i % 2 ==0 else -1 * i


if __name__ == '__main__':
    main()