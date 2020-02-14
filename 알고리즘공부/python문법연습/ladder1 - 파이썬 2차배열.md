# ladder1 - 파이썬 2차배열

```python
import sys
input = lambda: sys.stdin.readline().rstrip()

for _ in range(10):
    n = input()

    arr = [list(map(int,input().split())) for _ in range(100)]

    tmpb = int(0)
    tmpa = int(99)
    for i in range(100):
        if arr[99][i] == 2:
            tmpb = i

    while 1:
        arr[tmpa][tmpb] = 3
        if arr[tmpa][tmpb-1] ==1 and tmpb != 0 :
            tmpb -= 1

        if  tmpb != 99 and arr[tmpa][tmpb+1] == 1:
            tmpb += 1

        if arr[tmpa -1][tmpb] == 1 and tmpa != 0:
            tmpa-=1

        if tmpa == 0:
            print("#", end="")
            print(n, end =" ")
            print(tmpb)
            break;


```

