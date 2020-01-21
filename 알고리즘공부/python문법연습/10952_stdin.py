
while 1 :
    try :
        a, b = map(int,input().split())
        print(a+b)
    except : 
        break
    

## sys의 sydin을 사용한 코드
import sys
 
for line in sys.stdin:
    a, b = map(int, line.split())
    print(a + b)