def main():
    n = int(input())
    arr = [int(x) for x in input().split()]
    s = set()
    narr = []
    for x in arr[::-1]:
        if x not in s:
            narr.append(x)
            s.add(x)
    narr = narr[::-1]
    print(len(narr))
    print(' '.join([str(x) for x in narr]))


if __name__ == '__main__':
    main()
