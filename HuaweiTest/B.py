def byte2bits(s):
    int_n = [int(x) for x in list(s[2:])]
    str_n4 = []

    for n in int_n:
        bits4 = []
        while n != 0:
            q, r = divmod(n, 2)
            bits4.append(r)
            n = q
        bits4.reverse()
        l = [0 for i in range(4 - len(bits4))] + bits4
        s = [str(e) for e in l]
        str_n4.append(''.join(s))

    return ''.join(str_n4)


def bits2num(s):
    l = [int(e) for e in list(s)]
    n = 0
    for e in l:
        n = n * 2 + e
    return n


n = int(input())
byte_l = input().split()
s = ''
for b in byte_l:
    s += byte2bits(b)

m = int(input())
start = 0
for i in range(m):
    k = int(input())
    num_str = s[start: start+k]
    print(bits2num(num_str))
    start += k



