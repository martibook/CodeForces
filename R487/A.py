def main():
    s = input()
    com = ['ABC', 'ACB', 'BAC', 'BCA', 'CAB', 'CBA']
    for c in com:
        if c in s:
            print('Yes')
            break
    else:
        print('No')


if __name__ == '__main__':
    main()
