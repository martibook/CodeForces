n = int(input())
l = [int(x) for x in input().split()]

impossible = False
gaps = set()

for i in range(n - 1):
    gap = abs(l[i+1] - l[i])
    if gap == 1:
        continue
    elif gap > 1:
        gaps.add(gap)
    else:
        impossible = True
        break

if len(gaps) == 0:
    # include the case n == 1
    x = 1
    y = max(l)
elif len(gaps) == 1:
    y = gaps.pop()
    q, r = divmod(max(l), y)
    x = q if r == 0 else (q + 1)
else:
    impossible = True


if not impossible:
    for i in range(n - 1):
        a, b = min(l[i], l[i+1]), max(l[i], l[i+1])
        q, r = divmod(a, y)
        ia = q if r == 0 else (q + 1)
        ja = r if r != 0 else y
        q, r = divmod(b, y)
        ib = q if r == 0 else (q + 1)
        jb = r if r != 0 else y
        if (ib, jb) == (ia+1, ja) or (ib, jb) == (ia, ja+1):
            continue
        else:
            impossible = True
            break

if impossible:
    print('NO')
else:
    print('YES')
    print(x, y)
