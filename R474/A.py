def main():
    s = input()
    if not s.startswith('a'):
        print('NO')
    else:
        na = 1
        while na < len(s) and s[na] == 'a':
            na += 1
        s = s.lstrip('a')

        if not s.startswith('b'):
            print('NO')
        else:
            nb = 1
            while nb < len(s) and s[nb] == 'b':
                nb += 1
            s = s.lstrip('b')

            if not s.startswith('c'):
                print('NO')
            else:
                nc = 1
                while nc < len(s) and s[nc] == 'c':
                    nc += 1

                if nc == na or nc == nb:
                    print('YES')
                else:
                    print('NO')


if __name__ == '__main__':
    main()
