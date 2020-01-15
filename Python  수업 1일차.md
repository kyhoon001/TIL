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



