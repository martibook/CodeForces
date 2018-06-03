def idx(s, c, start = 0):
    try:
        return s[::-1].index(c, start)
    except:
        return -1


def main():
    s = input()
    zero_cnt = 0
    while zero_cnt < len(s) - 1 and s[zero_cnt + 1] == '0':
        zero_cnt += 1

    i01 = idx(s, '0')
    i02 = idx(s, '0', i01 + 1)
    i2 = idx(s, '2')
    i5 = idx(s, '5')
    i7 = idx(s, '7')

    r = 666
    if i01 != -1 and i02 != -1:
        r = min(r, i01 + (i02 - 1))
    if i2 != -1 and i5 != -1:
        r = min(r, i2 + i5 - int(i2 > i5) + int((i2 == len(s) - 1 or i5 == len(s) - 1) and zero_cnt))
    if i5 != -1 and i01 != -1:
        # if there are more than 2 0s this one would never be the final answer
        r = min(r, i5 + i01 - int(i5 > i01))
    if i7 != -1 and i5 != -1:
        # 1 and 3 --> 3
        r = min(r, i7 + i5 - int(i7 > i5) + int((i7 == len(s) - 1 or i5 == len(s) - 1) and zero_cnt))

    print(r if r != 666 else -1)


if __name__ == '__main__':
    main()
