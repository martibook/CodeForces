n = int(input())
s = input()

i = 0
op = n
while i < n:
    a = s[i]
    j = s.find(a, i+1)
    max_l = 1
    while j != -1:
        l = j - i
        if s[i: i+l] == s[j: j+l]:
            op = op - l + 1
        if l > max_l:
            max_l = l
        j = s.find(a, j+1)
    i += max_l

print(op)
