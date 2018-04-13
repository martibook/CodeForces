def main():
    n, a, b = map(int, input().split())
    s = input()

    ans = 0
    dot = 0
    while dot < len(s):
        ast = s.find('*', dot)
        if ast == -1:
            ast = len(s)
        seats = ast - dot
        if seats % 2 == 0:
            da = min(seats // 2, a)
            db = min(seats // 2, b)
            a, b = a - da, b - db
            ans += da + db
        else:
            if a > b:
                da = min(seats // 2 + 1, a)
                db = min(seats // 2, b)
                a, b = a - da, b - db
                ans += da + db
            else:
                da = min(seats // 2, a)
                db = min(seats // 2 + 1, b)
                a, b = a - da, b - db
                ans += da + db
        dot = ast + 1
    print(ans)


if __name__ == '__main__':
    main()


