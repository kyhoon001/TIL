# Python 수업

- 3일간 진행되는 Python 수업에 대한 간단한 정리자료 
- 코딩도장에서 파이썬 강좌를 참고하면 더 좋다.

##  1일차

- 간단한 환경설정 및 명령어에 대한 수업을 진행하였음.

  -  파이썬 파일 ( ex -> first.py)을   콘솔 환경에서 python first.py라고 입력하여 실행하였음

  ``` 
   import os
   print(os.name)
   결과 : nt
   
   import sys
   sys.platform
   결과 : win32
   
   import platform
   platform.system()
   결과 : Windows
  ```

  

- pip  명령어는 파이썬이 아닌 콘솔 환경에서 실행해야 함

  - 해당 환경에서는 beautifulsoup4를 설치해주었음

    ```
    pip install beautifulsoup4
    pip freeze > requirements.txt (필요한 패키지들을 해당 파일에 저장. )
    pip install -r requirements.txt 를 통해 해당 파일의 패키지들을 설치 가능
    
    python -m pip install --upgrade pip
    ```

    > pip를 통해 설치한 파일의 경로는 다음과 같다.
    >
    > Unix = prefix/lib/pythonx.y/site-packages (/usr/local/lib/pythonx.y/site-packages)
    >
    > Windows = prefix\lib\site-packages (c:\pythonxy\lib\site-packages)



## 관련 설정

- venv 모듈을 사용해 가상환경을 만들어줌

  ```
  python -m venv firstenv => 해당 디렉토리에 firstenv라는 폴더를 만듬
  cd firstenv/scripts  => 디렉토리 이동
  activate.bat => 가상환경 실행
  deactivate.bat => 가상환경 종료
  
  ```

- pycharm 환경에서는 setting 프로젝트에서 가상환경의 인터프리터를 추가해주었음.



## 간단한 문법

1. List

   ```
   li = [1, 11, 3, 4, 'A'] 와 같이 선언할 수 있음.
   ```

   - 리스트는  index, count, remove, reverse, sort 등등 다양한 메서드를 제공함.
   - join()함수를 이용하여 리스트를 문자열로 변환할 수 있음

   ```
   ex) title = ['인생', '은', '너무', '즐겁다']
   print(",".join(title))
   결과 : 인생,은,너무,즐겁다
   ```

   - reverse() : 순서를 바꿔줌, 메모리
   - sort() : 알파벳 순서로 정렬, 메모리

2. Tuple

   ```
   t = 1,  혹은  t = (1,) 등으로 선언할 수 있음.
   ```

   - tuple은 수정이 불가능한 자료형으로, 튜플 멤버를 바꿀 수 없음. 새로운 대입 연산이 불가
   - tuple끼리 더하는건 가능하므로 새로운 멤버를 추가하려면 다른 tuple을 생성해서 연산해야함



- tuple과 list는 서로 변환할 수 있으며 list() 와 tuple()을 사용하여 변환함.
  - li = list(tu)  혹은 tu = tuple(li)  이런 식으로 변환.



3. Dict

   - key와 value 구조로 인덱스를 가지고 있음. 

   ```
   dict1 = {'name':'홍길동','age':22, 'gender': True}  처럼 사용
   print(dict1['name'])  등으로 출력 가능
   ```

   - 맴버쉽 연산자 in과도 사용할 수 있음

   ```
   
   맴버쉽 연산자 in과도 사용할 수 있음
   table = {'홍길동': 3400, '제임스': 1234, '대디': 8332} for name, phone in table.items():     print("{0}: {1}".format(name, phone))
   결과 : 
   홍길동: 3400
   제임스: 1234
   대디: 8332
   ```

   - tuple과도 같이 사용 가능

   ```
   tuple과도 같이 사용 가능
   tuple = ('name', 'age', 'gender')
   >>> dict2 = {tuple : ('one', 23, True)}
   >>> print(dict2, type(dict2))
   {('name', 'age', 'gender'): ('one', 23, True)} <class 'dict'>
   ```



4. set
   - 순서가 없는 객체들의 집합, 수정이 가능한 자료형으로 dict와 비슷하지만 key가 없음.
   - 순서가 없기 때문에 요소 순회시 어떤 값이 나올지 알 수 없음.
   - 멤버쉽 연산자를 사용할 수 있으며 add(), discard() -> 에러 없음,remove() -> 에러 발생, update() -> 세트에 여러 데이터를 추가함, clear() 등의 메서드를 가짐. 수학적 집합 연산 또한 가능하다.



## 2일차

- 반복문
- for 문은 range()와 같이 사용하는 경우가 많다.





- pip install jupyter notebook을 사용하여 jupyter notebook을 설치하였음
- 이후  jupyter notebook --no-browser를 입력하여 실행 가능
  1. activate.bat 을 실행하여 가상환경으로 들어간다.
  2. jupyter를 설치한 다음, 워크스페이스로 사용할폴더를 만들어준다.
  3. 만든 폴더로 이동하여 jupyter notebook을 사용한다.



## 3일차

``sys.stdin, sys.stdout``

	1. sys.stdin import
 	2. stdin.read*()
     - stdin.readline() -> 문장을 입력받음?
     - stdin.readlines() -> 엔터를 입력해도 계속 입력을 받음.

- 입력을 받은 뒤 해당 파일의 글자 개수를 출력하는 코드

```python
from sys import stdin

result = []
for line in stdin.readlines():
    word_list = list(line)
    for _ in range(len(word_list)):
        result.append(word_list.pop())
        
print("파일의 단어수 {}개".format(len(result)))
```

- 엔터를 입력해도 계속 입력을 받음. ctrl + d 를 눌러서 입력을 종료해야함. 파이참에서 실행.



- 절대 경로로 설정을 해줄때는 다음과 같이 해줄 수 도 있다.

  ```python
  import sys
  sys.path.append("C:/Users/multicampus/PycharmProjects/HelloProject")
  ```

  ```python
  import temperatur ## 이렇게 import함.
  ```

- argv 확인하는 것.

  ```python
  import sys
  print(sys.argv) # 를 통해서 확인할 수 있음. 리스트 형식으로 들어옴
  #터미널에서 python hello.py ads gfdsg asd 이런 식으로 전달
  ```



- Pillow를 사용해 보았다.

  ```python
  from PIL import Image
  from IPython.display import display
  imgfile = 'asd.jpg'
  
  pil_im = Image.open(imgfile)
  out = pil_im.transpose(Image.FLIP_TOP_BOTTOM)
  display(out)
  ```

  - 해당 코드는 jupyter notebook에서 실행하였다. Pillow를 이용하여 사진을 컨트롤 하는 연습.







# Python 연습문제

- 간단한 연습문제

## 1일차

- 문제1 : list1 = ['a', 'c', 'd', 'b', 'e'] 라는 리스트를 list1 = ['a', 'b', 'c', 'd', 'e'] 로 만들어 보세요.

```python
list1 = ['a','c','d','b','e']
list1.sort()
print(list1)
list1.reverse()
print(list1)

```



- 문제2 : list2 = ['This', 'is', 'a', 'book.']라는 리스트를 change라는 변수를 사용해서 change = This is a book 라는 문자열을 만들 어 보세요. (join함수 응용)

```python
list2 = ['This','is','a','book.']
change = " ".join(list2)
print(change)
```



- 문제3 : tuple1 = (1, 2, 3, 4) 라는 튜플에 5라는 값을 추가해서 (1, 2, 3, 4, 5) 처럼 만들어 보세요.

```python
tuple1 = (1,2,3,4)
t2 = (5,)
tuple1 += t2
print(tuple1)
```

- 문제4 : dic1 = {'A':90, 'B':80, 'C':70, 'D':60, 'F':50} 에서 ‘D’에 해당 되는 값을 추출한 값은(dic1)에 삭제되는 값은 (dic2)에 넣어 만들어 보세요. (pop 활용하였음)

```python
dict1 = {'A':90, 'B':80, 'C' : 70,'D' : 60, 'F' : 50, }
dict2 = dict1.pop('D')
print(dict2)
print(dict1)
```



## 2일차

1. 

```python
for i in range(0,3) :
    num = input("숫자를 입력하세요: ")

    if int(num) > 0 :
     print(num + "은 양수입니다")
    elif int(num) < 0 :
     print(num + "은 음수입니다.")
    else :
     print(num + "은 양수도 음수도 아닙니다.")
```

2. 

```python
a = 7
while a > 1:
    pp = ''
    for i in range(0,a) :
        pp += '*'

    a -= 1
    print(pp)

```

3. 

```python

while 1 :
    print("구구단 프로그램을 실행합니다.")
    print("1.   홀수 구구단")
    print("2.   짝수 구구단")
    print("3.   종료")
    num = input()
    if int(num) == 1 :
        cnt = 3
        for i in range(0,4) :
            print(str(cnt)+"단")
            for j in range(1,10) :
                result = int(cnt) * int(j)
                print(str(cnt) + " * " + str(j) + " = " + str(result))
            cnt += 2
    elif int(num) == 2:
        cnt = 2
        for i in range(0, 4):
            print(str(cnt) + "단")
            for j in range(1, 10):
                result = int(cnt) * int(j)
                print(str(cnt) + " * " + str(j) + " = " + str(result))
            cnt += 2
    elif int(num) == 3:
        print("프로그램을 종료합니다. ")
        break
```



```python
students=["홍길동","전우치","강감찬","이순신","임꺽정"]
for name in students:
    print("이름 : % s" %name)

fruits = ['apple', 'banana', 'berry', 'yam', 'meron']
i = 0
for i, v in enumerate(fruits):
    print('{0}: {1}'.format(i, v))
    students=["홍길동","전우치","강감찬","이순신","임꺽정"]
for i, name in enumerate(students):
    print("이름 : %s" %name)
    print("번호 : {0}" .format(i))
    print("이름 : {0}" .format(name))
    #print("{0} : {1}.".format(i,name))
    
    
    
##########################################################
seq1 = {'apple', 'banana', 'berry', 'yam', 'meron'}
seq2 = {'사과', '바나나', '딸기', '맛있어', '메론'}
z = zip(seq1, seq2)
print(z)
for idx, (a, b) in enumerate(z):
    print('%d: %s' % (idx, (a, b)))
    print('{0}: {1}'.format(idx,(a,b)))
# 1:1로 매핑이 안 되고 지멋대로 뜨는데, 이는 순서가 없는 set를 사용해서 그럼.
# set가 아닌 순서가 있는 list 등을 사용할 경우 1:1로 매핑이 됨.
############################################################

list = []
for i in range(0,3) :
    num = int(input())
    list.append(num)
list.sort()
print(list[-1])
```



## 3일차

1. 구구단 문제

   ```python
   # 1번 경우
   c = 1
   while c == 1 :
       num1 = int(input())
       num2 = int(input())
       print(num1)
       if 1 <= int(num1) <=9 :
           c = 0
       else :
           print("INPUT ERROR!")
   
   
   for i in range(1,10) :
       print(str(num1) + " * " + str(i) + " = " + str(num1 * i))
   
   
   for i in range(1,10) :
       print(str(num2) + " * " + str(i) + " = " + str(num2 * i))
   
   #1번 끝
   
   
   #2번 경우
   
   
   while(1):
       num = input()
       num1 = num.split(" ")
       if 1 <= int(num1[1]) <= 9 and 1 <= int(num1[0]) <= 9 :
           break
   
   for i in range(1,10) :
       for j in num1 :
           result = int(i) * int(j)
           print("%d * %d = %d" %(int(j), int(i), result), end='\t')
       print(" ")
   
   #2번 경우 끝
   ```

2. 암호화 문제 - 딕셔너리 사용

   ```python
   key = list('abcdefghijklmnopqrstuvwxyz')
   code = list(input())
   
   
   z = zip(key, code)
   result = {}
   # for num in enumerate(z) :
   i = 0
   for i, num in enumerate(code) :
   
       result[key[i]] = num
   result[' '] = ' '
   answer = input()
   for i, text in enumerate(answer) :
       if 97 <= ord(text) <= 122 :
           print(result[text],end='')
       elif 65 <= ord(text) <= 90 :
           print(chr(ord(result[chr(ord(text) + 32)]) - 32),end='')
       elif text == ' ' :
           print(result[text],end='')
   
   
   ```

   