def main():
    n, k, m = map(int, input().split())
    words = ['Zero'] + input().split()
    cost = dict(zip(words, [0] + [int(i) for i in input().split()]))
    for i in range(k):
        size, *group = map(int, input().split())
        l = [cost[words[i]] for i in group]
        mincost = min(l)
        for i in group:
            cost[words[i]] = mincost
    message = input().split()
    ans = sum([cost[w] for w in message])
    print(ans)


if __name__ == "__main__":
    main()
