s = input()
l = list(s)
t = 'abcdefghijklmnopqrstuvwxyz'

i = 0
n = len(l)
impossible = False
for c in t:
    for j in range(i, n):
        if l[j] <= c:
            l[j] = c
            i = j + 1
            break
    else:
        impossible = True

if impossible:
    print(-1)
else:
    print(''.join(l))
