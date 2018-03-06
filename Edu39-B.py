a, b = map(int, input().split())

while a != 0 and b != 0:
    if a >= 2 * b:
        q, r = divmod(a, b)
        if q % 2 == 0:
            a = r
        else:
            a = b + r
    elif b >= 2 * a:
        q, r = divmod(b, a)
        if q % 2 == 0:
            b = r
        else:
            b = a + r
    else:
        break

print(a, b)
