import sys

R, x1, y1, x2, y2 = map(int, input().split())

d = ((x1-x2)**2 + (y1-y2)**2)**.5

if d > R:
    print(x1, y1, R)

elif d == 0:
    # x1, y1 只能减去它们自己方向上的分量，而不能都减去R/2
    print(x1-R/2, y1, R/2)

else:
    r = (R + d)/2
    x = x2 + (x1 - x2)/d * r
    y = y2 + (y1 - y2)/d * r
    print(x, y, r)

