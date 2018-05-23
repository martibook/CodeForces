from bisect import bisect_right


def main():
    n, k, l = map(int, input().split())
    a = [int(x) for x in input().split()]
    a = sorted(a)

    m = bisect_right(a, a[0]+l)
    if m < n:
        print(0)
        return

    group = 0
    i = 0
    volume = 0
    while 0 < n - group <= m - i:
        volume += a[i]
        group += 1
        i += k
    if group < n:
        volume += sum(a[m-(n - group):m])

    print(volume)
    return


if __name__ == '__main__':
    main()
