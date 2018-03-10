r, c = map(int, input().split())
pasture = [list(input()) for i in range(r)]
impossible = False


def fill(tu):
    global impossible
    x, y = tu
    if any((x<0, y<0, x>=r, y>=c)):
        return
    if pasture[x][y] == 'S':
        impossible = True
    if pasture[x][y] == '.':
        pasture[x][y] = 'D'


for i in range(r):
    for j in range(c):
        if pasture[i][j] == 'W':
            for tu in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]:
                fill(tu)

if impossible:
    print('No')
else:
    print('Yes')
    for i in range(r):
        print(''.join(pasture[i]))


