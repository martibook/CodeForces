def main():
    n, m, a, b = map(int, input().split())
    q, r = divmod(n, m)
    if r == 0:
        ans = 0
    else:
        ans = min(r * b, (m - r) * a)
    print(ans)


if __name__ == '__main__':
    main()
