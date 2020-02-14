# magnetic - 파이썬 2차배열

```python
import sys
input = lambda: sys.stdin.readline().rstrip()

for tc in range(1,11):
    n = input()

    arr = [list(map(int,input().split())) for _ in range(100)]
    # 1은 n극 아래로 사라짐
    # 2 는 s극 위로 사라짐

    for j in range(100) :
        for i in range(100):
            if arr[i][j] == 2: #위에서부터 보는데 만약 s극이라면
                arr[i][j] = 0
            elif arr[i][j] == 1:
                break

    for j in range(100):
        for i in range(100):
            if arr[99-i][j] == 2:  # 아래서부터 보는데 만약 s극이라면
                break
            elif arr[99-i][j] == 1:
                arr[99-i][j] = 0

    cnt = int(0)
    tmp = int(1)
    for j in range(100):
        for i in range(100):
            if tmp == 1 and arr[i][j] == 2:
                cnt+=1
                tmp = 2
            elif tmp == 2 and arr[i][j] == 1:
                tmp = 1



    print("#", end="")
    print(tc, end =" ")
    print(cnt)


```

