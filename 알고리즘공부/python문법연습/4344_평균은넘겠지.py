c = int(input())

for i in range(c):
    s = list(map(int, input().split()))
    avg = (sum(s) - s[0]) / s[0]
    cnt = 0
    for j in range(1,len(s)):
        if s[j] > avg:
            cnt += 1
    print('%0.3f%%' %round(cnt * 100 / s[0],3))