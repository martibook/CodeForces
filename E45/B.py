def main():
    n, K = map(int, input().split())
    a = [int(x) for x in input().split()]

    a = sorted(a)
    remained = 1
    i = len(a) - 1
    j = i - 1
    while 0 <= j < i:
        if a[i] - a[j] <= K and a[i] != a[j]:
            k = j - 1
            while k >= 0 and a[k] == a[j]:
                k -= 1
            i = j
            j = k
        else:
            remained += 1
            i = j
            j -= 1

    print(remained)


if __name__ == '__main__':
    main()
