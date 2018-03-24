n, k = map(int, input().split())
nums = [int(x) for x in input().split()]

nums = sorted(set(nums))

sum = 0
for x in nums:
    if (x + k) in nums:
        sum += 1

print(sum)
