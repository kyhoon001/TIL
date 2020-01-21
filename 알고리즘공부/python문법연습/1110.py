n = num = int(input())
count = 0
while True:
    ten = n // 10
    one = n % 10
    total = ten + one
    count += 1
    n = int(str(n % 10) + str(total % 10))
    if(num == n):
        break
print(count)

#//는 정수 값이 나오는 버림 나누기 연산자이고
#/는 소수점까지 출력하는 나누기 연산자이다.