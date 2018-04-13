def main():
    n = int(input())
    a = [int(x) for x in input().split()]

    s = sum(a)
    day = 0
    count = 0
    while count < s / 2:
        day += 1
        count += a[day - 1]
    print(day)


if __name__ == '__main__':
    main()


