s = input()
max_len = 0
max_s = ''
current_len = 0
current_s = ''
for i in range(len(s)):
    if s[i].isdigit():
        current_s += s[i]
        current_len += 1
        if current_len >= max_len:
            max_len = current_len
            max_s = current_s
    else:
        current_len = 0
        current_s = ''

print("{s},{l}".format(s=max_s, l=max_len))
