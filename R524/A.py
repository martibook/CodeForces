def main():
   n, k = map(int, input().split())
   v = cal(2, n, k) + cal(5, n, k) + cal(8, n, k)
   print(v)


def cal(m, n, k):
    return m * n // k + int(m * n % k != 0)


if __name__ == '__main__':
    main()