n = int(input())
cnt = 1
for i in range(n) :
    a = input()
    score = []
    for j in range(len(a)) :

        if a[j] == 'O' :
            score.append(cnt)
            cnt += 1
        elif a[j] == 'X' :
            cnt = 1
    cnt = 1
    print(sum(score))