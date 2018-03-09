n, m, K = map(int, input().split())
timetable = [input() for i in range(n)]

arrange = dict()
lesson_count = []
dp = dict()

for k in range(K+1):
    dp[k] = 0


for i in range(n):
    s = timetable[i]
    lesson = [0]
    lesson += [t+1 for t in range(m) if s[t] == '1']

    lesson_count.append(len(lesson) - 1)  # except the first element
    for k in range(lesson_count[i]+1):
        during = []
        for l in range(k+1):
            r = k - l
            if l+r < lesson_count[i]:
                during.append(lesson[-(r+1)] - lesson[l+1] + 1)
            else:
                during.append(0)
        arrange[(i, k)] = min(during)

    for k in reversed(range(K+1)):
        choices = []
        for c in range(min(k, lesson_count[i])+1):
            choices.append(dp[k-c] + arrange[(i, c)])
        dp[k] = min(choices)

print(dp[K])
