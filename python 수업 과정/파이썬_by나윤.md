### 프로그래밍언어

(3형식)

1. 저장
   1. 무엇을 저장하는가?
      - 모든 숫자(글자 섞이면 노노)
      - 기본적인 연산이 가능(계산기)
      - 모든 글자(따옴표로 둘러싼 글자,숫자)
      - 참/거짓(조건, 반복에 사용됨)
2. 조건
3. 반복

***

**변수 안에 어떠한 값을 할당한다.**



`print(greeting)` = greeting 변수 안에 담긴 내용을 출력해주세요..

`print("greeting")` = "greeting"이라는 글자를 출력해주세요..



- 리스트

  - dust = [1,2,3]

    print(dust[1])

    ​	==>>2가 출력



- 딕셔너리
  - {key:value}
  - print(dictionary("key"))
    - ===>value값 출력

***

`*` 조건문 작성시 탭키 공간 확보 굉장히 중요!!

ex) if dust>50:

​	  ^^^^print("50 초과")

ex)dust = [59, 24, 102, 45,64] 

​	 n = 0

​	 while n < 3 :

​	  ^^^^print(dust[n])

​	  ^^^^n = n+1

==>>>>59, 24, 102, 출력

***

- **반복 for 문**

  =>정해진 범위를 반복, *종료조건 필요 없음*

- **반복 while True문**

  =>조건이 True가 될때까지 반복, *종료조건 필!수!*



**예시 문제**

1. dust라는 변수에 농도가 API로부터 받은 정보가 저장되어있다.
2. 기상청에 미세먼지 농도 등급은 아래와 같다. 
   - 조건문과 출력하는 법을 통하여 코드를 작성하라!
     - ex)55, 보통
     - 미세먼지 농도/등급
     - 151~/매우나쁨
     - 81~150/나쁨
     - 30~80/보통
     - ~29/좋음

```python
dust = 87
if dust >151:
    print("매우나쁨")
elif 80<dust<=150:
    print("나쁨")
elif 30<dust<=80:
    print("보통")
else :
    print("좋음")
```

(파이썬 챗봇 페이지에 들어가서 직접 실습, 실행함)

- 웹과의 커뮤니케이션 방식
  - 요청과 응답
  - API(서버들간의 대화 방식)

***



### random 함수

import random

random.choice(리스트)

ex)

menu =["솜사탕","국밥","마파두부"]

choice = ramdom.choice(menu)

print(choice)



- random.choice(menu)

  > -리스트에서 임의적으로 하나의 요소를 선택.

- random.sample

  > -리스트에서 특정 수의 요소를 임의적으로 비복원 추출

  ​	ex)ramdom.sample(numbers,6)

  ​	*중복되지 않는 6개의 숫자가 랜덤으로 나오게 됨.

***

### 웹브라우저 조작

import webbrowser

1. webbrowser.open(주소)
2. webbrowser.open_new(주소)
3. webbrowser.open_new_tab(주소)

***

### 원하는 정보 스크랩해오기

`import requests`

1. requests.get(주소)
2. requests.get(주소).text



`BeautifulSoup`(문서, 타입)

- soup = BeautifulSoup(response, "html.parser")



`.select(selector)`

- 문서 안에 있는 특정 내용을 뽑아줘!!!

  soup.select(response)

`.select_one(selector)`

- 문서 안에 있는 특정 내용을 하나만 뽑아봐



request.함수

요청한 정보를 뽑아오는 것



정보 스크랩 순서

soup=>select=>print



#### 예시문제

**로또 정보를 출력해오자!**

```python
import requests
import random
from bs4 import BeautifulSoup

# 888회 로또 API 가져오기


res = requests.get('https://www.dhlottery.co.kr/common.do?method=getLottoNumber&drwNo=888')
lotto = res.json()
#request한 url에서 json형태로 정보를 출력
print(lotto)

# 그중에서 당첨번호 6개만 가져오기
winner = []
for i in range(1,7):
    winner.append(lotto[f'drwtNo{i}'])
    
#랜덤으로 로또번호 생성하기
numbers = random.sample(range(1,46),6)
print(numbers)
#실제 당첨번호와 랜덤으로 생성한 로또 번호의 일치하는 정도에 따른
# 등수 표시하기
matched = 0
for num in numbers:
    if num in winner:
        matched +=1
if matched == 6:
    print('1등입니다')
    if lotto['bnusNo'] in numbers:
        print('2등입니다')
    else:
        print('3등입니다')
elif matched ==4:
    print('4등입니다')
elif matched ==3:
    print('5등입니다')
else:
    print('다음 기회에..')
#1등 당첨되기 위해서 구입해야 하는 로또 갯수 구하기
matched = 0
for num in numbers:
    if num in winner:
        matched +=1
cnt =0
while matched<6:
    numbers = random.sample(range(1,46),6)
    matched = 0
    matched = 0
    for num in numbers:
        if num in winner:
            matched +=1
    cnt +=1
    print(cnt)
    print(winner)
    print(numbers)
```



***

## 12월 12일

***

##### DICTIONARY

#key 값만

```python
for key in area_code.keys():
     print(key)
```

#key와 value값을 각각 

```python
for key, value in area_code.items():
    print(key, value)
```

#value값만

```python
for value in area_code.values():
    print(value)
```

######  예시문제

1. 딕셔너리 value 값 평균 구하기

```python
score = {
    '수학': 80,
    '국어': 90,
    '음악': 100
}

sum_score = 0
for s in score.values():
    sum_score += s
result = sum_score/len(score)
print(result)
```



2. 다중 딕셔너리 value 값 평균 구하기

```python
scores = {
    'a': {
        '수학': 84,
        '국어': 90,
        '음악': 92
    },
    'b': {
        '수학': 83,
        '국어': 91,
        '음악': 77
    }
}
for person_score in scores.values():
    for subject_score in person_score.values():
        sum_score += subject_score
        count += 1
result = sum_score/count
print(result)
```



** 딕셔너리 내에 두 개의 딕셔너리가 존재하기 때문에 for문을 두번 돌아줘야함

3.  다중 딕셔너리 평균 값 및 요소 출력

   ```python
   city = {
       '서울': [-6, -10, 5],
       '대전': [-3, -5, 2],
       '광주': [0, -2, 10],
       '부산': [2, -2, 9],
   }
   
   # 3-1. 도시별 최근 3일의 온도 평균은?
   for key, value in city.items():
       temps = 0
       for t in value:
           temps += t
       temp = temps/len(value) 
       print(f'{key}:{temp}')   
   
   
   # 3-2. 도시 중에 최근 3일 중에 가장 추웠던 곳, 가장 더웠던 곳은?
   count = 0
   for key, value in city.items():
       #최초 시작시에만 작용되는 조건들
       if count ==0:
           hot_temp = max(value)
           cold_temp = min(value)
           hot_city = key
           cold_city = key
           count += 1
       else:
           if max(value)>hot_temp:
               hot_temp = max(value)
               hot_city = key
           if min(value)<cold_temp:
               cold_temp = min(value)
               cold_city = keyl
   
   print(f'가장 추운 곳은 {cold_city}이고, {cold_temp}도 이다. 가장 따뜻한 곳은 {hot_city}이며 {hot_temp}도 이다')
   
   
   # 3-3. 위에서 서울은 영상 2도였던 적이 있나요?
   if 2 in city['서울']:
       print("예!!")
   else:
       print('아뇨????')
   ```

***

##### 딕셔너리 심화 연습 문제

```python
import random

t4ir_6th = {
    'division': ['머신러닝', '빅데이터', 'IoT', 'VR'],
    'language': {
        'python': {
            'python standard library': ['os', 'random', 'webbrowser'],
            'frameworks': {
                'flask': 'micro',
                'django': 'full-functioning'
            },
            'data_science': ['numpy', 'pandas', 'scipy', 'sklearn'],
            'scraping': ['requests', 'bs4'],
        },
        'web' : ['HTML', 'CSS']
    },
    'classes': {
        '1305': {
            'lecturer': 'justin',
            'manager': '문주영',
            'class president': '문한나',
            'groups': {
                'A': ['문한나', '박나영', '김연주'],
                'B': ['백대현', '김완규', '윤동현'],
                'C': ['장민재', '강현수', '강동욱', '장하림'],
                'D': ['김이슬', '최희은', '전국현', '한상윤'],
                'E': ['최여진', '조현민', '김나윤','김영훈', '유한솔']
            }
        },
        '503': {
            'lecturer': 'change',
            'manager': '신윤미'
        }
    }
}


"""
난이도* 1. 반 분류(division)는 몇 개 있나요?
출력예시)
4
"""
print(len(t4ir_6th['division']))

"""
난이도** 2. python standard library에 'requests'가 있나요?
출력예시)
False
"""
print('request' in t4ir_6th['language']['python']['python standard library'])

"""
난이도** 3. 1305호의 반장의 이름을 출력하세요.
출력예시)
문한나
"""
print(t4ir_6th['classes']['1305']['class president'])

"""
난이도*** 4. t4ir에서 배우는 언어들을 출력하세요.
출력 예시)
python
web
"""
for lang in t4ir_6th['language'].keys():
    print(lang)

"""
난이도*** 5 t4ir 503호의 강사와 매니저의 이름을 출력하세요.
출력 예시)
change
신윤미
"""
for name in t4ir_6th['classes']['503'].values():
    print(name)

"""
난이도***** 6. framework 들의 이름과 설명을 다음과 같이 출력하세요.
출력 예시)
flask는 micro이다.
django는 full-functioning이다.
"""
frameworks = t4ir_6th['language']['python']['frameworks']

#첫번째 방법
for name in frameworks:
    print(f'{name}는 {frameworks[name]}이다.')
#두번째 방법
for key, value in frameworks.items():
    print(f'{key}는 {value}이다')    
"""
난이도***** 7. 오늘 당번을 뽑기 위해 groups의 E 그룹에서 한명을 랜덤으로 뽑아주세요.
출력예시)
오늘의 당번은 최여진
"""

print(random.choice(t4ir_6th['classes']['1305']['groups']['E']))
```

***

***

#### FLASK와 VENV

- pip install Flask

- **FLASK란?**

  - 웹 Framework

  - 폴더를 Flask로 시작하게 안 만들도록 주의(프로그램과 충돌)

  - ex) Flask를 이용하여 웹에서 'Hello Word'를 띄우도록 하는 예시

    ```python
    from flask import Flask
    app = Flask(__name__)
    
    @app.route('/')
    def hello():
        return 'Hello World!'
    ```

    

- pip -m venv venv
  - `source venv/Scripts/activate`(활성화)
  - `deactivate`(비활성화)
  - 다른 프로그램과의 충돌을 방지하기 위해 가상환경 구축하는 코드
  - `pip list` 명령어를 통해 가상환경인지 아닌지 구분 가능
  - venv 폴더가 자동으로 생성

***

### Flask 앱 실행 코드

1. `$ FLASK_APP=hello.py flask run`

2. 더 쉬운 실행 코드 방법

   - GIT BASH 접속

   `$ touch .bashrc`

   `$ vi .bashrc` => (끼워넣기, 편집 코드)

   - `export FLASK_APP=hello.py` (작성하고 :wq로 나가주고)
     - 원래 디폴트 값은 export FLASK_APP = app.py
   - VS CODE로 돌아와서

   `$ source ~/.bashrc
   (venv)`

   `$ flask run`

3. .py 파일을 수정을 할 때 마다 서버를 Ctrl+C로 나가주고, 새로고침하고 쓸수 있는 코드 

   > `$ flask run`

4. 서버 새로고침 안하고 바로 반영되도록 실행하는 코드

   > `$python hello.py`

***

### render_template

> 템플릿에 사용되는 파일들은 `templates` 디렉터리에 저장되며 일반적으로 .html 파일을 사용합니다. 
>
> 또한 css 같은 파일들은 `static` 디렉터리에 저장합니다. 
>
> 어플리케이션 상에서 이러한 html 파일들을 렌더링할 수 있도록 Flask에서는 `render_template`를 제공하는데요.
>
>  [Jinja2](http://jinja.pocoo.org/) 템플릿 엔진을 사용해서 html 문서 내에 코드 조각들을 삽입하여 웹 페이지를 동적으로 생성할 수 있습니다.

ex)순서대로 app.py 파일과 greeting.html 파일의 소스코드

```python
@app.route('/greeting/<name>')
def greeting(name):
    return render_template('greeting.html', html_name=name)
```

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset='utf-8'>
    <meta http-equiv='X-UA-Compatible' content='IE=edge'>
    <title>Page Title</title>
    <meta name='viewport' content='width=device-width, initial-scale=1'>
    <link rel='stylesheet' type='text/css' media='screen' href='main.css'>
    <script src='main.js'></script>
</head>
<body>
    <!--jinja template 안 쓴것-->
    <!-- <h2>{{  html_name    }}님 반갑습니당</h2> -->
    
    <!--jinja2 template 쓴것-->
    {% if html_name == 'juan'%}
        <h2>{{html_name}}이니ㅣㅣ????</h2>
    {% else %}
        <h2>{{html_name}}님 오셨습니까요..</h2> 
    {%endif%}       
</body>
</html>
```

***

***

### 챗봇

https://api.telegram.org/bot993104124:AAGn6gMcpzhwy83b3TNK5tFQz5ianyoGoHk/getMe

nayun_bot

993104124:AAGn6gMcpzhwy83b3TNK5tFQz5ianyoGoHk

993104124

https://4d8b777b.ngrok.io

[https://api.telegram.org/bot993104124:AAGn6gMcpzhwy83b3TNK5tFQz5ianyoGoHk/sendMessage?chat_id=831071081&text=%EC%A0%90%EC%8B%AC%EB%8F%84%20%EC%82%AC%EB%A6%AC%20%EA%B3%B0%ED%83%95%EC%9D%B4%EC%95%BC]



(https://api.telegram.org/bot993104124:AAGn6gMcpzhwy83b3TNK5tFQz5ianyoGoHk/sendMessage?chat_id=831071081&text=점심도 사리 곰탕이야)



https://api.telegram.org/bot993104124:AAGn6gMcpzhwy83b3TNK5tFQz5ianyoGoHk/setWebhook?url=https://0ece1dd8.ngrok.io/993104124:AAGn6gMcpzhwy83b3TNK5tFQz5ianyoGoHk



https://0ece1dd8.ngrok.io









파이썬 애니웨어 서버 배포

/home/NayunKim/mysite/flask_app.py



파이썬 ANYWHERE

1. 사이트에서 회원가입 및 이메일 확인
2. 웹서버에서 웹->FLASK->python 3.7->완료
3. FILE 메뉴에서 flask_app.py에 코드 변경
4. FILE 메뉴에서 .env 파일 생성, 숨김처리 아이디 코드 복붙
5. bash 코드 찍는 콘솔에서 pip3 install python-decouple --user
6. anywhere 코드 포함해서 webhook 찍어주기











