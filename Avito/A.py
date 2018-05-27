def pa(t):
    for i in range(len(t) // 2):
        if t[i] != t[len(t)-i-1]:
            return False
    return True


def main():
    s = input()
    ans = 0
    for i in range(len(s)):
        for j in range(len(s)):
            t = s[i:j+1]
            if not pa(t):
                if len(t) > ans:
                    ans = len(t)
    print(ans)


if __name__ == '__main__':
    main()
