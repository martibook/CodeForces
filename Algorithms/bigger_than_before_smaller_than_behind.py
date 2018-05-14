"""given a list, find those items which are bigger than all items before them and smaller than all items behind them"""


def gen_max_until(l):
    """current item not included"""
    x = l[0] - 1
    for e in l:
        yield x
        x = max(x, e)


def gen_min_until(l):
    x = l[0] + 1
    for e in l:
        yield x
        x = min(x, e)


def main():
    l = [int(x) for x in input().split()]
    max_until = [x for x in gen_max_until(l)]
    min_after = [x for x in gen_min_until(l[::-1])][::-1]

    for i in range(len(l)):
        if max_until[i] < l[i] < min_after[i]:
            print(l[i])


if __name__ == '__main__':
    main()
