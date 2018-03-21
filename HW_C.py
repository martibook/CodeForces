def big_int_times(num1, num2):
    minus = False
    if num1.startswith('-'):
        minus = not minus
        num1 = num1[1:]
    if num2.startswith('-'):
        minus = not minus
        num2 = num2[1:]

    x = [int(e) for e in list(num1)]
    x.reverse()
    y = [int(e) for e in list(num2)]
    y.reverse()

    z = [0 for i in range(len(x) + len(y))]
    for i in range(len(x)):
        for j in range(len(y)):
            z[i+j] += x[i] * y[j]

    for i in range(len(z) - 1):
        q, r = divmod(z[i], 10)
        z[i+1] += q
        z[i] = r

    z = [str(e) for e in reversed(z)]
    num = ''.join(z)
    while num.startswith('0') and len(num) > 1:
        num = num[1:]

    if minus and int(num) != 0:
        return '-' + num
    else:
        return num


num1 = input()
num2 = input()
print(big_int_times(num1, num2))
