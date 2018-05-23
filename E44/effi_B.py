def main():
    n, m = map(int, input().split())
    switches = [int(input(), 2) for _ in range(n)]
    lambs_on = 0
    duplicate_control = 0

    for lambs_turn_on in switches:
        duplicate_control |= lambs_on & lambs_turn_on
        lambs_on |= lambs_turn_on

    if any(lambs_turn_on & lambs_on & ~duplicate_control == 0 for lambs_turn_on in switches):
        print('YES')
    else:
        print('NO')


if __name__ == '__main__':
    main()