def main():
    n, m = map(int, input().split())
    rows = []
    s = [0 for _ in range(m)]
    for _ in range(n):
        l = [int(x) for x in list(input())]
        rows.append(l)
        s = [x + y for x, y in zip(s, l)]

    for l in rows:
        r = [x - y for x, y in zip(s, l)]
        if r.count(0) == 0:
            print('YES')
            return
    else:
        print('NO')
        return



if __name__ == '__main__':
    main()