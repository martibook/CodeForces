a = int(input())
b = int(input())

d = abs(a - b)
q, r = divmod(d, 2)
tireness = (1 + q) * q

if r == 1:
    tireness += (q + 1)

print(tireness)

