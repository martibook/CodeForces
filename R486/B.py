def main():
    n = int(input())
    a = []

    for _ in range(n):
        a.append(input())

    a = sorted(a, key=len)

    for i in range(1, n):
        if a[i - 1] in a[i]:
            pass
        else:
            print('NO')
            return
    print('YES')
    for s in a:
        print(s)


if __name__ == '__main__':
    main()
