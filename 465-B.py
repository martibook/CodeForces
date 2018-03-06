n = int(input())
S = input()

wall = 0
fafa = 0
coin = 0

if S[0] == 'U':
    side = -1
else:
    side = 1

for i in range(n):

    if S[i] == 'U':
        wall += 1
    if S[i] == 'R':
        fafa += 1

    if side * (fafa - wall) < 0:
        coin += 1
        side = fafa - wall


print(coin)
