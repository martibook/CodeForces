def main():
    n, H = map(int, input().split())

    if (1 + H) * H // 2 >= n:
        l = 1
        r = H
        while l < r:
            h = (l + r) // 2 + 1
            if (1 + h) * h // 2 > n:
                r = h - 1
            else:
                l = h
        h = r
        rest = n - ((1 + h) * h // 2)
        q, r = divmod(rest, h)
        ans = h + q + (1 if r != 0 else 0)
    else:
        l = H
        r = n
        while l < r:
            h = (l + r) // 2 + 1
            if (H + h - 1) * (h - H) // 2 + (1 + h) * h // 2 > n:
                r = h - 1
            else:
                l = h
        h = r
        rest = n - ((H + h - 1) * (h - H) // 2 + (1 + h) * h // 2)
        q, r = divmod(rest, h)
        ans = (h - H) + h + q + (1 if r != 0 else 0)

    print(ans)


if __name__ == '__main__':
    main()