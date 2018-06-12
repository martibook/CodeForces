def main():
    n, p = map(int, input().split())
    s = list(input())

    no = True
    for i in range(n - p):
        if s[i] == '.' and s[i + p] == '.':
            s[i] = '1'
            s[i + p] = '0'
            no = False
            break
        elif s[i] == '.':
            s[i] = '1' if s[i + p] == '0' else '0'
            no = False
            break
        elif s[i + p] == '.':
            s[i + p] = '1' if s[i] == '0' else '0'
            no = False
            break
        else:
            if s[i] != s[i + p]:
                no = False
                break

    if not no:
        s = ''.join(s).replace('.', '0')
        print(s)
    else:
        print('No')


if __name__ == '__main__':
    main()
