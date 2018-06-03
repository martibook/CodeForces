def main():
    k = int(input())
    d = dict()

    for i in range(1, k + 1):
        n = int(input())
        l = [int(x) for x in input().split()]

        s = sum(l)
        for j in range(n):
            possible_s = s - l[j]
            if possible_s in d:
                p_i, p_j = d[possible_s]
                if p_i != i:
                    print('YES')
                    print(*d[possible_s])
                    print(*(i, j + 1))
                    return
                else:
                    pass
            else:
                d[possible_s] = (i, j + 1)

    print('NO')
    return


if __name__ == '__main__':
    main()
