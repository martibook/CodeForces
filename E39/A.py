n = int(input())
a = [int(x) for x in input().split()]

B = [x for x in a if x >= 0]
C = [x for x in a if x < 0]
print(sum(B) - sum(C))
