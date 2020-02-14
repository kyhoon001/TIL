# 길찾기 파이썬

- 내 코드

```python
import sys
input = lambda: sys.stdin.readline().rstrip()

cnt = int(0)

for tc in range(1,11):
    t = list(map(int,input().split()))
    p = t[1]

    arr = []
    visit = []
    stack = []
    for _ in range(100):
        b = []
        arr.append(b)

    s = list(map(int,input().split()))

    for i in range(p) :
        arr[s[i * 2]].append(s[(i*2)+1])


    def solve(a) :
        global cnt
        if a == 99 :
            cnt = 1
            return

        for i in arr[a] :
            if i not in visit :
                stack.append(int(i))
                visit.append(int(i))
                solve(i)
                if cnt == 1 :
                    return
                stack.pop()
                visit.remove(i)
    cnt = 0
    solve(0)

    print("#{0} {1}".format(tc, cnt))
```

