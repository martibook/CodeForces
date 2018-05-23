def main():
    n = int(input())
    pos = [int(x) for x in input().split()]
    pos = sorted(pos)

    odd_pos = [x for x in range(1, n+1, 2)]
    even_pos = [x for x in range(2, n+1, 2)]

    odd_move = sum([abs(x - y) for x, y in zip(odd_pos, pos)])
    even_move = sum([abs(x - y) for x, y in zip(even_pos, pos)])

    print(min(odd_move, even_move))


if __name__ == '__main__':
    main()