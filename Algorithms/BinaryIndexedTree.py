"""binary indexed tree class"""


class BIT:

    def __init__(self, l):
        # len(s) = len(l) + 1
        self.s = [0 for _ in range(len(l) + 1)]
        for i, x in enumerate(l, 1):
            self.update(i, x)

    def __len__(self):
        return len(self.s)

    def lowbit(self, i):
        return i & (-i)

    def update(self, i, x):
        while i <= len(self):
            self.s[i] += x
            i += self.lowbit(i)

    def query(self, *args):
        if len(args) == 1:
            return self.sum_until(*args)
        elif len(args) == 2:
            return self.sum_between(*args)
        else:
            return None

    def sum_until(self, i):
        ans = 0
        while i:
            ans += self.s[i]
            i -= self.lowbit(i)
        return ans

    def sum_between(self, i, j):
        if j < i:
            return None
        return self.sum_until(j) - self.sum_until(i - 1)

    def __getitem__(self, item):
        return self.s[item]


def main():
    l = [1, 2, 3, 4, 5, 6, 7, 8]
    s = BIT(l)
    for i in range(len(l)):
        print(i, s.query(i))
    print(s.query(4, 6))


if __name__ == '__main__':
    main()
