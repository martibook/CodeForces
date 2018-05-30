def main():
    n = int(input())
    colors = ["purple", "green", "blue", "orange", "red", "yellow"]
    gems = ["Power", "Time", "Space", "Soul", "Reality", "Mind"]
    a = {c: g for c, g in zip(colors, gems)}
    absent = set(colors)
    for _ in range(n):
        c = input()
        absent.remove(c)

    print(len(absent))
    for c in absent:
        print(a[c])


if __name__ == '__main__':
    main()
