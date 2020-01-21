 # A,B,C의 값 받기
A = input()
B = input()
C = input()
 # A*B*C의 값 구하기
num = int(A) * int(B) * int(C)
 # 결과값을 배열로 만들기 
num = str(num) # 이렇게 하면 배열이 되나봄
 # count()써서 개수 구하기
for i in range(0, 10):
    print(num.count(str(i)))  #count는 배열에서 해당 숫자가 얼마나
    #나오는지를 계산해서 출력해줌

