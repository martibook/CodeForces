n = int(input())
s = input()
short_s = ''
i = 0
while i < n:
    if s[i:i+2] == 'RU' or s[i:i+2] == 'UR':
        short_s += 'D'
        i += 2
    else:
        short_s += s[i]
        i += 1
print(len(short_s))
