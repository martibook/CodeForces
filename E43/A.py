def main():
    n = int(input())
    s = input()
    if '1' in s:
        ans = '1' + s.replace('1', '')
    else:
        ans = '0'
    print(ans)


if __name__ == '__main__':
    main()