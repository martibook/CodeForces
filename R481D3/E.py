def main():
    n, w = map(int, input().split())
    changes = [int(x) for x in input().split()]
    lowest = highest = pos = 0
    for c in changes:
        pos += c
        if pos > highest:
            highest = pos
        if pos < lowest:
            lowest = pos

    upperb = w - highest + 1
    lowerb = 0 - lowest
    if upperb <= lowerb:
        print(0)
    else:
        print(upperb - lowerb)


if __name__ == '__main__':
    main()
