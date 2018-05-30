from math import log


def main():
    x, y = map(int, input().split())
    a = y * log(x)
    b = x * log(y)
    print('>' if a > b else '=' if a == b else '<')


if __name__ == '__main__':
    main()
