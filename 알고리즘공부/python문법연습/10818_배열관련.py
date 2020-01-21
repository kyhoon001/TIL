num = int(input())
numbers = list(map(int,input().split()))

maxno = numbers[0]
minno = numbers[0]

for i in numbers :
    if i > maxno :
        maxno = i
    elif i < minno :
        minno = i

print(minno, maxno)