

def times(a, b):
    la = [int(x) for x in reversed(a)]
    lb = [int(x) for x in reversed(b)]
    lc = [0 for i in range(len(a+b))]
    for i in range(len(a)):
        for j in range(len(b)):
            lc[i+j] += la[i] * lb[j]
    for i in range(len(lc) - 1):
        lc[i+1] += lc[i] // 10
        lc[i] = lc[i] % 10

    c = ''.join([str(x) for x in reversed(lc)])
    return c.lstrip('0')


def plus(a, b):
    la = [int(x) for x in reversed(a)]
    lb = [int(x) for x in reversed(b)]
    lc = [0 for i in range(max(len(a), len(b)) + 1)]
    for i in range(len(a)):
        lc[i] += la[i]
    for i in range(len(b)):
        lc[i] += lb[i]
    for i in range(len(lc) - 1):
        lc[i+1] += lc[i] // 10
        lc[i] = lc[i] % 10

    c = ''.join([str(x) for x in reversed(lc)])
    return c.lstrip('0')


def minus(a, b):
    negative = False
    if len(b) > len(a):
        a, b = b, a
        negative = True

    la = [int(x) for x in reversed(a)]
    lb = [int(x) for x in reversed(b)]
    lc = [0 for i in range(max(len(a), len(b)))]
    for i in range(len(a)):
        lc[i] += la[i]
    for i in range(len(b)):
        lc[i] -= lb[i]
    for i in range(len(lc) - 1):
        if lc[i] < 0:
            lc[i] += 10
            lc[i+1] -= 1
    for i in range(len(lc) - 1):
        lc[i+1] += lc[i] // 10
        lc[i] = lc[i] % 10

    c = ''.join([str(x) for x in reversed(lc)])
    c.lstrip('0')
    if negative:
        return '-' + c
    return c


def flat(n):
    ln = [int(x) for x in reversed(n)]
    for i in range(len(n) - 1):
        ln[i+1] += ln[i] // 10
        ln[i] = ln[i] % 10
    return [str(x) for x in reversed(ln)]



def deal(s):
    s = list(s)
    after_times = []
    i = 0
    while i < len(s):
        if s[i] == '*':
            left = after_times.pop()
            right = s[i+1]
            r = times(left, right)
            after_times.append(r)
            i += 1
        else:
            after_times.append(s[i])
        i += 1

    final = []
    i = 0
    while i < len(after_times):
        if after_times[i] == '+' or after_times[i] == '-':
            left = final.pop()
            right = after_times[i+1]
            pl = left.lstrip('-')
            pr = right.lstrip('-')
            if after_times[i] == '+':
                if not left.startswith('-') and not right.startswith('-'):
                    r = plus(pl, pr)
                elif not left.startswith('-') and right.startswith('-'):
                    r = minus(pl, pr)
                elif left.startswith('-') and not right.startswith('-'):
                    r = minus(pr, pl)
                else:
                    r = '-' + plus(pl, pr)

            else:
                if not left.startswith('-') and not right.startswith('-'):
                    r = minus(pl, pr)
                elif not left.startswith('-') and right.startswith('-'):
                    r = plus(pl, pr)
                elif left.startswith('-') and not right.startswith('-'):
                    r = '-' + plus(pl, pr)
                else:
                    r = minus(pr, pl)

            final.append(r)
            i += 1
        else:
            final.append(after_times[i])
        i += 1

    final_num = flat(''.join(final))
    for i in range(5):
        line = '..'.join([nums[e][i] for e in final_num])
        print(line)


def main():
    n = int(input())
    for i in range(n):
        s = input()
        deal(s)


if __name__ == '__main__':
    nums = dict()
    nums['0'] = ['66666', '6...6', '6...6', '6...6', '66666']
    nums['1'] = ['....6', '....6', '....6', '....6', '....6']
    nums['2'] = ['66666', '....6', '66666', '6....', '66666']
    nums['3'] = ['66666', '....6', '66666', '....6', '66666']
    nums['4'] = ['6...6', '6...6', '66666', '....6', '....6']
    nums['5'] = ['66666', '6....', '66666', '....6', '66666']
    nums['6'] = ['66666', '6....', '66666', '6...6', '66666']
    nums['7'] = ['66666', '....6', '....6', '....6', '....6']
    nums['8'] = ['66666', '6...6', '66666', '6...6', '66666']
    nums['9'] = ['66666', '6...6', '66666', '....6', '66666']
    main()