def main():
    n = int(input())
    s = input()
    ans = 0
    i = 0
    while i < len(s):
        if s[i] == 'x':
            l = 1
            i += 1
            while i < len(s) and s[i] == 'x':
                l += 1
                i += 1
            ans += l - 2 if l > 2 else 0
        i += 1
    print(ans)


if __name__ == '__main__':
    main()
