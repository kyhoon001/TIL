n,t = input().split()
n = int(n)
t = int(t)
a = input().split()
for i in range(n) :
    a[i] = int(a[i])
    if a[i] < t :
        print(a[i], end=' ')


#다른 사람 알고리즘 .  list와 map을 사용하였음
a1, a2 = map(int, input().split())
b = list(map(int, input().split()))

for i in b:
    if i < a2:
        print(i, end=" ")