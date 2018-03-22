def main():
    s = input()
    num = {str(n): 0 for n in range(10)}
    for e in s:
        num[e] += 1
    num['0'] += 1

    num_list = [(e, v) for e, v in num.items()]
    num_list = sorted(num_list, key=lambda x:(x[1], x[0]))
    lack_c, lack_n = num_list[0]

    if lack_c == '0':
        other_list = sorted([x[0] for x in num_list if x[1] > 0 and x[0] != '0'])
        other_smallest = other_list[0]  # must exist
        print(other_smallest + lack_c * lack_n)
    else:
        print(lack_c * (lack_n + 1))


if __name__ == '__main__':
    main()

