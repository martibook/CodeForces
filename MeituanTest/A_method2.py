
s = input()
t = input()

ta = sum([1 for e in t if e == 'a'])
tb = sum([1 for e in t if e == 'b'])

ss = 0
for i in range(len(t)):
    a = sum([1 for e in t[:i+1] if e == 'a'])
    b = sum([1 for e in t[:i+1] if e == 'b'])
    if s[i] == 'a':
        ss += b
    else:
        ss += a

for i in range(len(t), len(s) - len(t)):
    if s[i] == 'a':
        ss += tb
    else:
        ss += ta

for i in range(max(len(s) - len(t), len(t)), len(s)):
    a = sum([1 for e in t[-(len(s) - i):] if e == 'a'])
    b = sum([1 for e in t[-(len(s) - i):] if e == 'b'])
    if s[i] == 'a':
        ss += b
    else:
        ss += a

print(ss)
