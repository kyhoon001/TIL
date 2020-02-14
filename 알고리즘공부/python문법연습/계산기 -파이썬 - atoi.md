# 계산기 -파이썬 - atoi

```python
import sys
input = lambda: sys.stdin.readline().rstrip()


for tc in range(1,11):
    p = int(input())
    s = input()
    op = []
    cnt = []

    for i in range(p) :
        # print(ord(s[i]) - ord('0'))
        if ord(s[i]) - ord('0') >= 0 and ord(s[i]) - ord('0') <= 9 :
            cnt.append(s[i])
            # print(ord(s[i]))
        elif s[i] == '(' :
            op.append(s[i])
        elif s[i] == ')' :
            while len(op) != 0 and op[len(op)-1] != '(' :
                # print(op)
                cnt.append(op[len(op)-1])
                op.pop()
            op.pop()
        elif s[i] == '+' :
            while len(op) != 0 :
                if op[len(op)-1] == '(' :
                    break
                cnt.append(op[len(op)-1])
                op.pop()
            op.append(s[i])
        elif s[i] == '*' :
            while len(op) != 0 and op[len(op)-1] != '+' and op[len(op)-1] != '(' :
                cnt.append(op[len(op)-1])
                op.pop()
            op.append(s[i])
    while len(op) != 0 :
        cnt.append(op[len(op)-1])
        op.pop()

    # print(cnt)

    num = []

    for i in range(len(cnt)) :
        if ord(cnt[i]) - ord('0') >= 0 and ord(cnt[i]) - ord('0') <= 9 :
            num.append(int(cnt[i]))
        elif cnt[i] == '+' :
            num1 = int(num.pop())
            num2 = int(num.pop())
            num.append(num1 + num2)
        elif cnt[i] == '*' :
            num1 = int(num.pop())
            num2 = int(num.pop())
            num.append(num1 * num2)


    cnt = int(num[0])

    print("#{0} {1}".format(tc, cnt))
```

