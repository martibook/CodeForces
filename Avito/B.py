def main():
    n = int(input())
    a = set()
    x = dict()
    for _ in range(n):
        ele, inc = map(int, input().split())
        a.add(ele)
        x[ele] = inc

    m = int(input())
    b = set()
    y = dict()
    for _ in range(m):
        ele, inc = map(int, input().split())
        b.add(ele)
        y[ele] = inc

    both = a & b
    only_a = a - both
    only_b = b - both

    income = 0
    income += sum((x[ele] for ele in only_a))
    income += sum((y[ele] for ele in only_b))
    income += sum((max(x[ele], y[ele]) for ele in both))

    print(income)


if __name__ == '__main__':
    main()
