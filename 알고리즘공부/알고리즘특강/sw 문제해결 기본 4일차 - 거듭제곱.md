# s/w 문제해결 기본 4일차 - 거듭제곱

```python
for t in range(10):
    case = input()
    n = input().split(" ")

    def solve(a, b, sum):
        if int(a) != int(b):
            sum *= int(n[0])
            solve(int(a+1), int(b), sum)
        else:
            print("#%s %s"%(t+1,sum))
    solve(1, int(n[1]), int(n[0]))
```

