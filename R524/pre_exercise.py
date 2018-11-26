"""
Vasya and Books
http://codeforces.com/contest/1073/problem/B

"""
def main():
    n = int(input())
    a_li = list(map(int, input().split()))
    b_li = list(map(int, input().split()))
    idx = [-1 for _ in range(n + 1)]

    for i in range(n):
        idx[a_li[i]] = i

    move = 0
    take = []
    for v in b_li:
        if idx[v] < move:
            take.append(0)
        else:
            take.append(idx[v] + 1 - move)
            move = idx[v] + 1

    print(' '.join(str(e) for e in take))


if __name__ == '__main__':
    main()