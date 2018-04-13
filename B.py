"""
first line: the number of switches -- n
the following n lines
the number of lights each switch controls -- k, and a list of ids of k lights

question: what is the maximum number of lights we can turn on?
"""


def counton(bl, cl):
    if None in bl:
        return -100000000000
    l = [not bl[i] if i in cl else bl[i] for i in range(len(bl))]
    return l.count(True)


def countoff(bl):
    return bl.count(True)


def turnon(bl, cl):
    return [not bl[i] if i in cl else bl[i] for i in range(len(bl))]


def main(inputn, inputcontrol):
    n = inputn
    C = sum([i for i in range(1, n+1)])
    links = [[]]
    F = 1
    for i in range(n):
        control = [int(x) for x in inputcontrol[i].split()[1:]]
        F = max(F, max(control))
        links.append(control)

    dp = [[None] * (F+1)] * (C + 1)
    dp[0] = [False] * (F+1)
    for i in range(1, n+1):
        cl = links[i]
        for c in range(C, i-1, -1):
            if counton(dp[c-i], cl) >= countoff(dp[c]):
                dp[c] = turnon(dp[c-i], cl)
        print('i = ', i)
        for l in dp:
            print(l)
        print('-'*80)

    print(max([countoff(l) for l in dp]))


if __name__ == '__main__':
    n = 5
    control_list = ['1 1', '2 1 2', '3 1 2 3', '4 1 2 3 4', '5 1 2 3 4 5']
    main(n, control_list)