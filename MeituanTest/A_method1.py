

def distance(a, b):
    di = [1 for i in range(len(a)) if a[i] != b[i]]
    return sum(di)


def main():
    s = input()
    t = input()
    l = len(t)
    dis = [distance(s[i: i+l], t) for i in range(len(s) - l + 1)]
    print(sum(dis))


if __name__ == '__main__':
    main()


