n, q = map(int, input().split())
query = [int(input()) for i in range(q)]

# position = dict()
# for x in range(1, n+1):
#     if x <= n // 2:
#         position[2 * x -1] = x
#     else:
#         pos = 2 * ((n - x) + 1) - 1
#         gap = pos
#         while pos < n:
#             pos += gap
#             gap *= 2
#         position[2 * n - pos] = x
#
# for pos in query:
#     print(position[pos])

# as for why, click this http://blog.csdn.net/qq_36797743/article/details/79502298
# bitter python -- always time limit exceeded even when you resolve it right

for x in query:
    while x % 2 == 0:
        x = n + (x // 2)
    print((x + 1) // 2)


