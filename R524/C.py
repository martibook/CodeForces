def main():
    t = int(input())
    for _ in range(t):
        test_case()


def white_inside(a, b, c, d):
    n = d - b + 1
    m = c - a + 1
    if (a % 2 == 1 and b % 2 == 1) or (a % 2 == 0 and b % 2 == 0):
        return ((n + 1) // 2) * ((m + 1) // 2) + (n // 2) * (m // 2)
    else:
        return (n // 2) * ((m + 1) // 2) + ((n + 1) // 2) * (m // 2)


def black_inside(a, b, c, d):
    return cal_area(a, b, c, d) - white_inside(a, b, c, d)


def test_case():
    n, m = map(int, input().split())
    a1, b1, c1, d1 = map(int, input().split())
    a2, b2, c2, d2 = map(int, input().split())
    white = white_inside(1, 1, m, n) + black_inside(a1, b1, c1, d1) - white_inside(a2, b2, c2, d2) - black_inside(*get_incep_rec(a1, b1, c1, d1, a2, b2, c2, d2))
    black = black_inside(1, 1, m, n) - black_inside(a1, b1, c1, d1) + white_inside(a2, b2, c2, d2) + black_inside(*get_incep_rec(a1, b1, c1, d1, a2, b2, c2, d2))
    print(white, black)


def intercep(a1, c1, a2, c2):
    if a2 > c1 or c2 < a1:
        return False
    else:
        return True


def get_incep_rec(a1, b1, c1, d1, a2, b2, c2, d2):
    if intercep(a1, c1, a2, c2) and intercep(b1, d1, b2, d2):
        a, c = list(sorted([a1, c1, a2, c2]))[1:3]
        b, d = list(sorted([b1, d1, b2, d2]))[1:3]
        return a, b, c, d
    else:
        return 0, 0, 0, 0


def cal_area(a, b, c, d):
    return (c - a + 1) * (d - b + 1)


if __name__ == '__main__':
    main()