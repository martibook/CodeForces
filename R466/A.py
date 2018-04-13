n, d = map(int, input().split())
x = [e for e in map(int, input().split())]

x = sorted(x)

max_contain = 0
for i in range(n):
    head = x[i]
    tail = head + d
    contain = 0
    for j in range(n-i):
        if x[i+j] <= tail:
            contain += 1
        else:
            break
    max_contain = contain if contain > max_contain else max_contain

print(n-max_contain)

"""!! 计算数列中元素的个数可以使用下标相减啊 !!"""
